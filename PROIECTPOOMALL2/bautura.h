#pragma once
#include "produs.h"
class Bautura :public Produs {
private:
	double m_procentaj_alcool;
	int m_gramaj;
	bool m_este_pet;
public:
	double GetProcentajAlcool() const;
	Bautura(std::string denumire, double pret, int cantitate, double procentaj_alcool,
		int gramaj, bool este_pet);
	bool GetEstePet() const;
	int GetGramaj() const;
	double PretUnitate() const override;
};