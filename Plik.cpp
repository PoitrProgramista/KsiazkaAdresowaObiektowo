#include "Plik.h"


void Plik::zapiszLinijkeDoPliku(std::string& linijkaTekstu)
{
	dostosujFormatowanie();
	dostepDoPliku << linijkaTekstu;
}

void Plik::wczytajLinijkeZPliku(std::string& linijkaTekstu)
{
	std::getline(dostepDoPliku, linijkaTekstu);
}

bool Plik::czyKoniecPliku()
{
	return dostepDoPliku.eof();
}

bool Plik::otworzPlikDoZapisu(const std::string& nazwaPliku)
{
	dostepDoPliku.open(nazwaPliku, std::ios::out);
	return czyPoprawny();
}

bool Plik::otworzPlikDoDopisania(const std::string& nazwaPliku)
{
	dostepDoPliku.open(nazwaPliku, std::ios::out | std::ios::app);
	return czyPoprawny();
}

bool Plik::otworzPlikDoOdczytu(const std::string& nazwaPliku)
{
	dostepDoPliku.open(nazwaPliku, std::ios::in);
	return czyPoprawny() && czyNiePusty();
}

void Plik::zamknijPlik()
{
	dostepDoPliku.close();
}

int Plik::pobierzDlugoscPliku()
{
	dostepDoPliku.seekg(0, std::ios::end);
	int length = dostepDoPliku.tellg();

	return length;
}

bool Plik::czyPoprawny()
{
	if (dostepDoPliku.good() == false)
	{
		return false;
	}
	return true;
}

bool Plik::czyNiePusty()
{
	return !( dostepDoPliku.peek() == '/n' );
}

void Plik::dostosujFormatowanie()
{

	int length = pobierzDlugoscPliku();

	if (length != 0)
		dostepDoPliku << std::endl;
}



