#pragma once
#include <iostream>
#include <Windows.h>
#include "Uzytkownik.h"
#include "KsiazkaUzytkownikow.h"
#include "ksiazkaAdresatow.h"
#include "Plik.h"

class KsiazkaAdresowa
{
	Plik plik;
	int idZalogowanegoUzytkownika;
	KsiazkaUzytkownikow ksiazkaUzytkownikow;
	KsiazkaAdresatow ksiazkaAdresatowZalogowanegoUzytkownika;

	void zaloguj();
	void wyloguj();
	void zarejestruj();
	void zmienHaslo();
	void wyjdz();

public:
	KsiazkaAdresowa();
	int pobierzIDZalogowanegoUzytkownika();
	void wyswietlMenuGlowne();
	void wyswietlMenuUzytkownika();
};
