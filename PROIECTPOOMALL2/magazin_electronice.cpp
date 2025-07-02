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
void MagazinElectronice::Print(std::ostream& os) const
{
	os << "|Magazin Electronice|ID:" << m_id << "|Nume:" << m_nume << "|Etaj:" << m_etaj
		<< "|E deschis:" << m_e_deschis << "|" << std::endl;
}
int MagazinElectronice::Tip() const
{
	return 1;
}
void MagazinElectronice::AdaugaProdus()
{
	std::string denumire;
	double pret;
	int memorie, baterie, garantie;
	std::cout << "Denumire produs:" << std::endl;
	std::getline(std::cin, denumire);
	std::cout << "Pret:" << std::endl;
	std::cin >> pret;
	std::cin.ignore();
	std::cout << "Memorie:" << std::endl;
	std::cin >> memorie;
	std::cin.ignore();
	std::cout << "Baterie:" << std::endl;
	std::cin >> baterie;
	std::cin.ignore();
	std::cout << "Luni garantie:" << std::endl;
	std::cin >> garantie;
	std::cin.ignore();
	Gadget produs(denumire, pret, memorie, baterie, garantie);
	m_catalog_gadget.push_back(produs);
}
void MagazinElectronice::AfiseazaCatalog()
{
	if (m_catalog_gadget.empty())
	{
		std::cout << "Nu avem gadgeturi in catalog!" << std::endl;
	}
	else
	{
		std::cout << "Catalog gadgeturi:" << std::endl;
		for (const auto& g : m_catalog_gadget)
		{
			std::cout << "|ID:" << g.GetId() << "|Denumire:" << g.GetDenumire() << "|Pret:" << g.GetPret()
				<<"|Baterie:" << g.GetBaterie()<<"|Memorie:"<<g.GetMemorie()<<"|Garantie:"<<g.GetGarantie()
				<<std::endl;
		}
	}
}
void MagazinElectronice::ModificaStoc(int id,int cantitate)
{
	bool found = false;
	for (auto& g : m_catalog_gadget)
	{
		if (g.GetId() == id)
		{
			g.SetStoc(cantitate);
			found = true;
			break;
		}
	}
	if (!found)
	{
		std::cout << "Produsul nu exista!" << std::endl;
	}
}
int MagazinElectronice::GetStoc(int id)
{
	bool found = false;
	for (auto& g : m_catalog_gadget)
	{
		if (g.GetId() == id)
			return g.GetStoc();
	}
		std::cout << "Produsul nu exista!" << std::endl;
		return -1;
}
int MagazinElectronice::CalculValoareProduse() const
{
	int suma = 0;
	for (auto& g : m_catalog_gadget)
	{
		suma = suma + g.GetPret() * g.GetStoc();
	}
	return suma;
}