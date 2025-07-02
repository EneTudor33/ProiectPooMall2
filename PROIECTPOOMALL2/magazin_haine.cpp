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
void MagazinHaine::ModificaStoc(int id, int cantitate)
{
	bool found = false;
	for (auto& g : m_catalog_haine)
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
int MagazinHaine::GetStoc(int id)
{
	bool found = false;
	for (auto& g : m_catalog_haine)
	{
		if (g.GetId() == id)
			return g.GetStoc();
	}
	std::cout << "Produsul nu exista!" << std::endl;
	return -1;
}
double MagazinHaine::CalculValoareProduse() const
{
	double suma = 0;
	for (auto& g : m_catalog_haine)
	{
		suma = suma + g.GetPret() * g.GetStoc();
	}
	return suma;
}
bool MagazinHaine::VindeProdus(int id_produs, int cantitate)
{
	if (cantitate < 0)
		return false;
	for (auto& g : m_catalog_haine)
	{
		if (g.GetId() == id_produs)
		{
			int stoc = g.GetStoc();
			if (stoc < cantitate)
				return false;
			g.SetStoc(stoc - cantitate);
			return true;
		}
	}
	return false;
}
double MagazinHaine::GetPretProdus(int id) const
{
	for (const auto& g : m_catalog_haine)
	{
		if (g.GetId() == id)
		{
			return g.PretUnitate();
		}
	}
	return -1;
}
void MagazinHaine::AdaugaStoc(int id, int cantitate)
{
	if (cantitate <= 0)
		return;
	for (auto& g : m_catalog_haine)
	{
		if (g.GetId() == id)
		{
			g.SetStoc(g.GetStoc() + cantitate);
			break;
		}
	}
}
Produs* MagazinHaine::CautaProdus(int id)
{
	for (auto& g : m_catalog_haine)
		if (g.GetId() == id)
			return &g;
	return nullptr;
}