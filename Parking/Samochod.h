#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Parametry.h"

using namespace std;
using namespace sf;

class Samochod
{
protected:   // dostepne dla klas pochodnych
	string marka;

	Parametry parametry;
	Texture tekstura;
	Sprite sprite;

public:
	Samochod() : marka("nieznana")   // domyslny konstruktor z lista inicjalizacyjna
	{
		tekstura.loadFromFile("grafika/ciezarowy.png");
	}

	Samochod(string marka, Parametry parametry) : marka(marka), parametry(parametry)
	{
		tekstura.loadFromFile("grafika/ciezarowy.png");
	}

	// przeciazenie operatora wprowadzania danych 
	friend istream & operator>>(istream & klawiatura, Samochod & s)
	{
		return klawiatura;
	}

	Texture * pobierz_teksture()
	{
		return &tekstura;
	}

	Parametry pobierz_parametry()
	{
		return parametry;
	}

	// mozna tutaj wykonac przeciazenie operatora wczytania jak w klasie Parametr
	// ale chcemy utworzyc jakas sensowna metode virtualna, ktora dla klas pochodnych bedzie wygladac troche inaczej
	// po to aby zastosowac polimorfizm
	virtual void stworz_samochod()
	{
		cout << "Podaj marke samochodu: ";
		cin >> marka;
		cout << "Wprowadz Parametry" << endl;
		cin >> parametry;
	}
};

