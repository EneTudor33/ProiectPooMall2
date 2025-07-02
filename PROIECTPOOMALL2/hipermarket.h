#pragma once
#include "magazin_electronice.h"
#include "magazin_haine.h"
#include "magazin_mancare.h"

class Hipermarket :public MagazinElectronice, public MagazinHaine, public MagazinMancare {
public:
	Hipermarket(std::string nume, int etaj, bool e_deschis);
	void Print(std::ostream& os) const override;
	virtual int Tip() const override;
	virtual void AdaugaProdus() override;
	virtual void AfiseazaCatalog() override;
	virtual void AdaugaAngajat() override;
	virtual void AfiseazaAngajat() override;
	virtual void ModificaStoc(int id, int cantitate) override;
	virtual int GetStoc(int id) override;
	virtual int CalculValoareProduse() const override;
};