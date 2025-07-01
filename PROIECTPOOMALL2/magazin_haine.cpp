#include "magazin_haine.h"

MagazinHaine::MagazinHaine(std::string nume, int etaj, bool e_deschis) :Magazin()
{
	m_nume = nume;
	m_etaj = etaj;
	m_e_deschis = e_deschis;
}
std::vector<Haina> MagazinHaine::GetCatalogHaine() const
{
	return m_catalog_haine;
}
void MagazinHaine::Print(std::ostream& os) const
{
	os << "|Magazin Haine| ID:" << m_id << "|Nume:" << m_nume << "| Etaj:" << m_etaj
		<< "| E deschis:" << m_e_deschis << "|" << std::endl;
}