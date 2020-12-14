#include <iostream>
#include <fstream>
#include <algorithm>
#include "ListaJednokierunkowa.h"
#include "ParametrySamochodu.h"
#include "funkcje.h"
#include "Samochod.h"
#include "Osobowy.h"
#include "Dostawczy.h"
#include "Ciezarowy.h"
#include "Autobus.h"

using namespace std;

int main()
{
	int wybor, wybor2, wybor3, typAuta;
	ListaJednokierunkowa* myList = new ListaJednokierunkowa;
	Samochod* wskaznikPolimorficzny = nullptr;
	Samochod* samochodKlienta = nullptr;
	do
	{
		menu();
		wybor = czyToInt();
		switch (wybor)
		{
		case 1:
			rodzajSamochodu();
			wybor2 = czyToInt();
			switch (wybor2)
			{
			case 1:
				wskaznikPolimorficzny = new Osobowy;
				wskaznikPolimorficzny->kupSamochod();
				myList->dodajDoListy(wskaznikPolimorficzny);
				break;
			case 2:
				wskaznikPolimorficzny = new Dostawczy;
				wskaznikPolimorficzny->kupSamochod();
				myList->dodajDoListy(wskaznikPolimorficzny);
				break;
			case 3:
				wskaznikPolimorficzny = new Ciezarowy;
				wskaznikPolimorficzny->kupSamochod();
				myList->dodajDoListy(wskaznikPolimorficzny);
				break;
			case 4:
				wskaznikPolimorficzny = new Autobus;
				wskaznikPolimorficzny->kupSamochod();
				myList->dodajDoListy(wskaznikPolimorficzny);
				break;
			default:
				cout << "Nie ma takiego typu auta, wychodzisz do menu" << endl << endl;
				break;
			}
			break;
		case 2:
			//sprzedaj
			cout << "Podaj numer pojazdu ktory chcesz sprzedac: " << endl;
			int pojazdDoSprzedazy;
			cin >> pojazdDoSprzedazy;
			myList->sprzedajSamochodZListy(pojazdDoSprzedazy);
			break;
		case 3:
			//wykup od klienta w rozliczeniu rozliczenie
			cout << "Ktore auto jako klient chcesz odkupic od salonu, podaj numer: " << endl;
			wybor3 = czyToInt();
			cout << "Jaki typ auta chcesz oddac do salonu? (1.Osobowy 2.Dostawczy 3.Ciezarowy 4.Autobus) " << endl;
			do
			{
				typAuta = czyToInt();
				switch (typAuta)
				{
				case 1:
					samochodKlienta = new Osobowy;
					myList->kupSamochodOdKlientaWRozliczeniu(wybor3, samochodKlienta);
					break;
				case 2:
					samochodKlienta = new Dostawczy;
					myList->kupSamochodOdKlientaWRozliczeniu(wybor3, samochodKlienta);
					break;
				case 3:
					samochodKlienta = new Ciezarowy;
					myList->kupSamochodOdKlientaWRozliczeniu(wybor3, samochodKlienta);
					break;
				case 4:
					samochodKlienta = new Autobus;
					myList->kupSamochodOdKlientaWRozliczeniu(wybor3, samochodKlienta);
					break;
				default:
					cout << "Podaj wlasciwy numer auta!" << endl;
					break;
				}
			} while (typAuta != 1 && typAuta != 2 && typAuta != 3 && typAuta != 4);
			if (myList->kupSamochodOdKlientaWRozliczeniu(wybor3, samochodKlienta) == 0)
			{
				cout << "W salonie nie ma pojazdu o tym numerze!\n";
				delete samochodKlienta;
			}
			break;
		case 4:
			//wyswietl flote
			cout << "Dostepna flota pojazdow: " << endl;
			myList->pokazListeSamochodow();
			break;
		case 5:
			myList->zapiszDoPlikuListeSamochodow();
			break;
		case 6:
			myList->sortowanieWedlugCeny();
			break;
		case 7:
			cout << "Wychodzisz z salonu" << endl;
			break;
		default:
			cout << "Nie ma takiego wyboru. Wybierz jeszcze raz" << endl << endl;
			break;
		}
	} while (wybor != 7);
	cout << endl;
	SytuacjaFinansowaSalonu(wskaznikPolimorficzny->podstawoweParametry.saldoSalonu);
	delete myList;
	return 0;
}