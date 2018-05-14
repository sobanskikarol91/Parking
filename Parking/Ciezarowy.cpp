#include "Ciezarowy.h"

Ciezarowy::Ciezarowy() : Samochod()
{
	tekstura.loadFromFile("grafika/ciezarowka.png");
};

Ciezarowy::Ciezarowy(string marka, Parametry parametry)
	: Samochod(marka, parametry), max_zaladunek(max_zaladunek)
{
	tekstura.loadFromFile("grafika/ciezarowka.png");
};

void Ciezarowy::stworz_samochod()
{
	Samochod::stworz_samochod();
	cout << "Podaj maksymalny zaladunek ciezarowki w kg: ";
	cin >> max_zaladunek;
}