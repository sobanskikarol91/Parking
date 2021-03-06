#include "Parametry.h"

Parametry::Parametry() : masa(0), konie_mechaniczne(0), predkosc(0), zuzycie_benzyny(0) {};  // ustawiamy poczatkowe wartosci na 0
Parametry::Parametry(int masa, int predkosc, int zurzycie_benzyny, int konie_mechaniczne) : predkosc(predkosc), zuzycie_benzyny(zurzycie_benzyny), konie_mechaniczne(konie_mechaniczne) {};

// przeciazenie operatorow dodawania
Parametry Parametry::operator+(const Parametry & skladnik)
{
	return Parametry(masa + skladnik.masa, zuzycie_benzyny + skladnik.zuzycie_benzyny, predkosc + skladnik.predkosc, konie_mechaniczne + skladnik.konie_mechaniczne);
}

Parametry Parametry::operator+=(const Parametry & skladnik)
{
	masa += skladnik.zuzycie_benzyny;
	zuzycie_benzyny += skladnik.zuzycie_benzyny;
	predkosc += skladnik.predkosc;
	konie_mechaniczne += skladnik.konie_mechaniczne;
	return *this;
}

// przeciazenie operatora dzielenia przez skalar przyda sie do obliczania srednich statystyk
Parametry Parametry::operator/=(int skalar)
{
	if (skalar != 0)
	{
		masa /= skalar;
		zuzycie_benzyny /= skalar;
		predkosc /= skalar;
		konie_mechaniczne /= skalar;
	}
	else
		cout << "dzielenie przez zero!";

	return *this;
}