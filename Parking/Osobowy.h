#pragma once
#include "Samochod.h"

class Osobowy : public Samochod
{
	// samochod osobowy moze miec jakeis inne parametry 
public:
	Osobowy();
	Osobowy(string marka, Parametry parametry);
	virtual void stworz_samochod() override;
};

