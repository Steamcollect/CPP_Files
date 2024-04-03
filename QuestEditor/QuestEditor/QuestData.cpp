#include "pch.h"
#include "QuestData.h"

void QuestData::ResetInfos() {
	npcID = "";
	questTitle = "";

	objectiveType = "";
	objectivesQuantity = "";
	coinsGiven = "";
	xpGiven = "";

	preQuestDialog = "";
	inProgressDialog = "";
	postQuestDialog = "";

	isStarted = false;
	isAchieved = false;
}