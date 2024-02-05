#include "InputManager.h"

void InputManager::GetUserInput() {
	string tmpInput;
	cin >> tmpInput;

	fileData.WhriteInput(tmpInput);
	DisplayAllInput();
	GetUserInput();
}

void InputManager::DisplayAllInput() {
	system("cls");
	fileData.ResetFileCursor();
	vector<string> inputs = fileData.ReadInput();

	for (int i = 0; i < inputs.size(); i++)
	{
		cout << inputs[i] << endl;
	}
}

InputManager::InputManager()
{
	// Not implemented
}

InputManager::~InputManager()
{
	// Not implemented
}