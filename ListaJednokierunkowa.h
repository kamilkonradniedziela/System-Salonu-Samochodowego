#pragma once
#include "Samochod.h"

class ListaJednokierunkowa
{
public:
	Samochod* first = nullptr;
	int licznikPojazdow = 0;

	ListaJednokierunkowa() ;

	void dodajDoListy(Samochod* s);

	void pokazListeSamochodow();

	void zapiszDoPlikuListeSamochodow();

	void sprzedajSamochodZListy(int pozycjaNaLiscie);

	bool kupSamochodOdKlientaWRozliczeniu(int wybor, Samochod* samochodKlient);

	void zwolnijPamiec();

	void sortowanieWedlugCeny();

	~ListaJednokierunkowa();

	// konstruktor kopiuj¹cy
	ListaJednokierunkowa(const ListaJednokierunkowa& list);

	//operator przypisania
	ListaJednokierunkowa& operator=(ListaJednokierunkowa list);

};