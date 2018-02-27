#pragma once
#include <string>

class Uzytkownik
{
	int id;
	std::string nazwa, haslo;

public:
	Uzytkownik(int id, std::string& nazwa, std::string& haslo);
	int pobierzID();
	std::string& pobierzHaslo();
	std::string& pobierzNazwa();
	void ustawHaslo(std::string& hasloPodane);


};

