#pragma once
#include "Samochod.h"


class Ciezarowy :public Samochod
{
public:
	float dopuszczalnaDlugoscNaczepy = 0;
	int iloscNaczep = 0;
	string zimoweLancuchyNaKola;

	virtual void kupSamochod() override;

	virtual void pokazDane() override;

	virtual void sprzedajSamochod() override;

	virtual void zapiszDaneDoPliku(fstream& plik) override;

	Samochod* klonuj() const;
};