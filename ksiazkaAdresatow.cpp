#include "KsiazkaAdresatow.h"


void KsiazkaAdresatow::zapiszDoPliku(Plik& plik, int idZalogowanegoUzytkownika)
{
	if (plik.otworzPlikDoDopisania("Adresaci_temp.txt") == false)
	{
		plik.zamknijPlik();
		return;
	}

	std::string linijkaAdresata;

	for (size_t i = 0; i < adresaci.size(); i++)
	{
		linijkaAdresata = serializacjaAdresata(i, idZalogowanegoUzytkownika);
		plik.zapiszLinijkeDoPliku(linijkaAdresata);
	}
	plik.zamknijPlik();

	remove("Adresaci.txt");
	rename("Adresaci_temp.txt", "Adresaci.txt");
}

std::string KsiazkaAdresatow::serializacjaAdresata(int pozycja, int idZalogowanegoUzytkownika)
{
	std::string linijkaAdresata = std::to_string(adresaci[pozycja].getID()) + "|" + std::to_string(idZalogowanegoUzytkownika) + "|" + adresaci[pozycja].getImie() + "|" + adresaci[pozycja].getNazwisko() + "|" + adresaci[pozycja].getTelefon() + "|" + adresaci[pozycja].getEmail() + "|" + adresaci[pozycja].getAdres();

	return linijkaAdresata;
}

int KsiazkaAdresatow::wczytajZPliku(Plik& plik, int idZalogowanegoUzytkownika)
{
	idOstatniegoAdresata = 0;
	Plik temp;
	temp.otworzPlikDoZapisu("Adresaci_temp.txt");

	if (plik.otworzPlikDoOdczytu("Adresaci.txt") == false)
	{
		plik.zamknijPlik();
		return 0;
	}

	std::string linijkaAdresata;

	while (plik.czyKoniecPliku() == false)
	{
		plik.wczytajLinijkeZPliku(linijkaAdresata);
		idOstatniegoAdresata = znajdzIdAdresata(linijkaAdresata);
		bool adresatZalogowanegoUzytkownika = deserializacjaAdresata(linijkaAdresata, idZalogowanegoUzytkownika);

		if (adresatZalogowanegoUzytkownika == false)
			temp.zapiszLinijkeDoPliku(linijkaAdresata);
	}
	temp.zamknijPlik();
	plik.zamknijPlik();

	return idOstatniegoAdresata;
}

bool KsiazkaAdresatow::deserializacjaAdresata(std::string& linijkaAdresata,
											  int idZalogowanegoUzytkownika)
{
	int iterator = 1;
	size_t dlugoscParametru = 0;
	int idAdresata;
	std::string imie, nazwisko, telefon, email, adres;

	int idUzytkownika = znajdzIdUzytkownika(linijkaAdresata);

	if (idUzytkownika == idZalogowanegoUzytkownika)
	{
		while (true)
		{
			dlugoscParametru = linijkaAdresata.find("|");

			switch (iterator)
			{
				case 1:
					idAdresata = std::stoi(linijkaAdresata.substr(0, dlugoscParametru));
					break;
				case 2:
					linijkaAdresata.erase(0, linijkaAdresata.find("|") + 1);
					imie = linijkaAdresata.substr(0, linijkaAdresata.find("|"));
					break;
				case 3:
					nazwisko = linijkaAdresata.substr(0, dlugoscParametru);
					break;
				case 4:
					telefon = linijkaAdresata.substr(0, dlugoscParametru);
					break;
				case 5:
					email = linijkaAdresata.substr(0, dlugoscParametru);
					break;
				case 6:
					adres = linijkaAdresata.substr(0, dlugoscParametru);

					linijkaAdresata.clear();
					adresaci.emplace_back(idAdresata, imie, nazwisko,
										  telefon, email, adres);
					return true;
			}
			linijkaAdresata.erase(0, linijkaAdresata.find("|") + 1);
			iterator++;
		}
	}
	else
	{
		return false;
	}
}

int KsiazkaAdresatow::znajdzIdUzytkownika(std::string& linijkaAdresata)
{
	int poczatekIdUzytkownika = linijkaAdresata.find("|") + 1;
	int koniecIdUzytkownika = linijkaAdresata.find("|", poczatekIdUzytkownika);
	int idUzytkownika = std::stoi(linijkaAdresata.substr(poczatekIdUzytkownika, koniecIdUzytkownika - poczatekIdUzytkownika));

	return idUzytkownika;
}

int KsiazkaAdresatow::znajdzIdAdresata(std::string& linijkaAdresata)
{
	int idAdresata = std::stoi(linijkaAdresata.substr(0, linijkaAdresata.find("|")));

	return idAdresata;
}

void KsiazkaAdresatow::wyczyscAdresatow()
{
	adresaci.clear();
}

