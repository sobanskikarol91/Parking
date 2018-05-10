#pragma once
#include "Samochod.h"

class Ciezarowy : public Samochod
{
	int max_zaladunek;

public:
	Ciezarowy() : Samochod() 
	{
		tekstura.loadFromFile("grafika/ciezarowka.png");
	};

	Ciezarowy(string marka, Parametry parametry)
		: Samochod(marka, parametry), max_zaladunek(max_zaladunek) 
	{
		tekstura.loadFromFile("grafika/ciezarowka.png");
	};

	virtual void stworz_samochod() override
	{
		Samochod::stworz_samochod();
		cout << "Podaj maksymalny zaladunek ciezarowki w kg: ";
		cin >> max_zaladunek;
	}
};

