#pragma once
#include <iostream>
using namespace std;

// funkcja ma za zadanie sprawdzac czy uzytkownik wprowadzil poprawne dane
static int sprawdz_poprawnosc_wyboru(int min, int max)
{
	int wybor;

	// wprowdzamy dane dopoki sa one bledne
	while (true)
	{
		cin >> wybor;

		if (wybor < min || wybor > max)
			cout << "Wprowadzono bledne dane, sprobuj jeszcze raz" << endl;
		else
			return wybor;
	}
}

