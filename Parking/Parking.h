#pragma once
#include <vector>
#include <iostream>
#include "Samochod.h"
#include "Slot.h"
#include <string>
#include "Przycisk.h"

using namespace std;

class Parking : public Drawable // dziedziczymy po interfejsie  rysowania
{
	int rzedy, kolumny;
	Font czcionka;
	Text ile_zaparkowanych_txt;
	int ile_zaparkowanych;
	vector<Slot> sloty;
	
	Przycisk zaparkuj_btn = Przycisk("Zaparkuj", IntRect(500, 50, 200, 100));
	Przycisk wyparkuj_btn = Przycisk("Wyparkuj", IntRect(500, 200, 200, 100));

public:
	Parking(int rzedy, int kolumny, int kolumna_odstep, int rzad_odstep) :rzedy(rzedy), kolumny(kolumny), ile_zaparkowanych(0) // podajemy ile miejsc ma miec parking
	{
		for (size_t r = 0; r < rzedy; r++)
			for (size_t k = 0; k < kolumny; k++)
				sloty.push_back(Slot(rzad_odstep * r, kolumna_odstep * k));

		if (!czcionka.loadFromFile("Czcionka/Arial.ttf"))
			cout << "Nie znaleziono czcionki!";

		ile_zaparkowanych_txt.setFont(czcionka);
		ile_zaparkowanych_txt.setPosition(500, 10);
		ile_zaparkowanych_txt.setString("zaparkowane samochody: " + to_string(ile_zaparkowanych));
		ile_zaparkowanych_txt.setCharacterSize(20);
	}

	void draw(RenderTarget & target, RenderStates state) const // implementujemy metode odpowiedzialna za rysowanie na ekranie obiekty typu parking
	{
		for (size_t i = 0; i < rzedy*kolumny; i++)
		{
			target.draw(sloty[i]);
		}
		target.draw(ile_zaparkowanych_txt);
		target.draw(zaparkuj_btn);
		target.draw(wyparkuj_btn);

		RenderWindow * okno = dynamic_cast<RenderWindow*>(&target);
		if (zaparkuj_btn.detekcja_klikniecia(okno))
			cout << "zaparkuj";
		else if (wyparkuj_btn.detekcja_klikniecia(okno))
			cout << "wyparkuj";
	}
};

