#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <windows.h>

class File
{
	std::fstream fileManagement;

	bool isValid();
	bool isNotEmpty();
	void setFileFormat();
	int getFileLength();

public:
	bool isEndOfFile();
	bool openFileForSaving(const std::string& fileName);
	bool openFileForAdding(const std::string& fileName);
	bool openFileForReading(const std::string& fileName);
	void saveLineToFile(std::string& textLine);
	void loadLineFromFile(std::string& textLine);
	void closeFile();
};

