#pragma once
#include "magazin.h"
#include<vector>
#include"mancare.h"
class MagazinMancare :virtual public Magazin {
protected:
	std::vector<Mancare> m_catalog_mancare;//daca e pe meniu nu inseamna ca e si pe stoc
public:
	MagazinMancare(std::string nume, int etaj, bool e_deschis);
	std::vector<Mancare> GetCatalogMancare() const;
};