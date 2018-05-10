#pragma once
#include <vector>
#include <iostream>
#include "Samochod.h"
#include "Ciezarowy.h"
#include "Slot.h"
#include "Przycisk.h"

using namespace std;

class Parking : public Drawable // dziedziczymy po interfejsie  rysowania
{
private:

	int rzedy, kolumny, ile_zaparkowanych;
	Font czcionka;
	Text ile_zaparkowanych_txt, sr_masa_txt, sr_konie_mechaniczne_txt, sr_predkosc_txt, sr_zurzycie_benzyny_txt;
	vector<Text*> lista_tekstow; // przechowujemy wskaznik do wszystkich tekstow, aby szybko wykonywac na nich operacje za pomoca petli
	vector<Slot> sloty;

	// tworzymy przycisk, podajac nazwe obrazka ktory sie zaladuje, jego wymiary z pozycja ustawienia, oraz metode ktora sie wywola po kliknieciu przycisku
	Przycisk osobywy_btn = Przycisk("Osobowy", IntRect(500, 50, 200, 100), false);
	Przycisk ciezarowy_btn = Przycisk("Ciezarowy", IntRect(750, 50, 200, 100), false);

public:
	Parking(int rzedy, int kolumny, int kolumna_odstep, int rzad_odstep)
		:rzedy(rzedy), kolumny(kolumny), ile_zaparkowanych(0)// podajemy ile miejsc ma miec parking
	{
		// tworzymy sloty do parkowania i dodajemy je do listy
		for (size_t r = 0; r < rzedy; r++)
			for (size_t k = 0; k < kolumny; k++)
				sloty.push_back(Slot(rzad_odstep * r, kolumna_odstep * k));

		ustaw_teksty();
	}

	void ustaw_teksty()
	{
		// dodajemy referencje do tekstow dla listy
		lista_tekstow = vector<Text*>{ &ile_zaparkowanych_txt, &sr_masa_txt, &sr_konie_mechaniczne_txt, &sr_predkosc_txt, &sr_zurzycie_benzyny_txt };

		// wczytywanie czcionki
		if (!czcionka.loadFromFile("Czcionka/Arial.ttf"))
			cout << "Nie znaleziono czcionki!";

		// dzieki liscie mozemy wszystko szybko ustawic w petli dla kazdego tekstu
		for (size_t i = 0; i < lista_tekstow.size(); i++)
		{
			lista_tekstow[i]->setFont(czcionka);
			lista_tekstow[i]->setPosition(500, 10+50*i);
			ile_zaparkowanych_txt.setCharacterSize(20);
		}
		wyswietl_liczbe_samochodow(); // wyswietlamy informacje o samochodach na ekranie
	}

	void aktualizuj(RenderWindow * okno)
	{
		for (size_t i = 0; i < sloty.size(); i++)
		{
			bool klikniecie = sloty[i].pobierz_przycisk()->detekcja_klikniecia(okno);

			// jezeli nastapilo klikniecie na danym slocie
			if (klikniecie)
			{
				if (sloty[i].czy_zajety())
					wyparkuj(i);
				else
					dodaj_samochod(i);   // dodaj samochod na danym miejscu
			}
		}
	}

	void uaktualnij_statystyki(int masa, int konie_mech, int predkosc, int zurzyc_benz)
	{
		sr_masa_txt.setString("Sr. masa:       " + to_string(predkosc));
		sr_predkosc_txt.setString("Sr. predkosc:   " + to_string(predkosc));
		sr_konie_mechaniczne_txt.setString("Sr. km:         " + to_string(konie_mech));
		sr_zurzycie_benzyny_txt.setString("Sr. zurz. benz. " + to_string(zurzyc_benz));
	}
	// prywatne metody************************************************************************************************************
private:

	void pokaz_przyciski_samochodow(bool pokaz)
	{
		osobywy_btn.pokaz_przycisk(pokaz);
		ciezarowy_btn.pokaz_przycisk(pokaz);
	}

	void dodaj_samochod(int miejsce) // dodaj samochod do konkretnego slotu
	{
		wyswietl_liczbe_samochodow(1); // dodajemy jeden

		cout << "Dodaj samochod" << endl;
		Ciezarowy ss;
		sloty[miejsce].zaparkuj(ss);
	}

	void wyswietl_liczbe_samochodow(int zmiana = 0)
	{
		ile_zaparkowanych += zmiana; //dodajemy zmiane moze to byc ujemna liczba jak i dodatnia w zaleznosci czy parkujemy czy zwalniamy mniejsce
		ile_zaparkowanych_txt.setString("zaparkowane samochody: " + to_string(ile_zaparkowanych) + "/" + to_string(sloty.size()));// uaktualniamy wyswietlony napis;
	}

	void wyparkuj(int miejsce)
	{
		wyswietl_liczbe_samochodow(-1); // odejmujemy jeden
		cout << "Wyparkuj samochod" << endl;
		sloty[miejsce].wyparkuj();
	}

	void draw(RenderTarget & target, RenderStates state) const // implementujemy metode odpowiedzialna za rysowanie na ekranie obiekty typu parking
	{
		// rysuj miejsca parkingowe
		for (size_t i = 0; i < rzedy*kolumny; i++)
			target.draw(sloty[i]);

		target.draw(ile_zaparkowanych_txt);
		target.draw(osobywy_btn);
		target.draw(ciezarowy_btn);
	}
};


