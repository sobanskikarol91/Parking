#pragma once
#include "Samochod.h"
#include <SFML/Graphics.hpp>
#include "Przycisk.h"

// slot - miejsce parkingowe
class Slot : public Drawable // dziedziczymy po interfejsie  rysowania
{
	Samochod *samochod; // jaki samochod jest zaparkowany
	Przycisk przycisk;
public:
	Slot() { };

	Slot(int x, int y)   // okreslamy pozycje umieszczenia slotu na ekranie
	{
		przycisk = Przycisk("pusty", IntRect(x, y, 100, 100), true);
	}

	void zaparkuj(Samochod * samochod)
	{
		samochod = samochod;
		Texture * tekstura_samochodu = samochod->pobierz_teksture();
		przycisk.ustaw_wcisnieta_teksture(tekstura_samochodu);
	}

	void wyparkuj()
	{
		if (this->samochod)
			samochod = NULL;
		else
			cout << "Nie mozna wyparkowac, poniewaz nie ma zadnego zaparkowanego samochodu!" << endl;
	}

	void draw(RenderTarget & target, RenderStates states) const
	{
		target.draw(przycisk, states);
	}

	bool czy_zajety()
	{
		return samochod != NULL; // jezeli wskaznik nie pokazuje na zaden samochod to znaczy ze miejsce wolne
	}

	Przycisk * pobierz_przycisk()
	{
		return &przycisk;
	}
};

