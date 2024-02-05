#include "FileData.h"

void FileData::WhriteInput(string input) {
	myFile.open("Tmp.txt", fstream::in | fstream::out | fstream::app);
	fstream fstream(path, ios_base::app);

	fstream << input << endl;
}

vector<string> FileData::ReadInput() {
	vector<string> allInput;
	string current;

	if (myFile.is_open()) {
		while (myFile) {
			getline(myFile, current);
			allInput.emplace_back(current);
		}
	}

	myFile.close();
	return allInput;
}

void FileData::ClearFile() {
	myFile.open("Tmp.txt", ofstream::out | ofstream::trunc);
	myFile.close();
}
void FileData::ResetFileCursor() {
	myFile.clear();
	myFile.seekg(0, ios::beg);
}