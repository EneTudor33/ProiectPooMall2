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
void MagazinMancare::Print(std::ostream& os) const
{
	os << "|Magazin Mancare| ID:" << m_id << "|Nume:" << m_nume << "| Etaj:" << m_etaj
		<< "| E deschis:" << m_e_deschis << "|" << std::endl;
}