#include "pch.h"
#include "QuestData.h"

void QuestData::ResetInfos() {
	npcID = 0;
	questTitle = "";
	
	//objectiveType = QuestData::ObjectiveType::Loot;
	objectivesQuantity = 0;
	coinsGiven = 0;
	xpGiven = 0;

	preQuestDialog = "";
	inProgressDialog = "";
	postQuestDialog = "";
}