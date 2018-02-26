#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <windows.h>

class Plik
{
	std::fstream dostepDoPliku;

	bool czyPoprawny();
	bool czyNiePusty();
	void dostosujFormatowanie();
	int getDlugoscPliku();

public:
	bool czyKoniecPliku();
	bool otworzPlikDoZapisu(const std::string& nazwaPliku);
	bool otworzPlikDoDopisania(const std::string& nazwaPliku);
	bool otworzPlikDoOdczytu(const std::string& nazwaPliku);
	void zapiszLinijkeDoPliku(std::string& linijkaTekstu);
	void wczytajLinijkeZPliku(std::string& linijkaTekstu);
	void zamknijPlik();
};

