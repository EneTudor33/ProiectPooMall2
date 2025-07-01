#pragma once
#include "produs.h"
#include<string>
class Haina :public Produs {
private:
	std::string m_gen;
	std::string m_marime;
	std::string m_material;
public:
	Haina(std::string denumire, double pret, int cantitate, std::string gen, std::string marime,
		std::string material);
	std::string GetGen() const;
	std::string GetMarime() const;
	std::string GetMaterial() const;
	double PretUnitate() const override;
};