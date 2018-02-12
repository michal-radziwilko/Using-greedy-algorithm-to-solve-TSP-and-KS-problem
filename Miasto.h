#pragma once
class Miasto
{
public:
	Miasto(int lMiast);
	~Miasto();
	void komiwojazer();
	void losoweMiasta();
	void wyswietlMiasta();
	void wyswietlTrase();
	struct miasto
	{
		int m1, m2, d;
	};
	struct porownajDrogi
	{
		bool operator ()(const miasto & droga1, const miasto & droga2)
		{
			//kolejnoœæ - rosn¹co
			if (droga1.d > droga2.d) return true;

			if (droga1.d < droga2.d) return false;

			return false;
		}
	};
	int **miasta, *trasa;


private:
	int liczbaMiast = 0, dlugoscTrasy = 0;
};

