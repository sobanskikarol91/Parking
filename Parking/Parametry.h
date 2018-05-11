#pragma once
#include <iostream>
using namespace std;

// kazdy samochod bedzie miec parametry ktore bedziemy statystycznie pokazywac na parkingu.
class Parametry
{
	int masa;
	int konie_mechaniczne;
	int predkosc;
	int zuzycie_benzyny;

public:
	Parametry() : masa(0), konie_mechaniczne(0), predkosc(0), zuzycie_benzyny(0) {};  // ustawiamy poczatkowe wartosci na 0
	Parametry(int masa, int predkosc, int zurzycie_benzyny, int konie_mechaniczne) : predkosc(predkosc), zuzycie_benzyny(zurzycie_benzyny), konie_mechaniczne(konie_mechaniczne) {};

	// gettery
	int get_masa() { return masa; }
	int get_km() { return konie_mechaniczne; }
	int get_predkosc() { return predkosc; }
	int get_zurz_benz() { return zuzycie_benzyny; }

	// przeciazenie operatorow dodawania
	Parametry operator+(const Parametry & skladnik)
	{
		return Parametry(masa + skladnik.masa, zuzycie_benzyny + skladnik.zuzycie_benzyny, predkosc + skladnik.predkosc, konie_mechaniczne + skladnik.konie_mechaniczne);
	}

	Parametry operator+=(const Parametry & skladnik)
	{
		masa += skladnik.zuzycie_benzyny;
		zuzycie_benzyny += skladnik.zuzycie_benzyny;
		predkosc += skladnik.predkosc;
		konie_mechaniczne += skladnik.konie_mechaniczne;
		return *this;
	}

	// przeciazenie operatora dzielenia przez skalar przyda sie do obliczania srednich statystyk
	
	Parametry operator/=(int skalar)
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
	// przeciazenie operatora wczytania
	friend istream & operator>>(istream & klawiatura, Parametry & p)
	{
		cout << "Masa: ", klawiatura >> p.masa;
		cout << "Ilosc Koni mechanicznych: ", klawiatura >> p.konie_mechaniczne;
		cout << "Zuzycnie benzyny: ", klawiatura >> p.zuzycie_benzyny;
		cout << "Predkosc: ", klawiatura >> p.predkosc;
		return klawiatura;
	}
};

