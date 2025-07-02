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
	os << "|Magazin Haine|ID:" << m_id << "|Nume:" << m_nume << "|Etaj:" << m_etaj
		<< "|E deschis:" << m_e_deschis << "|" << std::endl;
}
int MagazinHaine::Tip() const 
{
	return 2;
}
void MagazinHaine::AdaugaProdus()
{
	std::string gen, marime, material, denumire;
	double pret;
	std::cout << "Denumire:" << std::endl;
	std::getline(std::cin, denumire);
	std::cout << "Pret:" << std::endl;
	std::cin >> pret;
	std::cin.ignore();
	std::cout << "Marime:" << std::endl;
	std::getline(std::cin, marime);
	std::cout << "Gen:" << std::endl;
	std::getline(std::cin, gen);
	std::cout << "Denumire:" << std::endl;
	std::getline(std::cin, denumire);
	Haina produs(denumire, pret, gen, marime, material);
	m_catalog_haine.push_back(produs);
}
void MagazinHaine::AfiseazaCatalog()
{
	if (m_catalog_haine.empty())
	{
		std::cout << "Nu avem haine in catalog!" << std::endl;
	}
	else
	{
		std::cout << "Catalog Haine:" << std::endl;
		for (const auto& h : m_catalog_haine)
		{
			std::cout << "|ID:" << h.GetId() << "|Denumire:" << h.GetDenumire() << "|Pret:" << h.GetPret()
				<<"|Gen:"<<h.GetGen()<<"|Marime:"<<h.GetMarime()<<"|Material:"<<h.GetMaterial()<<std::endl;
		}
	}
}