void KsiazkaAdresatow::dodajAdresata()
{
	system("cls");

	int id;
	std::string imie, nazwisko, telefon, email, adres;

	std::cin.sync();
	std::cout << "Podaj imie:" << std::endl;
	std::cin >> imie;
	std::cout << std::endl << "Podaj nazwisko:" << std::endl;
	std::cin >> nazwisko;
	std::cout << std::endl << "Podaj telefon:" << std::endl;
	std::cin.ignore();
	std::getline(std::cin, telefon);
	std::cout << std::endl << "Podaj email:" << std::endl;
	std::cin >> email;
	std::cout << std::endl << "Podaj adres:" << std::endl;
	std::cin.ignore();
	std::getline(std::cin, adres);

	++idOstatniegoAdresata;
	id = idOstatniegoAdresata;

	adresaci.emplace_back(id, imie, nazwisko, telefon, email, adres);
}

void KsiazkaAdresatow::edytujAdresata()
{
	int pozycja = znajdzAdresata();

	if (pozycja == -1)
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

		char wybor;
		std::cin >> wybor;

		if (wybor == '6')
			return;

		system("cls");

		std::string dane;
		std::cout << "Podaj dane: ";

		std::cin.ignore();
		std::getline(std::cin, dane);

		switch (wybor)
		{
			case '1':
				adresaci[pozycja].setImie(dane);
				return;
			case '2':
				adresaci[pozycja].setNazwisko(dane);
				return;
			case '3':
				adresaci[pozycja].setTelefon(dane);
				return;
			case '4':
				adresaci[pozycja].setEmail(dane);
				return;
			case '5':
				adresaci[pozycja].setAdres(dane);
				return;
			default:
				system("cls");
				std::cout << "Prosze podac poprawny numer" << std::endl;

				Sleep(1500);
				std::cin.sync();
		}
	}
}

int KsiazkaAdresatow::znajdzAdresata()
{
	system("cls");

	std::cin.sync();
	std::cout << "Podaj ID kontaktu: ";

	int id = 0;
	std::cin >> id;

	for (size_t i = 0; i < adresaci.size(); i++)
	{
		if (adresaci[i].getID() == id)
		{
			return i;
		}
	}
	return -1;
}

void KsiazkaAdresatow::usunAdresata()
{
	int pozycja = znajdzAdresata();

	if (pozycja == -1)
	{
		system("cls");
		std::cout << std::endl << "Brak kontaktu o podanym ID" << std::endl;
		Sleep(1500);
		return;
	}
	
	adresaci.erase(adresaci.begin() + pozycja);

	system("cls");
	std::cout << std::endl << "Usunieto" << std::endl;
	Sleep(1500);
}

void KsiazkaAdresatow::wyswietlWszystkichAdresatow()
{
	system("cls");
	bool czySaKontakty = false;
	for (size_t i = 0; i < adresaci.size(); i++)
	{
		adresaci[i].wyswietlAdresata();
		czySaKontakty = true;
	}
	if (czySaKontakty == 0)
		std::cout << std::endl << "Brak kontaktow do wyswietlenia" << std::endl;

	std::cout << std::endl << "Wcisnij przycisk aby wrocic do menu glownego" << std::endl;

	std::cin.ignore();
	std::cin.get();
}

void KsiazkaAdresatow::wyswietlAdresatowOImieniu()
{
	system("cls");

	bool czySaKontakty = false;
	std::string imie;

	std::cout << "Podaj imie: " << std::endl;
	std::cin >> imie;

	system("cls");

	for (size_t i = 0; i < adresaci.size(); i++)
	{
		if (adresaci[i].getImie() == imie)
		{
			adresaci[i].wyswietlAdresata();
			czySaKontakty = true;
		}
	}
	if (czySaKontakty == false)
		std::cout << std::endl << "Brak kontaktow o podanym imieniu" << std::endl;

	std::cout << std::endl << "Wcisnij przycisk aby wrocic do menu glownego" << std::endl;

	std::cin.ignore();
	std::cin.get();
}

void KsiazkaAdresatow::wyswietlAdresatowONazwisku()
{
	system("cls");

	bool czySaKontakty = false;
	std::string nazwisko;

	std::cout << "Podaj nazwisko: " << std::endl;
	std::cin >> nazwisko;

	system("cls");

	for (size_t i = 0; i < adresaci.size(); i++)
	{
		if (adresaci[i].getNazwisko() == nazwisko)
		{
			adresaci[i].wyswietlAdresata();
			czySaKontakty = true;
		}
	}
	if (czySaKontakty == false)
		std::cout << std::endl << "Brak kontaktow o podanym nazwisku" << std::endl;

	std::cout << std::endl << "Wcisnij przycisk aby wrocic do menu glownego" << std::endl;

	std::cin.ignore();
	std::cin.get();
}
