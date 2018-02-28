#include "Contact.h"


Contact::Contact(int ID, std::string& name, std::string& surname, std::string& phoneNumber,
				 std::string& email, std::string& address)
	: ID(ID), name(name), surname(surname), phoneNumber(phoneNumber), email(email), address(address)
{
}

void Contact::displayContact()
{
	std::cout << ID << std::endl << name << " " << surname << std::endl << phoneNumber << std::endl << email << std::endl << address << std::endl << std::endl;;
}

int Contact::getID()
{
	return ID;
}

void Contact::setName(std::string& name)
{
	this->name = name;
}

std::string Contact::getName()
{
	return name;
}

void Contact::setSurname(std::string& surname)
{
	this->surname = surname;
}

std::string Contact::getSurname()
{
	return surname;
}

void Contact::setPhoneNumber(std::string& phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

std::string Contact::getPhoneNumber()
{
	return phoneNumber;
}

void Contact::setEmail(std::string& email)
{
	this->email = email;
}

std::string Contact::getEmail()
{
	return email;
}

void Contact::setAddress(std::string& address)
{
	this->address = address;
}

std::string Contact::getAddress()
{
	return address;
}
