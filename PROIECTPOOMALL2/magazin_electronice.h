#pragma once
#include"magazin.h"
#include"gadget.h"
class MagazinElectronice :virtual public Magazin {
protected:
	std::vector<Gadget> m_catalog_gadget;
public:
	MagazinElectronice(std::string nume, int etaj, bool e_deschis);
	std::vector<Gadget> GetCatalogGadget() const;
};