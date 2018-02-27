#include "KsiazkaAdresowa.h"



KsiazkaAdresowa::KsiazkaAdresowa() : idZalogowanegoUzytkownika(0)
{
	ksiazkaUzytkownikow.wczytajZPliku(plik);
}

void KsiazkaAdresowa::zaloguj()
{
	system("cls");
	std::cin.sync();

	std::string nazwaPodana, hasloPodane;
	std::vector<Uzytkownik> uzytkownicy = ksiazkaUzytkownikow.getUzytkownicy();

	std::cout << "Podaj nazwe uzytkownika: ";
	std::cin >> nazwaPodana;

	for (int i = 0; i < uzytkownicy.size(); i++)
	{
		if (uzytkownicy[i].pobierzNazwa() == nazwaPodana)
		{
			std::cout << "Podaj haslo uzytkownika: ";
			std::cin >> hasloPodane;

			system("cls");
			std::cin.sync();

			if (uzytkownicy[i].pobierzHaslo() == hasloPodane)
			{
				idZalogowanegoUzytkownika = ++i;
				ksiazkaAdresatowZalogowanegoUzytkownika.wczytajZPliku(plik, idZalogowanegoUzytkownika);

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

void KsiazkaAdresowa::zarejestruj()
{
	std::string nazwaPodana, hasloPodane;
	int idUzytkownika;
	std::vector<Uzytkownik>& uzytkownicy = ksiazkaUzytkownikow.getUzytkownicy();

	if (uzytkownicy.size() == 0)
		idUzytkownika = 1;
	else
		idUzytkownika = uzytkownicy.back().pobierzID() + 1;

	system("cls");
	std::cin.sync();

	std::cout << "Podaj nazwe uzytkownika: ";
	std::cin >> nazwaPodana;
	std::cout << "Podaj haslo uzytkownika: ";
	std::cin >> hasloPodane;

	ksiazkaUzytkownikow.ustawUzytkownicy(idUzytkownika, nazwaPodana, hasloPodane);

	system("cls");
	std::cout << "Zarejestrowano" << std::endl;

	Sleep(1500);
	std::cin.sync();
}

void KsiazkaAdresowa::zmienHaslo()
{
	system("cls");
	std::cin.sync();

	std::string noweHaslo;
	std::vector<Uzytkownik>& uzytkownicy = ksiazkaUzytkownikow.getUzytkownicy();

	std::cout << "Podaj nowe haslo: ";
	std::cin >> noweHaslo;

	for (int i = 0; i < uzytkownicy.size(); i++)
	{
		if (uzytkownicy[i].pobierzID() == idZalogowanegoUzytkownika)
		{
			system("cls");
			std::cin.sync();

			uzytkownicy[i].ustawHaslo(noweHaslo);

			std::cout << "Haslo zmienione" << std::endl;
			Sleep(1500);
			std::cin.sync();
		}
	}
}

void KsiazkaAdresowa::wyjdz()
{
	ksiazkaUzytkownikow.zapiszDoPliku(plik);
	exit(0);
}

int KsiazkaAdresowa::pobierzIDZalogowanegoUzytkownika()
{
	return idZalogowanegoUzytkownika;
}

void KsiazkaAdresowa::wyswietlMenuGlowne()
{
	std::cout << "1. Logowanie" << std::endl;
	std::cout << "2. Rejestracja" << std::endl;
	std::cout << "3. Zamknij program" << std::endl;

	char wybor;
	std::cin >> wybor;

	switch (wybor)
	{
		case '1':
			zaloguj();
			break;
		case '2':
			zarejestruj();
			break;
		case '3':
			wyjdz();
		default:
			system("cls");
			std::cout << "Prosze podac poprawny numer" << std::endl;
			Sleep(1500);
	}
}

void KsiazkaAdresowa::wyswietlMenuUzytkownika()
{
	std::cout << "1. Dodaj adresata" << std::endl;
	std::cout << "2. Edytuj adresata" << std::endl;
	std::cout << "3. Usun adresata" << std::endl;
	std::cout << "4. Wyswietl wszystkich adresatow" << std::endl;
	std::cout << "5. Wyszukaj adresatow o imieniu" << std::endl;
	std::cout << "6. Wyszukaj adresatow o nazwisku" << std::endl;
	std::cout << "7. Zmien haslo" << std::endl;
	std::cout << "8. Wyloguj" << std::endl;

	char wybor;
	std::cin >> wybor;

	switch (wybor)
	{
		case '1':
			ksiazkaAdresatowZalogowanegoUzytkownika.dodajAdresata();
			break;
		case '2':
			ksiazkaAdresatowZalogowanegoUzytkownika.edytujAdresata();
			break;
		case '3':
			ksiazkaAdresatowZalogowanegoUzytkownika.usunAdresata();
			break;
		case '4':
			ksiazkaAdresatowZalogowanegoUzytkownika.wyswietlWszystkichAdresatow();
			break;
		case '5':
			ksiazkaAdresatowZalogowanegoUzytkownika.wyswietlAdresatowOImieniu();
			break;
		case '6':
			ksiazkaAdresatowZalogowanegoUzytkownika.wyswietlAdresatowONazwisku();
			break;
		case '7':
			zmienHaslo();
			break;
		case '8':
			wyloguj();
			break;
		default:
			system("cls");
			std::cout << "Prosze podac poprawny numer" << std::endl;
			Sleep(1500);
	}
}

void KsiazkaAdresowa::wyloguj()
{
	ksiazkaAdresatowZalogowanegoUzytkownika.zapiszDoPliku(plik, idZalogowanegoUzytkownika);
	idZalogowanegoUzytkownika = 0;
	ksiazkaAdresatowZalogowanegoUzytkownika.wyczyscAdresatow();

	system("cls");
	std::cout << "Wylogowano" << std::endl;
	Sleep(1500);
}
