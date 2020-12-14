#include "Samochod.h"
#include "funkcje.h"
#include <string>
#include <fstream>

void Samochod:: kupSamochod()
{
	aktualnaData.pobierzDate();
	cout << "Wprowadz dane pojazdu: " << endl;
	cout << "Marka: "; getline(cin>>ws,podstawoweParametry.marka);
	cout << "Model: "; cin >> podstawoweParametry.model;
	cout << "Cena(PLN): "; podstawoweParametry.cena = czyToInt();
	cout << "Rok produkcji: "; podstawoweParametry.rokProdukcji = czyToInt();
	cout << "Pojemnosc(w CM^3): "; podstawoweParametry.pojemnosc = czyToInt();
	cout << "Przebieg(w km): "; podstawoweParametry.przebieg = czyToInt();
	cout << "Moc(w KM): "; podstawoweParametry.moc = czyToInt();
	podstawoweParametry.saldoSalonu -= podstawoweParametry.cena;
}

void Samochod:: sprzedajSamochod()
{
	podstawoweParametry.saldoSalonu += podstawoweParametry.cena;
}

void Samochod:: pokazDane()	
{
	aktualnaData.wyswietlDate();
	cout << "Marka: " << podstawoweParametry.marka << endl;
	cout << "Model: " << podstawoweParametry.model << endl;
	cout << "Cena: " << podstawoweParametry.cena <<" PLN" << endl;
	cout << "Rok produkcji: " << podstawoweParametry.rokProdukcji << endl;
	cout << "Pojemnosc: " << podstawoweParametry.pojemnosc<<" CM^3" << endl;
	cout << "Przebieg: " << podstawoweParametry.przebieg <<" km" << endl;
	cout << "Moc: " << podstawoweParametry.moc <<" KM"<< endl;
}

void Samochod:: zapiszDaneDoPliku(fstream& plik)	//const
{
	aktualnaData.zapiszDateDoPliku(plik);
	plik << "Marka: " << podstawoweParametry.marka << endl;
	plik << "Model: " << podstawoweParametry.model << endl;
	plik << "Cena: " << podstawoweParametry.cena <<" PLN"<< endl;
	plik << "Rok produkcji: " << podstawoweParametry.rokProdukcji << endl;
	plik << "Pojemnosc: " << podstawoweParametry.pojemnosc <<" CM^3"<< endl;
	plik << "Przebieg: " << podstawoweParametry.przebieg <<" km"<< endl;
	plik << "Moc: " << podstawoweParametry.moc <<" KM"<< endl;
}

Samochod:: ~Samochod() {};

Samochod* Samochod:: klonuj()const
{
	return new Samochod(*this);
};

//Sortowanie od najtanszego
bool Samochod:: operator< (const Samochod& o) const
{
	return podstawoweParametry.cena < o.podstawoweParametry.cena;
}

//sortowanie od najdrozszego
bool Samochod:: operator> (const Samochod& o) const
{
	return podstawoweParametry.cena > o.podstawoweParametry.cena;
}