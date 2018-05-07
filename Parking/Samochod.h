#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


class Samochod
{
	string model;
	int rok;

	Texture tekstura;
	Sprite sprite;

public:
	Samochod() {}
	Samochod(string model, int rok) : model(model), rok(rok){};

	//friend ostream & operator<<(ostream & ekran, Samochod & samochod)
	//{
	//	cout << nazwa << " " << model;
	//}

};

