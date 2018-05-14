#pragma once
#include "Samochod.h"

class Ciezarowy : public Samochod
{
	int max_zaladunek;

public:
	Ciezarowy();
	Ciezarowy(string marka, Parametry parametry);
	virtual void stworz_samochod() override;
};

