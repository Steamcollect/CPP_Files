#include "FileData.h"

void FileData::WhriteInput(string input) {
	myFile.open("Tmp.txt", fstream::in | fstream::out | fstream::app);
	fstream fstream(path, ios_base::app);

	fstream << input << endl;
}

//void FileData::ReadInput(int size) {
//	string tmp;
//	for (size_t i = 0; i < size; i++)
//	{
//
//	}
//}