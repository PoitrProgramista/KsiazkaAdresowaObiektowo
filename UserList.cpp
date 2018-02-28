#include "UserList.h"


void UserList::saveFile(File& file)
{
	if (file.openFileForSaving("Users.txt") == false)
	{
		file.closeFile();
		return;
	}

	std::string textLine;

	for (size_t i = 0; i < users.size(); i++)
	{
		textLine = userSerialization(i);
		file.saveLineToFile(textLine);
	}
	file.closeFile();
}

std::string UserList::userSerialization(int position)
{
	std::string textLine = std::to_string(users[position].getID()) + "|" + users[position].getName() + "|" + users[position].getPassword();

	return textLine;
}

void UserList::loadFile(File& file)
{
	if (file.openFileForReading("Users.txt") == false)
	{
		file.closeFile();
		return;
	}

	std::string textLine;

	while (file.isEndOfFile() == false)
	{
		file.loadLineFromFile(textLine);
		userDeserialization(textLine);
	}

	file.closeFile();
}

void UserList::userDeserialization(std::string& textLine)
{
	int iterator = 1;
	size_t dataLength = 0;
	int ID;
	std::string name, password;

	while (true)
	{
		dataLength = textLine.find("|");

		switch (iterator)
		{
			case 1:
				ID = std::stoi(textLine.substr(0, dataLength));
				break;
			case 2:
				name = textLine.substr(0, dataLength);
				break;
			case 3:
				password = textLine.substr(0, dataLength);

				textLine.clear();
				users.emplace_back(ID, name, password);

				return;
		}
		textLine.erase(0, dataLength + 1);
		iterator++;
	}
}

std::vector<User>& UserList::getUsers()
{
	return users;
}

void UserList::setUsers(int ID, std::string& name, std::string& password)
{
	users.emplace_back(ID, name, password);
}

