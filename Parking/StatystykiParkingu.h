#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;
using namespace std;

class StatystykiParkingu : Drawable
{
	Text sr_masa_txt, sr_konie_mechaniczne_txt, sr_predkosc_txt, sr_zurzycie_benzyny_txt;
	 vector<Text*> lista_tekstow;  // lsita wskaznikow do tekstow jakie bedziemu uzywac, 
	// jest tylko po to aby w szybki sposob miec dostep do wszystkich tekstow.

public:
	StatystykiParkingu(Vector2i polozenie, int odstep_y) // gdzie teksty maja byc umiejscowione i jaki odstep miedzy nimi w osi y
	{
		lista_tekstow =  vector<Text*>(5);
		sr_masa_txt.setPosition(polozenie.x, polozenie.y);
		sr_masa_txt.setPosition(polozenie.x, polozenie.y);
	}

	void uaktualnij(int masa, int konie_mech, int predkosc, int zurzyc_benz)
	{
		sr_masa_txt.setString("Sr. masa:       " + to_string(predkosc));
		sr_predkosc_txt.setString("Sr. predkosc:   " + to_string(predkosc));
		sr_konie_mechaniczne_txt.setString("Sr. km:         " + to_string(konie_mech));
		sr_zurzycie_benzyny_txt.setString("Sr. zurz. benz. " + to_string(zurzyc_benz));
	}

	void draw(RenderTarget & target, RenderStates state) const
	{
		for (size_t i = 0; i < lista_tekstow.size(); i++)
		{
			target.draw(*lista_tekstow[i]);
		}
	}
};

