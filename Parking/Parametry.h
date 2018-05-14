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
	Parametry();
	Parametry(int masa, int predkosc, int zurzycie_benzyny, int konie_mechaniczne);

	// gettery
	int get_masa() { return masa; }
	int get_km() { return konie_mechaniczne; }
	int get_predkosc() { return predkosc; }
	int get_zurz_benz() { return zuzycie_benzyny; }

	// przeciazenie operatorow dodawania
	Parametry operator+(const Parametry & skladnik);
	Parametry operator+=(const Parametry & skladnik);
	
	Parametry operator/=(int skalar);
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

