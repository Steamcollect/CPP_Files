#include "InputManager.h"

void InputManager::GetUserInput() {
	string tmpInput;
	cin >> tmpInput;

	inputRegister->push_back(tmpInput);
}

void InputManager::DisplayAllInput() {
	system("cls");

	for (auto n = inputRegister->begin(); n != inputRegister->end(); ++n) {
		cout << *n;
	}
}

InputManager::InputManager()
{
	inputRegister = new list<string>;
}

InputManager::~InputManager()
{
	delete inputRegister;
	inputRegister = nullptr;
}