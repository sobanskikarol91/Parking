#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Samochod
{
protected:   // dostepne dla klas pochodnych
	string marka;
	int predkosc;
	int rok;

	Texture tekstura;
	Sprite sprite;

public:
	Samochod() : marka("nieznana"), predkosc(0), rok(0) 
	{
		tekstura.loadFromFile("grafika/ciezarowy.png");
	}  // domyslny konstruktor z lista inicjalizacyjna
	Samochod(string marka, int predkosc, int rok) : marka(marka), predkosc(predkosc), rok(rok) 
	{
		tekstura.loadFromFile("grafika/ciezarowy.png");
	};

	// przeciazenie operatora wprowadzania danych 
	friend istream & operator>>(istream & klawiatura, Samochod & s)	{
		
		cout << "Podaj marke samochodu: ";
		klawiatura >> s.marka;
		cout << "Podaj maksymalna predkosc: ";
		cin >> s.predkosc;
		return klawiatura;
	}

	Texture * pobierz_teksture()
	{
		return &tekstura;
	}
};

