#include "Uzytkownik.h"


Uzytkownik::Uzytkownik(int idPodane, std::string& nazwaPodana, std::string& hasloPodane)
	: id(idPodane), nazwa(nazwaPodana), haslo(hasloPodane)
{
}

int Uzytkownik::getID()
{
	return id;
}

void Uzytkownik::setHaslo(std::string& hasloPodane)
{
	haslo = hasloPodane;
}

std::string& Uzytkownik::getHaslo()
{
	return haslo;
}

std::string& Uzytkownik::getNazwa()
{
	return nazwa;
}
