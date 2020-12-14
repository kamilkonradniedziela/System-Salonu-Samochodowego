#pragma once

using namespace std;

class Data
{
private:
	int dzien;
	int miesiac;
	int rok;

public:
	void pobierzDate();

	void wyswietlDate();

	void zapiszDateDoPliku(fstream& plik);
};