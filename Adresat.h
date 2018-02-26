#pragma once
#include <string>
#include <iostream>

class Adresat
{
	int id;
	std::string imie, nazwisko, telefon, email, adres;

public:
	Adresat(int id, std::string& imie, std::string& nazwisko, std::string& telefon,
			std::string& email, std::string& adres);
	void wyswietlAdresata();
	void setImie(std::string& imie);
	void setNazwisko(std::string& nazwisko);
	void setTelefon(std::string& telefon);
	void setEmail(std::string& email);
	void setAdres(std::string& adres);
	int getID();
	std::string getImie();
	std::string getNazwisko();
	std::string getTelefon();
	std::string getEmail();
	std::string getAdres();

};
