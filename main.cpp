#include <iostream>
#include "KsiazkaAdresowa.h"


int main()
{
	KsiazkaAdresowa ksiazkaAdresowa;

	while (true)
	{
		system("cls");
		std::cin.sync();

		if (ksiazkaAdresowa.pobierzIDZalogowanegoUzytkownika() == 0)
			ksiazkaAdresowa.wyswietlMenuGlowne();
		else
			ksiazkaAdresowa.wyswietlMenuUzytkownika();
	}
}
