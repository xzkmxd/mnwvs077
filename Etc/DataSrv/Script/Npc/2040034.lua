require "./DataSrv/Script/sysDef"

fieldSet = FieldSet.get("Party2")
if(fieldSet) then
    ret = fieldSet->enter(userID)
   if (ret == 1) then
        self->say("要挑戰玩具城101組隊任務，單靠自己一個人是不可能的，所以請先加入隊伍後再與我談話。")
    elseif (ret == 2) then
        self->say("請隊長與我談話。")
    elseif (ret == 3 or ret == 4) then
        self->say("欲進行玩具城101組隊任務，您的隊伍人數至少#r5人#k，等級界於#r36至50級#k之間，並且由隊長與我交談！")
    elseif (ret == 5) then
        self->say("已經有隊伍目前正在挑戰組隊任務，請更換頻道或�芚市搘縝b進行的隊伍結束。")
    end
end