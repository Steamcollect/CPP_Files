#pragma once
#include <string>
#include <fstream>

using namespace std;

class FileData
{
	ofstream myFile;
	string path = "C:\\Users\\e_garnier4\\Documents\\GitHub\\CPP_Files\\MemoireExo\\MemoireExo\\Tmp.txt";

public:
	void WhriteInput(string input);
	void ReadInput();
};