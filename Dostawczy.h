#pragma once
#include "Samochod.h"


class Dostawczy : public Samochod
{
public:
	int dozwolonaMasaWlasnaKatB = 0;
	string kurnik;

	virtual void kupSamochod() override;

	virtual void pokazDane() override;

	virtual void sprzedajSamochod() override;

	virtual void zapiszDaneDoPliku(fstream& plik) override;

	Samochod* klonuj() const;
};