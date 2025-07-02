#pragma once
#include "produs.h"
class Gadget :public Produs {
private:
	int m_baterie;
	int m_memorie;
	int m_garantie;
public:
	Gadget(std::string denumire, double pret, int baterie, int memorie,
		int garantie);
	int GetBaterie() const;
	int GetMemorie() const;
	int GetGarantie() const;
	double PretUnitate() const override;
	bool EsteReturnabil() const override;
};
