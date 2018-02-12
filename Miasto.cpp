#include "Miasto.h"
#include <iostream>
#include <random>
#include <queue>

using namespace std;



Miasto::Miasto(int lMiast)
{
	liczbaMiast = lMiast;
	miasta = new int *[liczbaMiast];
	trasa = new int [liczbaMiast-1];

	for (int i = 0; i < liczbaMiast; i++)
	{
		miasta[i] = new int[liczbaMiast];
		for (int j = 0; j < liczbaMiast; j++)
		{
			miasta[i][j] = 0;
		}
	}
}


Miasto::~Miasto()
{
	for (int i = 0; i < liczbaMiast; i++)
		delete[] miasta[i];

	delete[] miasta;
	delete[] trasa;
}

void Miasto::losoweMiasta()
{
	random_device rd; // non-deterministic generator
	mt19937 gen(rd()); // random engine seeded with rd()
	uniform_int_distribution<> dist(1, 50); // distribute results between
											// 1 and 1000000 inclusive

	for (int i = 0; i < liczbaMiast; i++)
	{
		for (int j = 0; j < liczbaMiast; j++)
		{
			if(j!=i)
			miasta[i][j] = dist(gen);
		}
	}
}

void Miasto::wyswietlMiasta()
{
	cout << endl << "          Zbior odleglosci miedzy miastami: " << endl << endl;
	cout << "          Liczba miast: " << liczbaMiast << endl << endl;

	for (int i = 0; i < liczbaMiast; i++)
	{
		cout << "          " << i << ": ";
		for (int j = 0; j < liczbaMiast; j++)
		{
			cout << miasta[i][j] <<" | ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

void Miasto::komiwojazer()
{
	bool *odwiedzone = new bool [liczbaMiast];
	int aktualny = 0, licznik = 0;
	miasto m;

	typedef std::priority_queue < miasto, std::vector < miasto >, porownajDrogi > TKolejkaPriorytetowaMiast;

	TKolejkaPriorytetowaMiast Q;


		for (int i = 0; i < liczbaMiast; i++)
			odwiedzone[i] = false;

		while (licznik < liczbaMiast - 1)
		{
			odwiedzone[aktualny] = true;

			for (int i = 0; i < liczbaMiast; i++)
			{
				if (odwiedzone[i] == false && miasta[aktualny][i] != 0)
				{
					m.m1 = aktualny;
					m.m2 = i;
					m.d = miasta[aktualny][i];
					Q.push(m);
				}
			}

			if (!Q.empty())
			{
				m = Q.top();
				trasa[licznik] = m.m2;
				dlugoscTrasy = dlugoscTrasy + m.d;
				aktualny = trasa[licznik];
				licznik++;
			}

			while (!Q.empty()) Q.pop();
		}
		dlugoscTrasy = dlugoscTrasy + miasta[trasa[liczbaMiast-2]][0];
}

void Miasto::wyswietlTrase()
{
	cout << "          Dlugosc trasy: " << dlugoscTrasy << endl;
	cout << endl << "          Trasa: 0 - ";

	for (int i = 0; i < liczbaMiast - 1; i++)
	{
		cout << trasa[i] << " - ";
	}
	cout << "0" << endl << endl;
}