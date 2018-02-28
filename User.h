#pragma once
#include <string>

class User
{
	int ID;
	std::string name, password;

public:
	User(int ID, std::string& name, std::string& password);
	int getID();
	std::string& getPassword();
	std::string& getName();
	void setPassword(std::string& givenPassword);
};

