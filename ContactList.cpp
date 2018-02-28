#include "ContactList.h"


void ContactList::saveFile(File& file, int currentUserID)
{
	if (file.openFileForAdding("Contacts_temp.txt") == false)
	{
		file.closeFile();
		return;
	}

	std::string textLine;

	for (size_t i = 0; i < contacts.size(); i++)
	{
		textLine = contactSerialization(i, currentUserID);
		file.saveLineToFile(textLine);
	}
	file.closeFile();

	remove("Contacts.txt");
	rename("Contacts_temp.txt", "Contacts.txt");
}

std::string ContactList::contactSerialization(int position, int currentUserID)
{
	std::string textLine = std::to_string(contacts[position].getID()) + "|" + std::to_string(currentUserID) + "|" + contacts[position].getName() + "|" + contacts[position].getSurname() + "|" + contacts[position].getPhoneNumber() + "|" + contacts[position].getEmail() + "|" + contacts[position].getAddress();

	return textLine;
}

int ContactList::loadFile(File& file, int currentUserID)
{
	lastContactID = 0;
	File tempFile;
	tempFile.openFileForSaving("Contacts_temp.txt");

	if (file.openFileForReading("Contacts.txt") == false)
	{
		file.closeFile();
		return 0;
	}

	std::string textLine;

	while (file.isEndOfFile() == false)
	{
		file.loadLineFromFile(textLine);
		int currentContactID = findContactID(textLine);

		if (currentContactID >= lastContactID)
			lastContactID = currentContactID;

		bool isContactOfCurrentUser = contactDeserialization(textLine, currentUserID);

		if (isContactOfCurrentUser == false)
			tempFile.saveLineToFile(textLine);
	}
	tempFile.closeFile();
	file.closeFile();

	return lastContactID;
}

bool ContactList::contactDeserialization(std::string& textLine,
											  int currentUserID)
{
	int iterator = 1;
	size_t dataLength = 0;
	int contactID;
	std::string name, surname, phoneNumber, email, address;

	int UserID = findUserID(textLine);

	if (UserID == currentUserID)
	{
		while (true)
		{
			dataLength = textLine.find("|");

			switch (iterator)
			{
				case 1:
					contactID = std::stoi(textLine.substr(0, dataLength));
					break;
				case 2:
					textLine.erase(0, textLine.find("|") + 1);
					name = textLine.substr(0, textLine.find("|"));
					break;
				case 3:
					surname = textLine.substr(0, dataLength);
					break;
				case 4:
					phoneNumber = textLine.substr(0, dataLength);
					break;
				case 5:
					email = textLine.substr(0, dataLength);
					break;
				case 6:
					address = textLine.substr(0, dataLength);

					textLine.clear();
					contacts.emplace_back(contactID, name, surname,
										  phoneNumber, email, address);
					return true;
			}
			textLine.erase(0, textLine.find("|") + 1);
			iterator++;
		}
	}
	else
	{
		return false;
	}
}

int ContactList::findUserID(std::string& textLine)
{
	int UserIDBegin = textLine.find("|") + 1;
	int UserIDEnd = textLine.find("|", UserIDBegin);
	int UserID = std::stoi(textLine.substr(UserIDBegin, UserIDEnd - UserIDBegin));

	return UserID;
}

int ContactList::findContactID(std::string& textLine)
{
	int ContactID = std::stoi(textLine.substr(0, textLine.find("|")));

	return ContactID;
}

void ContactList::clearContacts()
{
	contacts.clear();
}

void ContactList::addContact()
{
	system("cls");

	int ID;
	std::string name, surname, phoneNumber, email, address;

	std::cin.sync();
	std::cout << "Podaj imie:" << std::endl;
	std::cin >> name;
	std::cout << std::endl << "Podaj nazwisko:" << std::endl;
	std::cin >> surname;
	std::cout << std::endl << "Podaj telefon:" << std::endl;
	std::cin.ignore();
	std::getline(std::cin, phoneNumber);
	std::cout << std::endl << "Podaj email:" << std::endl;
	std::cin >> email;
	std::cout << std::endl << "Podaj adres:" << std::endl;
	std::cin.ignore();
	std::getline(std::cin, address);

	++lastContactID;
	ID = lastContactID;

	contacts.emplace_back(ID, name, surname, phoneNumber, email, address);
}

