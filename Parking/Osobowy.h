#pragma once
#include "Samochod.h"

class Osobowy : public Samochod
{
	// samochod osobowy moze miec jakeis inne parametry 
public:
	Osobowy() : Samochod()
	{
		tekstura.loadFromFile("grafika/osobowy.png");
	};

	Osobowy(string marka, Parametry parametry)
		: Samochod(marka, parametry)
	{
		tekstura.loadFromFile("grafika/osobowy.png");
	};

	virtual void stworz_samochod() override
	{
		Samochod::stworz_samochod();
	}
};

