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
	function<void()> akcja_klikniecia;

public:
	Przycisk() {};
	Przycisk(string nazwa, IntRect obszar, function<void()> akcja_klikniecia) : akcja_klikniecia(akcja_klikniecia) // nazwa pozycja i wymiar i metoda jaka ma sie wywolac przy kliknieciu
	{		
		domyslna_tekstura.loadFromFile("grafika/" + nazwa + ".png");
		sprite.setPosition(obszar.left, obszar.top);
		sprite.setTexture(domyslna_tekstura);
	}

	bool mysz_nad_obiektem(Vector2i mysz, FloatRect granica) const
	{
		return (mysz.x >= granica.left &&  mysz.x <= granica.left + granica.width &&
			mysz.y >= granica.top && mysz.y <= granica.top + granica.height);
	}

	void detekcja_klikniecia(const Window * okno) const
	{
		// pozycja myszy wzgledem okna
		Vector2i mysz = Mouse::getPosition(*okno);

		// okreslamy granice polozenia prostokata
		FloatRect granica = sprite.getGlobalBounds();

		// sprawdzamy czy wystapilo klikniecie w obszarze obiektu
		if (mysz_nad_obiektem(mysz, granica) && Mouse::isButtonPressed(Mouse::Left))
			akcja_klikniecia();
	}

	void ustaw_wcisnieta_teksture(Texture nowa_teksutra)
	{
		sprite.setTexture(nowa_teksutra);
	}

	void draw(RenderTarget & target, RenderStates state) const
	{
		target.draw(sprite);
	}
};

