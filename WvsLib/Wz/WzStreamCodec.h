#pragma once
#include <string>

class WzMappedFileStream;
class WzArchive;

class WzStreamCodec
{
	unsigned char 
		aWzKey[2][0x10000],
		aWideWzKey[2][0x10000],
		aKeyStore[2][0x10000];

	void GenKey(unsigned char* aKey, unsigned char *aResult);

public:
	WzStreamCodec();
	~WzStreamCodec();
	void Init();
	std::string DecodeString(WzMappedFileStream *pStream);
	std::string DecodePropString(WzMappedFileStream *pStream, unsigned int uRootPropPos);
};

