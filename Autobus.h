#pragma once
#include "Samochod.h"


class Autobus :public Samochod
{
public:
	int miejscaStojace = 0, miejscaSiedzace = 0;
	string przewozOsobNiepelnosprawnych;

	virtual void kupSamochod() override;

	virtual void pokazDane() override;

	virtual void sprzedajSamochod() override;

	virtual void zapiszDaneDoPliku(fstream& plik) override;

	Samochod* klonuj() const;
};