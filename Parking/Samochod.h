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
	Samochod();  // domyslny konstruktor z lista inicjalizacyjna
	Samochod(string marka, Parametry parametry);
	Texture * pobierz_teksture();
	Parametry pobierz_parametry();
	// mozna tutaj wykonac przeciazenie operatora wczytania jak w klasie Parametr
	// ale chcemy utworzyc jakas sensowna metode virtualna, ktora dla klas pochodnych bedzie wygladac troche inaczej
	// po to aby zastosowac polimorfizm
	virtual void stworz_samochod();
};

