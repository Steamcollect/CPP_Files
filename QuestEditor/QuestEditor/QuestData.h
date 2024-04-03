#pragma once
#include <string>

using namespace std;

class QuestData
{
public:
	//Main infos
	string questID, npcID;
	string questTitle;

	// Objectives infos
	string objectiveType, objectivesQuantity;
	string coinsGiven, xpGiven;

	//Dialog infos
	string preQuestDialog, inProgressDialog, postQuestDialog;
	bool isStarted, isAchieved;

	void ResetInfos();
};