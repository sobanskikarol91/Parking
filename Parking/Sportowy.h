#pragma once
#include "Samochod.h"

class Sportowy : public Samochod
{
	int nitro;
public:
	Sportowy() : Samochod()
	{
		tekstura.loadFromFile("grafika/sport.png");
	};

	Sportowy(string marka, Parametry parametry, int nitro)
		: Samochod(marka, parametry), nitro(nitro)
	{
		tekstura.loadFromFile("grafika/sport.png");
	};

	virtual void stworz_samochod() override
	{
		Samochod::stworz_samochod();
		cout << "Podaj pojemnosc nitro: ";
		cin >> nitro;
	}
};

