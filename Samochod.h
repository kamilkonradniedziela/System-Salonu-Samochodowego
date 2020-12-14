#pragma once
#include "ParametrySamochodu.h"
#include "Data.h"

class Samochod
{
public:
	ParametrySamochodu podstawoweParametry;
	Data aktualnaData = {};
	Samochod* next = nullptr;

	virtual void kupSamochod();

	virtual void sprzedajSamochod();

	virtual void pokazDane();

	virtual void zapiszDaneDoPliku(fstream& plik);

	virtual ~Samochod();

	virtual Samochod* klonuj()const;

	//Sortowanie od najtanszego
	bool operator< (const Samochod& o) const;

	//sortowanie od najdrozszego
	bool operator> (const Samochod& o) const;
};