#include "Uzytkownik.h"


Uzytkownik::Uzytkownik(int idPodane, std::string& nazwaPodana, std::string& hasloPodane)
	: id(idPodane), nazwa(nazwaPodana), haslo(hasloPodane)
{
}

int Uzytkownik::pobierzID()
{
	return id;
}

void Uzytkownik::ustawHaslo(std::string& hasloPodane)
{
	haslo = hasloPodane;
}

std::string& Uzytkownik::pobierzHaslo()
{
	return haslo;
}

std::string& Uzytkownik::pobierzNazwa()
{
	return nazwa;
}
