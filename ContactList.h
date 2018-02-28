#pragma once
#include <vector>
#include <string>
#include "Contact.h"
#include "File.h"

class ContactList
{
	std::vector<Contact> contacts;
	int lastContactID;

	int findContact();
	int findContactID(std::string& textLine);
	int findUserID(std::string& textLine);
	std::string contactSerialization(int position, int currentUserID);
	bool contactDeserialization(std::string& textLine, int currentUserID);
	
public:
	int loadFile(File& file, int currentUserID);
	void saveFile(File& file, int currentUserID);
	void clearContacts();
	void addContact();
	void editContact();
	void removeContact();
	void displayAllContacts();
	void displayAllContactsWithName();
	void displayAllContactsWithSurname();
};

