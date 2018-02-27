#include "Adresat.h"


Adresat::Adresat(int id, std::string& imie, std::string& nazwisko, std::string& telefon,
				 std::string& email, std::string& adres)
	: id(id), imie(imie), nazwisko(nazwisko), telefon(telefon), email(email), adres(adres)
{
}

void Adresat::wyswietlAdresata()
{
	std::cout << id << std::endl << imie << " " << nazwisko << std::endl << telefon << std::endl << email << std::endl << adres << std::endl << std::endl;;
}

int Adresat::pobierzID()
{
	return id;
}

void Adresat::ustawImie(std::string& imie)
{
	this->imie = imie;
}

std::string Adresat::pobierzImie()
{
	return imie;
}

void Adresat::ustawNazwisko(std::string& nazwisko)
{
	this->nazwisko = nazwisko;
}

std::string Adresat::pobierzNazwisko()
{
	return nazwisko;
}

void Adresat::ustawTelefon(std::string& telefon)
{
	this->telefon = telefon;
}

std::string Adresat::pobierzTelefon()
{
	return telefon;
}

void Adresat::ustawEmail(std::string& email)
{
	this->email = email;
}

std::string Adresat::pobierzEmail()
{
	return email;
}

void Adresat::ustawAdres(std::string& adres)
{
	this->adres = adres;
}

std::string Adresat::pobierzAdres()
{
	return adres;
}
