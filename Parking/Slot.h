#pragma once
#include "Samochod.h"
#include <SFML/Graphics.hpp>
#include "Przycisk.h"

// slot - miejsce parkingowe
class Slot : public Drawable // dziedziczymy po interfejsie  rysowania
{
	bool zajety;
	Samochod samochod; // jaki samochod jest zaparkowany
	Przycisk przycisk;

public:
	Slot() { };

	Slot(int x, int y)  // okreslamy pozycje umieszczenia slotu na ekranie
		:zajety(false), samochod(Samochod()), przycisk(Przycisk("puste", IntRect(x, y, 100, 100), true)) {}


	void zaparkuj(Samochod samochod)
	{
		cout << "Parkuje na slocie " << endl;
		zajety = true;
		this->samochod = samochod;
		Texture * tekstura_samochodu = this->samochod.pobierz_teksture();
		przycisk.ustaw_wcisnieta_teksture(tekstura_samochodu);
	}

	void wyparkuj()
	{
		cout << "slot wolny";
		zajety = false;
		przycisk.przywroc_domyslna_teksture();
	}

	void draw(RenderTarget & target, RenderStates states) const
	{
		target.draw(przycisk, states);
	}

	bool czy_zajety()
	{
		return zajety;
	}

	Przycisk * pobierz_przycisk()
	{
		return &przycisk;
	}

	Samochod * pobierz_samochod()
	{
		return &samochod;
	}
};

