#pragma once
#include <iostream>
#include <Windows.h>
#include "User.h"
#include "UserList.h"
#include "ContactList.h"
#include "File.h"

class ContactBook
{
	File file;
	int currentUserID;
	UserList userList;
	ContactList currentUserContactList;

	void logIn();
	void LogOut();
	void signIn();
	void changePassword();
	void quit();

public:
	ContactBook();
	int getCurrentUserID();
	void displayMainMenu();
	void displayUserMenu();
};
