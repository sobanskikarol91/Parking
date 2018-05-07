#pragma once
#include <iostream>
using namespace std;


class Samochod
{
	string model;
	string nazwa;

public:
	Samochod(string nazwa, string model) : nazwa(nazwa), model(model) {};

	//friend ostream & operator<<(ostream & ekran, Samochod & samochod)
	//{
	//	cout << nazwa << " " << model;
	//}

};

