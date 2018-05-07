#pragma once
#include <vector>
#include <iostream>
#include "Samochod.h"
#include "Slot.h"

using namespace std;

class Parking : Drawable // dziedziczymy po interfejsie  rysowania
{
	int rzad, kolumna;
	int kolumna_odstep, rzad_odstep; // odstepy miedyz kolumnami i rzedami

	vector<Slot> lista_samochodow;

public:
	Parking(int rzedy, int kolumny) // podajemy ile miejsc ma miec parking
	{
		// tworzymy tyle slotow ile jest miejsc
		for (size_t i = 0; i < rzedy*kolumny; i++)
		{
			lista_samochodow.push_back(Slot());
		}
	}

	void zaparkuj(Samochod samochod, int wybrane_miejsce)
	{

	}

	void wyparkuj(Samochod samochod)
	{

	}

	void informacja()
	{

	}

	void draw() // implementujemy metode odpowiedzialna za rysowanie na ekranie obiekty typu parking
	{

	}
};

