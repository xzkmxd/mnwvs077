#pragma once
#include "FieldObj.h"
#include <string>
#include <map>
#include <atomic>

class Npc;
class Field;
class ReactorTemplate;
class User;
class InPacket;

class Reactor : public FieldObj
{
	friend class ReactorPool;

	int m_nState = 0, 
		m_nOldState = 0,
		m_nHitCount = 0,
		m_nOwnerID = 0,
		m_nOwnType = 0,
		m_nOwnPartyID = 0,
		m_nLastHitCharacterID;

	unsigned int 
		m_tStateEnd = 0,
		m_tLastHit = 0,
		m_tTimeout = 0,
		m_tStateStart = 0;

	std::atomic<bool> m_bDestroyAfterEvent;
	bool m_bFlip = false, m_bRemove = false;

	Npc* m_pNpc;
	Field* m_pField;
	ReactorTemplate* m_pTemplate;
	std::string m_sReactorName;
	void *m_pReactorGen = nullptr;
	std::map<int, void*> m_mEvent;

	static int GetHitTypePriorityLevel(int nOption, int nType);
public:
	Reactor(ReactorTemplate* pTemplate, Field* pField);
	~Reactor();

	void MakeEnterFieldPacket(OutPacket *oPacket);
	void MakeLeaveFieldPacket(OutPacket *oPacket);

	int GetHitDelay(int nEventIdx);
	void OnHit(User *pUser, InPacket *iPacket);
	void SetState(int nEventIdx, int tActionDelay);
	void MakeStateChangePacket(OutPacket* oPacket, int tActionDelay, int nProperEventIdx);
	void FindAvailableAction();
	void DoAction(void* pInfo, unsigned int tDelay, int nDropIdx);
	void DoActionByUpdateEvent();
	void SetRemoved();
	void CancelAllEvent();
	void OnTime(int nEventSN);
	const std::string& GetReactorName() const;
};

