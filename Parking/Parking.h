#pragma once
#include <vector>
#include <iostream>
#include "Samochod.h"
#include "Ciezarowy.h"
#include "Sportowy.h"
#include "Osobowy.h"
#include "Slot.h"
#include "Przycisk.h"
#include "Parametry.h"
#include "InputHandler.h" // do korygowania wprowadzonych danych
using namespace std;

class Parking : public Drawable // dziedziczymy po interfejsie rysowania
{
private:

	int rzedy, kolumny, ile_zaparkowanych;
	Font czcionka;
	Text ile_zaparkowanych_txt, sr_masa_txt, sr_konie_mechaniczne_txt, sr_predkosc_txt, sr_zuzycie_benzyny_txt;
	vector<Text*> lista_tekstow; // przechowujemy wskaznik do wszystkich tekstow, aby szybko wykonywac na nich operacje za pomoca petli
	vector<Slot> sloty;          // sloty w ktorych parkujemy samochody
	Texture znak_tekstura;       // znak parkingu
	Sprite znak_sprite;

public:
	Parking(int rzedy, int kolumny, int kolumna_odstep, int rzad_odstep);

	void aktualizuj(RenderWindow * okno);
	// prywatne metody uzywamy je tylko w klasie ************************************************************************************************************
private:
	void uaktualnij_statystyki();
	void ustaw_teksty();
	void ustaw_znak();
	void zaparkuj(int miejsce); // dodaj samochod do konkretnego slotu
	void wyparkuj(int miejsce);
	void draw(RenderTarget & target, RenderStates state) const; // implementujemy metode odpowiedzialna za rysowanie na ekranie obiekty typu parking
};


