#pragma once
#include"magazin.h"
#include"gadget.h"
class MagazinElectronice :virtual public Magazin {
protected:
	std::vector<Gadget> m_catalog_gadget;
public:
	MagazinElectronice(std::string nume, int etaj, bool e_deschis);
	std::vector<Gadget> GetCatalogGadget() const;
	void Print(std::ostream& os) const override;
	virtual int Tip() const override;
	virtual void AdaugaProdus() override;
	virtual void AfiseazaCatalog() override;
	virtual void ModificaStoc(int id,int cantitate) override;
	virtual int GetStoc(int id) override;
	virtual double CalculValoareProduse() const override;
	virtual bool VindeProdus(int id_produs, int cantitate) override;
	virtual double GetPretProdus(int id) const override;
	virtual void AdaugaStoc(int id, int cantitate) override;
	virtual Produs* CautaProdus(int id) override;
};