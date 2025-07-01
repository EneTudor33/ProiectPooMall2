#include"magazin_mancare.h"


MagazinMancare::MagazinMancare(std::string nume, int etaj, bool e_deschis) :Magazin()
{
	m_nume = nume;
	m_etaj = etaj;
	m_e_deschis = e_deschis;
}
std::vector<Mancare> MagazinMancare::GetCatalogMancare() const
{
	return m_catalog_mancare;
}