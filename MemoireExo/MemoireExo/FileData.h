#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class FileData
{
	fstream myFile;
	string path = "C:\\Users\\e_garnier4\\Documents\\GitHub\\CPP_Files\\MemoireExo\\MemoireExo\\Tmp.txt";

public:
	void WhriteInput(string input);
	vector<string> ReadInput();
	void ClearFile();
	void ResetFileCursor();
};