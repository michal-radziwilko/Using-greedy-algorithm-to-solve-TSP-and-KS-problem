#include "Przedmiot.h"
#include "Miasto.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{

	int wybor;

	Przedmiot *przedmiot;
	Miasto *miasto;

etykieta:

	cout << endl << endl << "          MENU" << endl << endl <<
		"          1. Dyskretny problem plecakowy" << endl <<
		"          2. Asymetryczny problem komiwojazera" << endl <<
		"          3. Zakoncz dzialanie programu" << endl << endl <<
		"          Wybierz opcje: ";
	cin >> wybor;

	switch (wybor)
	{

	case 1:
	{
		string nazwa;
		int pojemnosc, liczbaPrzedmiotow, waga, wartosc, i = 0;

		cout << endl << "          Podaj nazwe pliku do wczytania danych: ";
		cin >> nazwa;
		nazwa = nazwa + ".txt";
		ifstream plecak(nazwa);
		if (!plecak)
		{
			cout << endl << "          Nie mozna otworzyc pliku" << endl;
			goto etykieta;

		}

		else
		{

			plecak >> pojemnosc >> liczbaPrzedmiotow;

			przedmiot = new Przedmiot(pojemnosc, liczbaPrzedmiotow);
			Przedmiot::przedmiot a;

			while (!plecak.eof())
			{

				plecak >> waga >> wartosc;

				a.waga = waga;
				a.wartosc = wartosc;
				przedmiot->przedmioty[i] = a;
				i++;
			}

		}

		plecak.close();

		cout << endl << "          Wczytano dane." << endl << endl;


		przedmiot->wyswietlPrzedmioty();

		przedmiot->plecakowyWartosc();
		przedmiot->wyswietlPlecak();

		przedmiot->plecakowyIloraz();
		przedmiot->wyswietlPlecak();

		//Miasto *miasto = new Miasto(10);

		//miasto->losoweMiasta();
		//miasto->wyswietlMiasta();

		//miasto->komiwojazer();
		//miasto->wyswietlTrase();
	} goto etykieta;

	case 2:
	{
		string nazwa;
		int liczbaMiast, droga, i = 0, j = 0;

		cout << endl << "          Podaj nazwe pliku do wczytania danych: ";
		cin >> nazwa;
		nazwa = nazwa + ".txt";


		ifstream komi(nazwa);
		if (!komi)
		{
			cout << endl << "          Nie mozna otworzyc pliku" << endl;
			goto etykieta;

		}

		else
		{

			komi >> liczbaMiast;

			miasto = new Miasto(liczbaMiast);

			for (int i = 0; i < liczbaMiast; i++)
			{
				for (int j = 0; j < liczbaMiast; j++)
				{

					if (!komi.eof())
					{
						komi >> droga;
						miasto->miasta[i][j] = droga;
					}
				}
			}
		}

		komi.close();

		cout << endl << "          Wczytano dane." << endl << endl;


		miasto->wyswietlMiasta();

		miasto->komiwojazer();
		miasto->wyswietlTrase();
	} goto etykieta;

	case 3:
	{
		cout << endl << endl << "          ZAKONCZONO DZIALANIE PROGRAMU" << endl << endl;
		return(0);

	};

}
	return(0);
}