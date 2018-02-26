#pragma once
#include <string>

class Uzytkownik
{
	int id;
	std::string nazwa, haslo;

public:
	Uzytkownik(int id, std::string& nazwa, std::string& haslo);
	int getID();
	std::string& getHaslo();
	std::string& getNazwa();
	void setHaslo(std::string& hasloPodane);


};

