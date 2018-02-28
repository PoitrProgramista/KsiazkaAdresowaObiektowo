#pragma once
#include <string>
#include <iostream>

class Contact
{
	int ID;
	std::string name, surname, phoneNumber, email, address;

public:
	Contact(int ID, std::string& name, std::string& surname, std::string& phoneNumber,
			std::string& email, std::string& address);
	void displayContact();
	void setName(std::string& name);
	void setSurname(std::string& surname);
	void setPhoneNumber(std::string& phoneNumber);
	void setEmail(std::string& email);
	void setAddress(std::string& address);
	int getID();
	std::string getName();
	std::string getSurname();
	std::string getPhoneNumber();
	std::string getEmail();
	std::string getAddress();

};
