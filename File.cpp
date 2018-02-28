#include "File.h"


void File::saveLineToFile(std::string& textLine)
{
	setFileFormat();
	fileManagement << textLine;
}

void File::loadLineFromFile(std::string& textLine)
{
	std::getline(fileManagement, textLine);
}

bool File::isEndOfFile()
{
	return fileManagement.eof();
}

bool File::openFileForSaving(const std::string& fileName)
{
	fileManagement.open(fileName, std::ios::out);
	return isValid();
}

bool File::openFileForAdding(const std::string& fileName)
{
	fileManagement.open(fileName, std::ios::out | std::ios::app);
	return isValid();
}

bool File::openFileForReading(const std::string& fileName)
{
	fileManagement.open(fileName, std::ios::in);
	return isValid() && isNotEmpty();
}

void File::closeFile()
{
	fileManagement.close();
}

int File::getFileLength()
{
	fileManagement.seekg(0, std::ios::end);
	int length = fileManagement.tellg();

	return length;
}

bool File::isValid()
{
	if (fileManagement.good() == false)
	{
		return false;
	}
	return true;
}

bool File::isNotEmpty()
{
	return !( fileManagement.peek() == '/n' );
}

void File::setFileFormat()
{

	int length = getFileLength();

	if (length != 0)
		fileManagement << std::endl;
}



