#pragma once
#include "magazin.h"
#include "haina.h"
class MagazinHaine :virtual public Magazin {
protected:
	std::vector<Haina> m_catalog_haine;
public:
	MagazinHaine(std::string nume, int etaj, bool e_deschis);
	std::vector<Haina> GetCatalogHaine() const;
	void Print(std::ostream& os) const override;
	virtual int Tip() const override;
	virtual void AdaugaProdus() override;
	virtual void AfiseazaCatalog() override;
	virtual void ModificaStoc(int id, int cantitate) override;
	virtual int GetStoc(int id) override;
	virtual double CalculValoareProduse() const override;
};