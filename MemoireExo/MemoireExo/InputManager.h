#pragma once
#include <iostream>
#include <string>
#include <list>

using namespace std;

class InputManager
{
	list<string>* inputRegister;

public:
	// Constructor and destructor
	InputManager();
	~InputManager();

	// Functions and methods
	void GetUserInput();
	void DisplayAllInput();
};