#pragma once
#include "Przycisk.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <functional>  // dla konstruktora w ktorym bedizemy przyjmowac argument jako wskaznik do metody innej klasy

using namespace sf;
using namespace std;

class Przycisk : public Drawable
{
	Texture domyslna_tekstura;
	Texture wcisnieta_tekstura;
	Sprite sprite;
	bool aktywny; // czy przycisk aktywny

public:
	Przycisk() {};
	Przycisk(string nazwa, IntRect obszar, bool pokaz) // pokaz - czy przycisk ma byc schowany na poczatku 
	{
		pokaz_przycisk(pokaz);

		domyslna_tekstura.loadFromFile("grafika/" + nazwa + ".png");
		sprite.setPosition(obszar.left, obszar.top);
		sprite.setTexture(domyslna_tekstura);
	}

	bool mysz_nad_obiektem(Vector2i mysz, FloatRect granica) const
	{
		return (mysz.x >= granica.left &&  mysz.x <= granica.left + granica.width &&
			mysz.y >= granica.top && mysz.y <= granica.top + granica.height);
	}

	bool detekcja_klikniecia(const Window * okno) const
	{
		// jezeli jest nieaktyny zwroc false
		if (!aktywny) return false;
		cout << "detekcja";
		// pozycja myszy wzgledem okna
		Vector2i mysz = Mouse::getPosition(*okno);

		// okreslamy granice polozenia prostokata
		FloatRect granica = sprite.getGlobalBounds();

		// sprawdzamy czy wystapilo klikniecie w obszarze obiektu
		return (mysz_nad_obiektem(mysz, granica) && Mouse::isButtonPressed(Mouse::Left));
	}

	void ustaw_wcisnieta_teksture(Texture * nowa_teksutra)
	{
		sprite.setTexture(*nowa_teksutra);
	}

	void draw(RenderTarget & target, RenderStates state) const
	{
		target.draw(sprite);
	}

	void pokaz_przycisk(bool state)
	{
		aktywny = state;
		if (!aktywny)  // jak aktywny pokaz wizualnie
			sprite.setColor(Color::Transparent);
		else
			sprite.setColor(Color::White);
	}
};

