#pragma once
#include "magazin.h"
#include<vector>
#include"mancare.h"
#include"bautura.h"
class MagazinMancare :virtual public Magazin {
protected:
	std::vector<Mancare> m_catalog_mancare;//daca e pe meniu nu inseamna ca e si pe stoc
	std::vector<Bautura> m_catalog_bauturi;
public:
	MagazinMancare(std::string nume, int etaj, bool e_deschis);
	std::vector<Mancare> GetCatalogMancare() const;
	void Print(std::ostream& os) const override;
	virtual int Tip() const override;
	virtual void AdaugaProdus() override;
	virtual void AfiseazaCatalog() override;
};