#pragma once
#include "Przycisk.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Przycisk
{
public:
	bool detekcja_klikniecia(Window * okno, const Sprite & sprite)
	{
		// pozycja myszy wzgledem okna
		Vector2i mysz = Mouse::getPosition(*okno);

		// okreslamy granice polozenia prostokata
		FloatRect granica = sprite.getGlobalBounds();

		// sprawdzamy czy wystapilo klikniecie w obszarze obiektu
		return (mysz_nad_obiektem  && Mouse::isButtonPressed(Mouse::Left));
	}

	bool mysz_nad_obiektem(Vector2i mysz, FloatRect granica)
	{
		return (mysz.x >= granica.left &&  mysz.x <= granica.left + granica.width &&
			mysz.y >= granica.top && mysz.y <= granica.top + granica.height);
	}
};

