#pragma once
#include "magazin.h"
#include<vector>
#include"mancare.h"
#include"bautura.h"
class MagazinMancare :virtual public Magazin {
protected:
	std::vector<Mancare> m_catalog_mancare;//daca e pe meniu nu inseamna ca e si pe stoc
	std::vector<Bautura> m_catalog_bauturi;
	std::vector<Bucatar> m_echipa_bucatari;
public:
	MagazinMancare(std::string nume, int etaj, bool e_deschis);
	std::vector<Mancare> GetCatalogMancare() const;
	void Print(std::ostream& os) const override;
	virtual int Tip() const override;
	virtual void AdaugaProdus() override;
	virtual void AfiseazaCatalog() override;
	virtual void AdaugaAngajat() override;
	virtual void AfiseazaAngajat() override;
	virtual void ModificaStoc(int id, int cantitate) override;
	virtual int GetStoc(int id) override;
	virtual double CalculValoareProduse() const override;
	virtual bool VindeProdus(int id_produs, int cantitate) override;
	virtual double GetPretProdus(int id) const override;
	virtual void AdaugaStoc(int id, int cantitate) override;
	virtual Produs* CautaProdus(int id) override;
};