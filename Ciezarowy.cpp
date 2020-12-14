#include <fstream>
#include "Ciezarowy.h"
#include "funkcje.h"

void Ciezarowy:: kupSamochod()
{
	Samochod::kupSamochod();
	cout << "Jaka dlugosc naczepy jest dozwolona w pojezdzie(w metrach)?: "; dopuszczalnaDlugoscNaczepy = czyToInt();
	cout << "Jaka jest maksymalna dopuszczalna ilosc naczep?: "; iloscNaczep = czyToInt();
	cout << "Czy ciezarowka posiada zimowe lancuchy na kola?: "; cin >> zimoweLancuchyNaKola;
	cout << endl;

}

void Ciezarowy::pokazDane() 	
{
	Samochod::pokazDane();
	cout << "Maksymalna dlugosc naczepy dozwolona w pojezdzie(w metrach): "; cout << dopuszczalnaDlugoscNaczepy << endl;
	cout << "Maksymalna dopuszczalna ilosc naczep: "; cout << iloscNaczep << endl;
	cout << "Zimowe lancuchy na kola w wyposazeniu: "; cout << zimoweLancuchyNaKola << endl << endl;
}

void Ciezarowy::sprzedajSamochod() 
{
	Samochod::sprzedajSamochod();
}

void Ciezarowy::zapiszDaneDoPliku(fstream& plik)	
{
	Samochod::zapiszDaneDoPliku(plik);
	plik << "Maksymalna dlugosc naczepy dozwolona w pojezdzie(w metrach): " << dopuszczalnaDlugoscNaczepy << endl;
	plik << "Maksymalna dopuszczalna ilosc naczep: " << iloscNaczep << endl;
	plik << "Zimowe lancuchy na kola w wyposazeniu: " << zimoweLancuchyNaKola << endl << endl;
}

Samochod* Ciezarowy::klonuj() const
{
	return new Ciezarowy(*this);
}