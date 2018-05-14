#include "Slot.h"

Slot::Slot() { };

Slot::Slot(int x, int y)  // okreslamy pozycje umieszczenia slotu na ekranie
	:zajety(false), samochod(Samochod()), przycisk(Przycisk("puste", IntRect(x, y, 100, 100), true)) {}


void Slot::zaparkuj(Samochod samochod)
{
	cout << "Parkuje na slocie " << endl;
	zajety = true;
	this->samochod = samochod;
	Texture * tekstura_samochodu = this->samochod.pobierz_teksture();
	przycisk.ustaw_wcisnieta_teksture(tekstura_samochodu);
}

void Slot::wyparkuj()
{
	cout << "slot wolny";
	zajety = false;
	przycisk.przywroc_domyslna_teksture();
}

void Slot::draw(RenderTarget & target, RenderStates states) const
{
	target.draw(przycisk, states);
}

bool Slot::czy_zajety()
{
	return zajety;
}

Przycisk * Slot::pobierz_przycisk()
{
	return &przycisk;
}

Samochod * Slot::pobierz_samochod()
{
	return &samochod;
}