#include <iostream>
#include "ContactBook.h"


int main()
{
	ContactBook contactBook;

	while (true)
	{
		system("cls");
		std::cin.sync();

		if (contactBook.getCurrentUserID() == 0)
			contactBook.displayMainMenu();
		else
			contactBook.displayUserMenu();
	}
}
