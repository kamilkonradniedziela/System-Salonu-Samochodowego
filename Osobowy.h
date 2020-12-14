#pragma once
#include "Samochod.h"

class Osobowy : public Samochod
{
public:
	int iloscDrzwi = 0;
	float wielkoscBagaznika = 0;
	string fotelikDlaDziecka = "";

	virtual void kupSamochod() override;

	virtual void pokazDane() override;

	virtual void sprzedajSamochod() override;

	virtual void zapiszDaneDoPliku(fstream& plik) override;

	virtual Samochod* klonuj() const;
};