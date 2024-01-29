#pragma once
#include <iostream>
#include <string>
#include <list>
#include "FileData.h"

using namespace std;

class InputManager
{
	FileData fileData;
	list<string>* inputRegister;

public:

	// Constructor and destructor
	InputManager();
	~InputManager();

	// Functions and methods
	void GetUserInput();
	void DisplayAllInput();
};