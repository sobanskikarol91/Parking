#include "Sportowy.h"

Sportowy::Sportowy() : Samochod()
{
	tekstura.loadFromFile("grafika/sport.png");
};

Sportowy::Sportowy(string marka, Parametry parametry, int nitro)
	: Samochod(marka, parametry), nitro(nitro)
{
	tekstura.loadFromFile("grafika/sport.png");
};

void Sportowy::stworz_samochod()
{
	Samochod::stworz_samochod();
	cout << "Podaj pojemnosc nitro: ";
	cin >> nitro;
}