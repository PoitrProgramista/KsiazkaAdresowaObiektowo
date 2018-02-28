#include "ContactBook.h"


ContactBook::ContactBook() : currentUserID(0)
{
	userList.loadFile(file);
}

void ContactBook::logIn()
{
	system("cls");
	std::cin.sync();

	std::string givenName, givenPassword;
	std::vector<User> users = userList.getUsers();

	std::cout << "Podaj nazwe uzytkownika: ";
	std::cin >> givenName;

	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].getName() == givenName)
		{
			std::cout << "Podaj haslo uzytkownika: ";
			std::cin >> givenPassword;

			system("cls");
			std::cin.sync();

			if (users[i].getPassword() == givenPassword)
			{
				currentUserID = ++i;
				currentUserContactList.loadFile(file, currentUserID);

				std::cout << "Zalogowano" << std::endl;
				Sleep(1500);
				return;
			}
			else
			{
				std::cout << "Bledne haslo" << std::endl;
				Sleep(1500);
				return;
			}
		}
	}
	system("cls");
	std::cin.sync();

	std::cout << "Brak uzytkownika o podanej nazwie" << std::endl;
	Sleep(1500);
}

void ContactBook::signIn()
{
	std::string givenName, givenPassword;
	int userID;
	std::vector<User>& users = userList.getUsers();

	if (users.size() == 0)
		userID = 1;
	else
		userID = users.back().getID() + 1;

	system("cls");
	std::cin.sync();

	std::cout << "Podaj nazwe uzytkownika: ";
	std::cin >> givenName;
	std::cout << "Podaj haslo uzytkownika: ";
	std::cin >> givenPassword;

	userList.setUsers(userID, givenName, givenPassword);

	system("cls");
	std::cout << "Zarejestrowano" << std::endl;

	Sleep(1500);
	std::cin.sync();
}

void ContactBook::changePassword()
{
	system("cls");
	std::cin.sync();

	std::string newPassword;
	std::vector<User>& users = userList.getUsers();

	std::cout << "Podaj nowe haslo: ";
	std::cin >> newPassword;

	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].getID() == currentUserID)
		{
			system("cls");
			std::cin.sync();

			users[i].setPassword(newPassword);

			std::cout << "Haslo zmienione" << std::endl;
			Sleep(1500);
			std::cin.sync();
		}
	}
}

void ContactBook::quit()
{
	userList.saveFile(file);
	exit(0);
}

int ContactBook::getCurrentUserID()
{
	return currentUserID;
}

void ContactBook::displayMainMenu()
{
	std::cout << "1. Logowanie" << std::endl;
	std::cout << "2. Rejestracja" << std::endl;
	std::cout << "3. Zamknij program" << std::endl;

	char option;
	std::cin >> option;

	switch (option)
	{
		case '1':
			logIn();
			break;
		case '2':
			signIn();
			break;
		case '3':
			quit();
		default:
			system("cls");
			std::cout << "Prosze podac poprawny numer" << std::endl;
			Sleep(1500);
	}
}

void ContactBook::displayUserMenu()
{
	std::cout << "1. Dodaj adresata" << std::endl;
	std::cout << "2. Edytuj adresata" << std::endl;
	std::cout << "3. Usun adresata" << std::endl;
	std::cout << "4. Wyswietl wszystkich adresatow" << std::endl;
	std::cout << "5. Wyszukaj adresatow o imieniu" << std::endl;
	std::cout << "6. Wyszukaj adresatow o nazwisku" << std::endl;
	std::cout << "7. Zmien haslo" << std::endl;
	std::cout << "8. Wyloguj" << std::endl;

	char option;
	std::cin >> option;

	switch (option)
	{
		case '1':
			currentUserContactList.addContact();
			break;
		case '2':
			currentUserContactList.editContact();
			break;
		case '3':
			currentUserContactList.removeContact();
			break;
		case '4':
			currentUserContactList.displayAllContacts();
			break;
		case '5':
			currentUserContactList.displayAllContactsWithName();
			break;
		case '6':
			currentUserContactList.displayAllContactsWithSurname();
			break;
		case '7':
			changePassword();
			break;
		case '8':
			LogOut();
			break;
		default:
			system("cls");
			std::cout << "Prosze podac poprawny numer" << std::endl;
			Sleep(1500);
	}
}

void ContactBook::LogOut()
{
	currentUserContactList.saveFile(file, currentUserID);
	currentUserID = 0;
	currentUserContactList.clearContacts();

	system("cls");
	std::cout << "Wylogowano" << std::endl;
	Sleep(1500);
}
