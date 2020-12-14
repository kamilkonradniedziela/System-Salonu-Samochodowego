#include <fstream>
#include "Autobus.h"
#include "funkcje.h"

void Autobus:: kupSamochod() 
{
	Samochod::kupSamochod();
	cout << "Ile miejsc stojacych posiada autobus?: "; miejscaStojace = czyToInt();
	cout << "Ile miejsc siedzacych posiada autobus?: "; miejscaSiedzace = czyToInt();
	cout << "Czy autobus przystosowany jest do przewozu osob niepelnosprawnych?: "; cin >> przewozOsobNiepelnosprawnych;
	cout << endl;

}

void Autobus::pokazDane() 	
{
	Samochod::pokazDane();
	cout << "Ilosc miejsc stojacych: "; cout << miejscaStojace << endl;
	cout << "Ilosc miejsc siedzacych: "; cout << miejscaSiedzace << endl;
	cout << "Przystosowanie do przewozu osob niepelnosprawnych?: "; cout << przewozOsobNiepelnosprawnych << endl << endl;
}

void Autobus::sprzedajSamochod()
{
	Samochod::sprzedajSamochod();
}

void Autobus::zapiszDaneDoPliku(fstream& plik)
{
	Samochod::zapiszDaneDoPliku(plik);
	plik << "Ilosc miejsc stojacych: " << miejscaStojace << endl;
	plik << "Ilosc miejsc siedzacych: " << miejscaSiedzace << endl;
	plik << "Przystosowanie do przewozu osob niepelnosprawnych?: " << przewozOsobNiepelnosprawnych << endl << endl;
}

Samochod* Autobus::klonuj() const
{
	return new Autobus(*this);
}