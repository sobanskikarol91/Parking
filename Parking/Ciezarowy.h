#pragma once
#include "Samochod.h"

class Ciezarowy : public Samochod
{
	int maksymalny_zaladunek;

public:
	Ciezarowy(string nazwa, int rok) : Samochod(nazwa, rok) {};
};