void ContactList::editContact()
{
	int position = findContact();

	if (position == -1)
	{
		system("cls");
		std::cout << std::endl << "Brak kontaktu o podanym ID" << std::endl;
		Sleep(1500);
		return;
	}

	while (true)
	{
		system("cls");

		std::cout << "Wybierz dane do edycji: " << std::endl;
		std::cout << "1. Imie" << std::endl;
		std::cout << "2. Nazwisko" << std::endl;
		std::cout << "3. Telefon" << std::endl;
		std::cout << "4. Email" << std::endl;
		std::cout << "5. Adres" << std::endl;
		std::cout << "6. Powrot" << std::endl;

		char option;
		std::cin >> option;

		if (option == '6')
			return;

		system("cls");

		std::string data;
		std::cout << "Podaj dane: ";

		std::cin.ignore();
		std::getline(std::cin, data);

		switch (option)
		{
			case '1':
				contacts[position].setName(data);
				return;
			case '2':
				contacts[position].setSurname(data);
				return;
			case '3':
				contacts[position].setPhoneNumber(data);
				return;
			case '4':
				contacts[position].setEmail(data);
				return;
			case '5':
				contacts[position].setAddress(data);
				return;
			default:
				system("cls");
				std::cout << "Prosze podac poprawny numer" << std::endl;

				Sleep(1500);
				std::cin.sync();
		}
	}
}

int ContactList::findContact()
{
	system("cls");

	std::cin.sync();
	std::cout << "Podaj ID kontaktu: ";

	int ID = 0;
	std::cin >> ID;

	for (size_t i = 0; i < contacts.size(); i++)
	{
		if (contacts[i].getID() == ID)
		{
			return i;
		}
	}
	return -1;
}

void ContactList::removeContact()
{
	int position = findContact();

	if (position == -1)
	{
		system("cls");
		std::cout << std::endl << "Brak kontaktu o podanym ID" << std::endl;
		Sleep(1500);
		return;
	}

	contacts.erase(contacts.begin() + position);

	system("cls");
	std::cout << std::endl << "Usunieto" << std::endl;
	Sleep(1500);
}

void ContactList::displayAllContacts()
{
	system("cls");
	bool anyContacts = false;
	for (size_t i = 0; i < contacts.size(); i++)
	{
		contacts[i].displayContact();
		anyContacts = true;
	}
	if (anyContacts == 0)
		std::cout << std::endl << "Brak kontaktow do wyswietlenia" << std::endl;

	std::cout << std::endl << "Wcisnij przycisk aby wrocic do menu glownego" << std::endl;

	std::cin.ignore();
	std::cin.get();
}

void ContactList::displayAllContactsWithName()
{
	system("cls");

	bool anyContacts = false;
	std::string name;

	std::cout << "Podaj imie: " << std::endl;
	std::cin >> name;

	system("cls");

	for (size_t i = 0; i < contacts.size(); i++)
	{
		if (contacts[i].getName() == name)
		{
			contacts[i].displayContact();
			anyContacts = true;
		}
	}
	if (anyContacts == false)
		std::cout << std::endl << "Brak kontaktow o podanym imieniu" << std::endl;

	std::cout << std::endl << "Wcisnij przycisk aby wrocic do menu glownego" << std::endl;

	std::cin.ignore();
	std::cin.get();
}

void ContactList::displayAllContactsWithSurname()
{
	system("cls");

	bool anyContacts = false;
	std::string surname;

	std::cout << "Podaj nazwisko: " << std::endl;
	std::cin >> surname;

	system("cls");

	for (size_t i = 0; i < contacts.size(); i++)
	{
		if (contacts[i].getSurname() == surname)
		{
			contacts[i].displayContact();
			anyContacts = true;
		}
	}
	if (anyContacts == false)
		std::cout << std::endl << "Brak kontaktow o podanym nazwisku" << std::endl;

	std::cout << std::endl << "Wcisnij przycisk aby wrocic do menu glownego" << std::endl;

	std::cin.ignore();
	std::cin.get();
}
