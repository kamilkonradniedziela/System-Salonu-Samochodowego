#include <fstream>
#include "Dostawczy.h"
#include "funkcje.h"

void Dostawczy::kupSamochod()
{
	Samochod::kupSamochod();
	cout << "Dozwolona masa wlasna(w tonach): "; dozwolonaMasaWlasnaKatB = czyToInt();
	cout << "Czy auto wyposazone jest w kurnik?: "; cin >> kurnik;
	cout << endl;
}

void Dostawczy::pokazDane()	
{
	Samochod::pokazDane();
	cout << "Dozwolona masa wlasna(w tonach): " << dozwolonaMasaWlasnaKatB << endl;
	cout << "Czy auto wyposazone jest w kurnik?: " << kurnik << endl << endl;
}

void Dostawczy::sprzedajSamochod()
{
	Samochod::sprzedajSamochod();
}

void Dostawczy::zapiszDaneDoPliku(fstream& plik)	
{
	Samochod::zapiszDaneDoPliku(plik);
	plik << "Dozwolona masa wlasna(w tonach): " << dozwolonaMasaWlasnaKatB << endl;
	plik << "Czy auto wyposazone jest w kurnik?: " << kurnik << endl << endl;
}

Samochod* Dostawczy::klonuj() const
{
	return new Dostawczy(*this);
}