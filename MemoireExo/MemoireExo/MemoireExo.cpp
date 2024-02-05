#include <iostream>
#include <list>

#include "InputManager.h"

using namespace std;

int main()
{
	InputManager getinputSC;
	FileData fileData;

	fileData.ClearFile();

	getinputSC.GetUserInput();
}