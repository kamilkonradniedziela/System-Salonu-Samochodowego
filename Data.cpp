#include <iostream>
#include <fstream>
#include "Data.h"
#include "funkcje.h"

using namespace std;

void Data::pobierzDate()
{
	cout << "Podaj date zakupu/sprzedazy samochodu: " << endl;
	cout << "Dzien: ";
	dzien = czyToInt();
	cout << "Miesiac: ";
	miesiac = czyToInt();
	cout << "Rok: ";
	rok = czyToInt();
}

void Data::wyswietlDate()
{
	cout << "Data kupna pojazdu przez salon: ";
	if (dzien < 10)
	{
		cout << '0';
	}
	cout << dzien << ".";

	if (miesiac < 10)
	{
		cout << "0";
	}
	cout << miesiac << ".";

	cout << rok << endl;
}

void Data::zapiszDateDoPliku(fstream& plik)
{
	plik << "Data kupna pojazdu przez salon: " << endl;
	plik << "Dzien: ";
	plik << dzien << endl;
	plik << "Miesiac: ";
	plik << miesiac << endl;
	plik << "Rok: ";
	plik << rok << endl;
}