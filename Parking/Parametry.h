#pragma once

// kazdy samochod bedzie miec parametry ktore bedziemy statystycznie pokazywac na parkingu.
class Parametry
{
	int masa;
	int konie_mechaniczne;
	int predkosc;
	float zurzycie_benzyny;

public:
	Parametry(int prednosc, float zurzycie_benzyny, int konie_mechaniczne) : predkosc(predkosc), zurzycie_benzyny(zurzycie_benzyny), konie_mechaniczne(konie_mechaniczne) {};
};

