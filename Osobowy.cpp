#include "Osobowy.h"
#include "funkcje.h"
#include <fstream>

void Osobowy:: kupSamochod() 
{
	Samochod::kupSamochod();
	cout << "Ilosc drzwi: "; iloscDrzwi = czyToInt();
	cout << "Jaka jest wielkosc bagaznika(w litrach)?: "; wielkoscBagaznika = czyToInt();
	cout << "Czy auto posiada fotelik dla dziecka?: "; cin >> fotelikDlaDziecka;
	cout << endl;
}

void Osobowy:: pokazDane()	
{
	Samochod::pokazDane();
	cout << "Ilosc drzwi: " << iloscDrzwi << endl;
	cout << "Wielkosc bagaznika(w litrach): " << wielkoscBagaznika << endl;
	cout << "Fotelik dla dziecka: " << fotelikDlaDziecka << endl << endl;
}

void Osobowy:: sprzedajSamochod()
{
	Samochod::sprzedajSamochod();
}

void Osobowy:: zapiszDaneDoPliku(fstream& plik)	
{
	Samochod::zapiszDaneDoPliku(plik);
	plik << "Ilosc drzwi: " << iloscDrzwi << endl;
	plik << "Wielkosc Bagaznika(w litrach): " << wielkoscBagaznika << endl;
	plik << "Fotelik dla dziecka: " << fotelikDlaDziecka << endl << endl;
}

Samochod* Osobowy:: klonuj() const
{
	return new Osobowy(*this);
}