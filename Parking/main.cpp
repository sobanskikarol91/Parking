#define NOMINMAX   // windows.h clashes with the STL, which frankly is a problem with windows.h.

#include "Parking.h"
//test
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Slot.h"
#include "Samochod.h"
#include "Ciezarowy.h"

using namespace std;
using namespace sf;

void okno()
{
	Parking parking(4, 4, 130, 100);
	RenderWindow okno{ VideoMode(1000, 700), "Parking" };
	okno.setFramerateLimit(60);
	Event event; // do interakci z oknem
	
	while (okno.isOpen())
	{
		okno.clear(Color::Blue);  // czysc ekran na czarno
		okno.pollEvent(event);
		okno.draw(parking);

		if (event.type == Event::Closed)  // zamykanie myszka okna
		{
			okno.close();
			break;
		}

		parking.aktualizuj(&okno);
		okno.display();
	}
}

void main()
{
	Ciezarowy c;
	okno();
	system("pause");
}
