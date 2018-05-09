#pragma once
#include "Przycisk.h"
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

class Przycisk : public Drawable
{
	Texture domyslna_tekstura;
	Sprite sprite;
	bool klawisz_nacisniety;  // flaga ktora przyda sie do detekcji pojedynczego klikniecia 
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

	bool pojedyncze_klikniecie()
	{
		// sprawdzamy czy wystapilo pojedyncze klikniecie lewym przyciskiem myszy i czy wczesniej klawisz byl puszczony zalezy nam na detekcji tylko pojedynczego klikniecia
		if (!klawisz_nacisniety && Mouse::isButtonPressed(Mouse::Left))
		{
			klawisz_nacisniety = true;
			return true;
		}
		else if (!Mouse::isButtonPressed(Mouse::Left))
			klawisz_nacisniety = false;

		return false;
	}

	bool detekcja_klikniecia(const Window * okno)
	{
		// jezeli jest nieaktyny zwroc false
		if (!aktywny) return false;

		// pozycja myszy wzgledem okna
		Vector2i mysz = Mouse::getPosition(*okno);

		// okreslamy granice polozenia prostokata
		FloatRect granica = sprite.getGlobalBounds();

		// sprawdzamy czy wystapilo klikniecie w obszarze obiektu
		return (mysz_nad_obiektem(mysz, granica) && pojedyncze_klikniecie());
	}

	void ustaw_wcisnieta_teksture(Texture * nowa_teksutra)
	{
		sprite.setTexture(*nowa_teksutra);
	}

	void przywroc_domyslna_teksture()
	{
		sprite.setTexture(domyslna_tekstura);
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

