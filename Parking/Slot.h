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
	Slot();
	Slot(int x, int y);  // okreslamy pozycje umieszczenia slotu na ekranie
	void zaparkuj(Samochod samochod);
	void wyparkuj();
	void draw(RenderTarget & target, RenderStates states) const;
	bool czy_zajety();
	Przycisk * pobierz_przycisk();
	Samochod * pobierz_samochod();
};

