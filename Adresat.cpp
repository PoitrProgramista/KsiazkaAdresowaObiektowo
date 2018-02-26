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

int Adresat::getID()
{
	return id;
}

void Adresat::setImie(std::string& imie)
{
	this->imie = imie;
}

std::string Adresat::getImie()
{
	return imie;
}

void Adresat::setNazwisko(std::string& nazwisko)
{
	this->nazwisko = nazwisko;
}

std::string Adresat::getNazwisko()
{
	return nazwisko;
}

void Adresat::setTelefon(std::string& telefon)
{
	this->telefon = telefon;
}

std::string Adresat::getTelefon()
{
	return telefon;
}

void Adresat::setEmail(std::string& email)
{
	this->email = email;
}

std::string Adresat::getEmail()
{
	return email;
}

void Adresat::setAdres(std::string& adres)
{
	this->adres = adres;
}

std::string Adresat::getAdres()
{
	return adres;
}
