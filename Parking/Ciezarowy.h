#pragma once
#include "Samochod.h"

class Ciezarowy : public Samochod
{
	int max_zaladunek;

public:
	Ciezarowy() : Samochod() {};
	Ciezarowy(string nazwa, int predkosc, int rok, int max_zaladunek) 
		: Samochod(nazwa, predkosc, rok), max_zaladunek(max_zaladunek) {};
};

