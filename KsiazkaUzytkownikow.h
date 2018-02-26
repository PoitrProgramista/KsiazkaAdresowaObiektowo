#pragma once
#include <vector>
#include <string>
#include "Uzytkownik.h"
#include "Plik.h"

class KsiazkaUzytkownikow
{
	std::vector<Uzytkownik> uzytkownicy;

	std::string serializacjaUzytkownika(int pozycja);
	void deserializacjaUzytkownika(std::string& linijkaUzytkownika);

public:
	std::vector<Uzytkownik>& getUzytkownicy();
	void setUzytkownicy(int id, std::string& nazwa, std::string& haslo);
	void zapiszDoPliku(Plik& plik);
	void wczytajZPliku(Plik& plik);
};

