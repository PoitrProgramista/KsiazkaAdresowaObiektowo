#include "KsiazkaUzytkownikow.h"


void KsiazkaUzytkownikow::zapiszDoPliku(Plik& plik)
{
	if (plik.otworzPlikDoZapisu("Uzytkownicy.txt") == false)
	{
		plik.zamknijPlik();
		return;
	}

	std::string linijkaUzytkownika;

	for (size_t i = 0; i < uzytkownicy.size(); i++)
	{
		linijkaUzytkownika = serializacjaUzytkownika(i);
		plik.zapiszLinijkeDoPliku(linijkaUzytkownika);
	}
	plik.zamknijPlik();
}

std::string KsiazkaUzytkownikow::serializacjaUzytkownika(int pozycja)
{
	std::string linijkauzytkownika = std::to_string(uzytkownicy[pozycja].pobierzID()) + "|" + uzytkownicy[pozycja].pobierzNazwa() + "|" + uzytkownicy[pozycja].pobierzHaslo();

	return linijkauzytkownika;
}

void KsiazkaUzytkownikow::wczytajZPliku(Plik& plik)
{
	if (plik.otworzPlikDoOdczytu("Uzytkownicy.txt") == false)
	{
		plik.zamknijPlik();
		return;
	}

	std::string linijkaUzytkownika;

	while (plik.czyKoniecPliku() == false)
	{
		plik.wczytajLinijkeZPliku(linijkaUzytkownika);
		deserializacjaUzytkownika(linijkaUzytkownika);
	}

	plik.zamknijPlik();
}

void KsiazkaUzytkownikow::deserializacjaUzytkownika(std::string& linijkaUzytkownika)
{
	int iterator = 1;
	size_t dlugoscParametru = 0;
	int id;
	std::string nazwa, haslo;

	while (true)
	{
		dlugoscParametru = linijkaUzytkownika.find("|");

		switch (iterator)
		{
			case 1:
				id = std::stoi(linijkaUzytkownika.substr(0, dlugoscParametru));
				break;
			case 2:
				nazwa = linijkaUzytkownika.substr(0, dlugoscParametru);
				break;
			case 3:
				haslo = linijkaUzytkownika.substr(0, dlugoscParametru);

				linijkaUzytkownika.clear();
				uzytkownicy.emplace_back(id, nazwa, haslo);

				return;
		}
		linijkaUzytkownika.erase(0, dlugoscParametru + 1);
		iterator++;
	}
}

std::vector<Uzytkownik>& KsiazkaUzytkownikow::getUzytkownicy()
{
	return uzytkownicy;
}

void KsiazkaUzytkownikow::ustawUzytkownicy(int id, std::string& nazwa, std::string& haslo)
{
	uzytkownicy.emplace_back(id, nazwa, haslo);
}

