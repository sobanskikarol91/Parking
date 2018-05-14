#pragma once
#include "Samochod.h"

class Sportowy : public Samochod
{
	int nitro;
public:
	Sportowy();
	Sportowy(string marka, Parametry parametry, int nitro);
	virtual void stworz_samochod() override;
};

