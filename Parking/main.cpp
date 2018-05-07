#define NOMINMAX   // windows.h clashes with the STL, which frankly is a problem with windows.h.
#include "Parking.h"

//test
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "DodatkoweFunkcje.h"

using namespace std;
using namespace sf;

void okno()
{
	RenderWindow window{ VideoMode(1000, 1000), "Parking" };
	window.setFramerateLimit(60);
	Event event; // do interakci z oknem

	while (true)
	{
		window.clear(Color::Black);  // czysc ekran na czarno
		window.pollEvent(event);

		if (event.type == Event::Closed)  // zamykanie myszka okna
		{
			window.close();
			break;
		}
		window.display();
	}
}


void main()
{
	okno();
}
