#pragma once
#include <string>

using namespace std;

class QuestData
{
public:
	enum QuestState
	{
		NotStarted,
		Started,
		Finished
	};

	enum ObjectiveType {
		Slay,
		Loot,
		Save
	};

	//Main infos
	int questID, npcID;
	string questTitle;

	// Objectives infos
	ObjectiveType objectiveType;
	int objectivesQuantity;
	int coinsGiven, xpGiven;

	//Dialog infos
	string preQuestDialog, inProgressDialog, postQuestDialog;

	QuestState questState;

	// Functions
	void ResetInfos();
};