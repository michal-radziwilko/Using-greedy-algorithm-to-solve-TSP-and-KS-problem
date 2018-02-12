#include "Przedmiot.h"
#include <iostream>
#include <random>
#include <queue>

using namespace std;


Przedmiot::Przedmiot(int pojem, int liczbaPrzedm)
{
	pojemnosc = pojem;
	liczbaPrzedmiotow = liczbaPrzedm;
	przedmioty = new przedmiot [liczbaPrzedmiotow];

}


Przedmiot::~Przedmiot()
{
	delete[] przedmioty;
	delete[] plecak;
}

void Przedmiot::losowePrzedmioty()
{
	random_device rd; // non-deterministic generator
	mt19937 gen(rd()); // random engine seeded with rd()
	uniform_int_distribution<> dist(0, 50); // distribute results between
													// 1 and 50 inclusive


	cout << "Podaj ilosc przedmiotow do utworzenia: ";
	cin >> liczbaPrzedmiotow;


	przedmioty = new przedmiot [liczbaPrzedmiotow];
	przedmiot a;

	for (int i = 0; i < liczbaPrzedmiotow; i++)
	{
		
		a.waga = dist(gen);
		a.wartosc = dist(gen);
		przedmioty[i] = a;

	}
}

void Przedmiot::wyswietlPrzedmioty()
{
	cout << endl << "Wszystkie przedmioty: " << endl << endl <<
		"          Pojemnosc plecaka: " << pojemnosc << endl <<
		"          Liczzba wszystkich przedmiotow: " << liczbaPrzedmiotow << endl << endl;
	for (int i = 0; i < liczbaPrzedmiotow; i++)
	{
		cout << "          " << i <<": " << "waga: " << przedmioty[i].waga << "  wartosc: " << przedmioty[i].wartosc << endl;
	}
	cout << endl;
}

void Przedmiot::plecakowyWartosc()
{
	cout << endl << "Problem plecakowy, algorytm zachlanny (wartosc): " << endl;

	typedef std::priority_queue < przedmiot, std::vector < przedmiot >, porownajPrzedmioty > TKolejkaPriorytetowaPrzedmiotow;

	TKolejkaPriorytetowaPrzedmiotow Q;

	przedmiot p;

	// wrzucamy wszystkie przedmioty do kolejki priorytetowej sortuj¹c wed³ug wartoœci
	for (int i = 0; i < liczbaPrzedmiotow; i++)
	{

		Q.push(przedmioty[i]);
	}

	for (int i = 0; i < liczbaPrzedmiotow; i++)
	{
		p = Q.top();
		if (WagaPlecaka + p.waga < pojemnosc)
		{
			relokujPlecak();
			plecak[rozmiarPlecaka - 1] = p;

			WartoscPlecaka = WartoscPlecaka + p.wartosc;
			WagaPlecaka = WagaPlecaka + p.waga;
		}
		Q.pop();
	}

}

void Przedmiot::relokujPlecak()
{

		przedmiot *b = new przedmiot [rozmiarPlecaka + 1];
		for (int i = 0; i < rozmiarPlecaka; i++)
		{
			b[i] = plecak[i];
		}
		if (rozmiarPlecaka > 0)
		delete[] plecak;
		plecak = b;
		rozmiarPlecaka++;

}

void Przedmiot::wyswietlPlecak()
{

	if (rozmiarPlecaka > 0)
	{
		cout << endl << endl << "          Zawartosc plecaka: " << endl << endl;
		cout << endl << "          Pojemnosc: " << pojemnosc << endl;
		cout << endl << "          Przedmiotow: " << rozmiarPlecaka << endl << endl;

		for (int i = 0; i < rozmiarPlecaka; i++)
		{
			cout << "          " << i << ": " << "waga: " << plecak[i].waga << "  wartosc: " << plecak[i].wartosc << endl;
		}
		cout << endl << "          W sumie:" << endl;
		cout << endl << "          Wartosc: " << WartoscPlecaka << endl;
		cout << endl << "          Waga: " << WagaPlecaka << endl << endl;
	}

	else if (rozmiarPlecaka == 0) cout << endl << endl << "          Plecak jest pusty!" << endl << endl;
}

void Przedmiot::plecakowyIloraz()
{
	cout << endl << "Problem plecakowy, algorytm zachlanny (wartosc / waga): " << endl;

	rozmiarPlecaka = 0, WagaPlecaka = 0, WartoscPlecaka = 0;

	typedef std::priority_queue < przedmiot, std::vector < przedmiot >, porownajIloczyny > TKolejkaPriorytetowaPrzedmiotow;

	TKolejkaPriorytetowaPrzedmiotow Q;

	przedmiot p;

	// wrzucamy wszystkie przedmioty do kolejki priorytetowej sortuj¹c wed³ug wartoœci
	for (int i = 0; i < liczbaPrzedmiotow; i++)
	{

		Q.push(przedmioty[i]);
	}

	for (int i = 0; i < liczbaPrzedmiotow; i++)
	{
		p = Q.top();
		if (WagaPlecaka + p.waga < pojemnosc)
		{
			relokujPlecak();
			plecak[rozmiarPlecaka - 1] = p;

			WartoscPlecaka = WartoscPlecaka + p.wartosc;
			WagaPlecaka = WagaPlecaka + p.waga;
		}
		Q.pop();
	}

}