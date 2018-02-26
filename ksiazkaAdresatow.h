#pragma once
#include <vector>
#include <string>
#include "Adresat.h"
#include "Plik.h"

class KsiazkaAdresatow
{
	std::vector<Adresat> adresaci;
	int idOstatniegoAdresata;

	int znajdzAdresata();
	int znajdzIdAdresata(std::string& linijkaAdresata);
	int znajdzIdUzytkownika(std::string& linijkaAdresata);
	std::string serializacjaAdresata(int pozycja, int idZalogowanegoUzytkownika);
	bool deserializacjaAdresata(std::string& linijkaAdresata, int idZalogowanegoUzytkownika);
	
public:
	int wczytajZPliku(Plik& plik, int idZalogowanegoUzytkownika);
	void zapiszDoPliku(Plik& plik, int idZalogowanegoUzytkownika);
	void wyczyscAdresatow();
	void dodajAdresata();
	void edytujAdresata();
	void usunAdresata();
	void wyswietlWszystkichAdresatow();
	void wyswietlAdresatowOImieniu();
	void wyswietlAdresatowONazwisku();
};

