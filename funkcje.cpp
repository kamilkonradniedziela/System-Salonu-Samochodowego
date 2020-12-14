#include <iostream>
#include "funkcje.h"

using namespace std;

void menu()
{
	puts("Witaj w systemie salonu samochodowego!\n"
		"Wybierz opcje:\n"
		"1.Kup samochod\n"
		"2.Sprzedaj samochod\n"
		"3.Wykup samochod od klienta w rozliczeniu\n"
		"4.Wyswietl obecne auta w salonie\n"
		"5.Zapisz obecna flote do pliku\n"
		"6.Sortuj liste pojazdow wzgledem ceny\n"
		"7.Zamknij salon\n"
		"Wybor: ");
}

void rodzajSamochodu()
{
	puts("Podaj przeznaczenie pojazdu: \n"
		"1.Osobowy\n"
		"2.Dostawczy\n"
		"3.Ciezarowy\n"
		"4.Autobus\n"
		"Wybor: ");
}

void SytuacjaFinansowaSalonu(int liczba)
{
	cout << "AKTUALNY BUDZET SALONU: " << liczba << endl;
	if (liczba < 0)
	{

		cout << "Przykro mi, zostawiasz salon z dlugami :(" << endl;
	}
	if (liczba == 0)
	{
		cout << "Budzet salonu wynosi zero" << endl;
	}
	if (liczba > 0)
	{
		cout << "Gratulacje! Doprowadziles do wzrostu salda konta salonu!" << endl;
	}
}

int czyToInt()
{
	int czyInt;
	while (!(cin >> czyInt))
	{
		cout << "Niepoprawny format liczby!\nPodaj liczbe jeszcze raz: ";
		cin.clear();
		cin.ignore(1000, '\n');
	}
	return czyInt;
}
