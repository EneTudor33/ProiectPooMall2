#include "magazin_electronice.h"

MagazinElectronice::MagazinElectronice(std::string nume, int etaj, bool e_deschis) :Magazin()
{
	m_nume = nume;
	m_etaj = etaj;
	m_e_deschis = e_deschis;
}
std::vector<Gadget> MagazinElectronice::GetCatalogGadget() const
{
	return m_catalog_gadget;
}