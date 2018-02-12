#pragma once
class Przedmiot
{
public:
	Przedmiot(int pojemnosc, int liczbaPrzedmiotow);
	~Przedmiot();
	void losowePrzedmioty();
	struct przedmiot
	{
		int waga, wartosc;
	};
	void wyswietlPrzedmioty();
	void plecakowyWartosc();
	struct porownajPrzedmioty
	{
		bool operator ()(const przedmiot & wartosc1, const przedmiot & wartosc2)
		{
			//kolejnoœæ - malej¹co
			if (wartosc1.wartosc < wartosc2.wartosc) return true;

			if (wartosc1.wartosc > wartosc2.wartosc) return false;

			return false;
		}
	};
	struct porownajIloczyny
	{
		bool operator ()(const przedmiot & wartosc1, const przedmiot & wartosc2)
		{
			//kolejnoœæ - malej¹co
			if ((wartosc1.wartosc / wartosc1.waga) < (wartosc2.wartosc / wartosc2.waga)) return true;

			if ((wartosc1.wartosc / wartosc1.waga) > (wartosc2.wartosc / wartosc2.waga)) return false;

			return false;
		}
	};
	void relokujPlecak();
	void wyswietlPlecak();
	void plecakowyIloraz();
	przedmiot *przedmioty;
	przedmiot *plecak;

private:
	int pojemnosc, liczbaPrzedmiotow, rozmiarPlecaka = 0, WagaPlecaka = 0, WartoscPlecaka = 0;
};

