#include "Osobowy.h"

Osobowy::Osobowy() : Samochod()
{
	tekstura.loadFromFile("grafika/osobowy.png");
};

Osobowy::Osobowy(string marka, Parametry parametry)
	: Samochod(marka, parametry)
{
	tekstura.loadFromFile("grafika/osobowy.png");
};

void Osobowy::stworz_samochod()
{
	Samochod::stworz_samochod();
}
