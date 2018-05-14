#include "Samochod.h"

Samochod::Samochod() : marka("nieznana") {};  // domyslny konstruktor z lista inicjalizacyjna
Samochod::Samochod(string marka, Parametry parametry) : marka(marka), parametry(parametry) {};

Texture * Samochod::pobierz_teksture()
{
	return &tekstura;
}

Parametry Samochod::pobierz_parametry()
{
	return parametry;
}

// mozna tutaj wykonac przeciazenie operatora wczytania jak w klasie Parametr
// ale chcemy utworzyc jakas sensowna metode virtualna, ktora dla klas pochodnych bedzie wygladac troche inaczej
// po to aby zastosowac polimorfizm
void Samochod::stworz_samochod()
{
	cout << "Podaj marke samochodu: ";
	cin >> marka;
	cout << "Wprowadz Parametry" << endl;
	cin >> parametry;
}

