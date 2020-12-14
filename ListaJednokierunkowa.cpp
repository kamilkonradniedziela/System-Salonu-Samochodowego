#include <fstream>
#include "ListaJednokierunkowa.h"
#include "Osobowy.h"
#include "Dostawczy.h"
#include "Ciezarowy.h"
#include "Autobus.h"

ListaJednokierunkowa::ListaJednokierunkowa() {};

void ListaJednokierunkowa::dodajDoListy(Samochod* s)
{
	if (first == nullptr)
	{
		licznikPojazdow++;
		first = s;
		return;
	}
	else
	{
		Samochod* p = first;
		licznikPojazdow++;
		while (p->next)
		{
			p = p->next;
		}
		p->next = s;
	}
}

void ListaJednokierunkowa:: pokazListeSamochodow()
{
	Samochod* temp = this->first;
	if (this->first == nullptr)
	{
		cout << "Nie masz zadnych aut!" << endl;
	}
	int i = 1;
	while (temp != nullptr)
	{
		cout << "Pojazd nr: " << i++ << "\n";
		temp->pokazDane();
		temp = temp->next;
	}
	cout << "AKTUALNY BUDZET SALONU: " << temp->podstawoweParametry.saldoSalonu << endl << endl;
}

void ListaJednokierunkowa::zapiszDoPlikuListeSamochodow()
{
	fstream plik;
	plik.open("ListaSamochodow.txt", ios::out);
	if (plik.is_open() == false)
	{
		cout << "Niestety, nie udalo sie otworzyc pliku" << endl << endl;
		return;
	}
	else
	{
		Samochod* temp = this->first;
		if (this->first == nullptr)
		{
			cout << "Nie masz zadnych aut, program zapisze pusty plik!" << endl << endl;
			return;
		}
		int i = 1;
		while (temp != nullptr)
		{
			plik << "Pojazd nr: " << i++ << "\n";
			temp->zapiszDaneDoPliku(plik);
			plik << endl;
			temp = temp->next;
		}
		plik << "AKTUALNY BUDZET SALONU: " << temp->podstawoweParametry.saldoSalonu << endl << endl;
		cout << "Pomyslnie zapisano do pliku!" << endl << endl;
		plik.close();
	}
}

void ListaJednokierunkowa::sprzedajSamochodZListy(int pozycjaNaLiscie)
{
	Samochod* temp = first;
	Samochod* before = nullptr;

	while (temp && --pozycjaNaLiscie > 0)
	{
		before = temp;
		temp = temp->next;
	}

	if (!temp)
	{
		cout << "Nie ma pojazdu o tym numerze!\n";
		return;
	}

	temp->sprzedajSamochod();

	if (before)
	{
		before->next = temp->next;
	}
	else
	{
		first = temp->next;
	}

	delete temp;
}

bool ListaJednokierunkowa::kupSamochodOdKlientaWRozliczeniu(int wybor, Samochod* samochodKlient)
{
	Samochod* temp = first;
	Samochod* before = nullptr;

	while (temp && --wybor > 0)
	{
		before = temp;
		temp = temp->next;// dla usuniecia np. jednego elementu to nie bedzie wskazywac na nic
	}

	if (!temp)
	{
		return false;
	}

	temp->sprzedajSamochod();
	temp->podstawoweParametry.saldoSalonu += temp->podstawoweParametry.cena;

	samochodKlient->kupSamochod();

	if (before)
	{
		before->next = samochodKlient;
		samochodKlient->next = temp->next;
	}
	else
	{
		samochodKlient->next = temp->next;	
		first = samochodKlient;
	}

	delete temp;
	return true;
}

void ListaJednokierunkowa::zwolnijPamiec()
{
	Samochod* temp = first;
	while (temp)
	{
		auto p = temp->next;
		delete temp;
		temp = p;
	}
	first = nullptr;
}

void ListaJednokierunkowa::sortowanieWedlugCeny()
{
	if (first == nullptr)
	{
		cout << "Lista pojazdow jest pusta wiec danych nie da sie posortowac!" << endl << endl;
		return;
	}

	int wybor;
	auto comp = &Samochod::operator<;
	cout << "Jak chcesz posortowac liste?(1.Rosnaco 2.Malejaco):" << endl;
	cin >> wybor;
	do
	{
		switch (wybor)
		{
		case 1:
			comp = &Samochod::operator<;
			break;
		case 2:
			comp = &Samochod::operator>;//od najdrozszego
			break;
		default:
			cout << "Nie ma takiego sortowania! Wybierz jeszcze raz" << endl;
			break;
		}
	} while (wybor != 1 && wybor != 2);

	Samochod* last = nullptr;

	while (last != first)
	{
		Samochod* prev = nullptr;
		Samochod* p = first;
		Samochod* next = p ? p->next : nullptr;

		while (next != last)
		{
			if ((next->*comp)(*p))
			{
				if (prev)
				{
					prev->next = next;
					p->next = next->next;
					next->next = p;
					p = next;
				}
				else
				{
					first = next;
					p->next = next->next;
					next->next = p;
					p = next;
				}
			}

			prev = p;
			p = next;
			next = next->next;
		}

		last = p;
	}
	cout << "Sortowanie przebieglo pomyslnie!" << endl << endl;
}

ListaJednokierunkowa::~ListaJednokierunkowa()
{
	zwolnijPamiec();
}

// konstruktor kopiuj¹cy
ListaJednokierunkowa::ListaJednokierunkowa(const ListaJednokierunkowa& list) : first(nullptr)
{
	if (!list.first)
	{
		return;
	}

	first = list.first->klonuj();
	Samochod* prev = first;
	Samochod* tmp = list.first->next;

	while (tmp)
	{
		prev->next = tmp->klonuj();
		prev = prev->next;
		tmp = tmp->next;
	}
}

//operator przypisania
ListaJednokierunkowa& ListaJednokierunkowa:: operator=(ListaJednokierunkowa list)
{
	swap(first, list.first);
	return *this;
}