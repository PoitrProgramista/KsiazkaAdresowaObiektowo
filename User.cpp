#include "User.h"


User::User(int ID, std::string& name, std::string& password)
	: ID(ID), name(name), password(password)
{
}

int User::getID()
{
	return ID;
}

void User::setPassword(std::string& password)
{
	password = password;
}

std::string& User::getPassword()
{
	return password;
}

std::string& User::getName()
{
	return name;
}
