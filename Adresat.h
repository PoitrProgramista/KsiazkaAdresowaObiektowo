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
	void ustawImie(std::string& imie);
	void ustawNazwisko(std::string& nazwisko);
	void ustawTelefon(std::string& telefon);
	void ustawEmail(std::string& email);
	void ustawAdres(std::string& adres);
	int pobierzID();
	std::string pobierzImie();
	std::string pobierzNazwisko();
	std::string pobierzTelefon();
	std::string pobierzEmail();
	std::string pobierzAdres();

};
