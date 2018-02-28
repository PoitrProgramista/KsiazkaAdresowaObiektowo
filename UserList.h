#pragma once
#include <vector>
#include <string>
#include "User.h"
#include "File.h"

class UserList
{
	std::vector<User> users;

	std::string userSerialization(int position);
	void userDeserialization(std::string& textLine);

public:
	std::vector<User>& getUsers();
	void setUsers(int ID, std::string& name, std::string& password);
	void saveFile(File& file);
	void loadFile(File& file);
};

