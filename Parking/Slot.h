#pragma once
#include "Samochod.h"
#include <SFML/Graphics.hpp>

// slot - miejsce parkingowe
class Slot : public Drawable // dziedziczymy po interfejsie  rysowania
{
	Samochod *samochod; // jaki samochod jest zaparkowany
	Sprite sprite;
	Texture texture;

public:
	Slot() { };
	Slot(int x, int y)   // okreslamy pozycje umieszczenia slotu na ekranie
	{
		texture.loadFromFile("grafika/pusty.png"); // wczytujemy obrazek
		sprite.setTexture(texture);
		sprite.setPosition(x, y);
	}

	void zaparkuj(Samochod samochod)
	{
		if (this->samochod) // sprawdz czy nie jest zaparkowany inny samochod
			this->samochod = &samochod;
		else
			cout << "Na tym miejscu juz jest zaparkowany inny samochod!" << endl;
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
		target.draw(sprite, states);
		detekcja_klikniecia(&target, sprite);
	}
};

