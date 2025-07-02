#include "hipermarket.h"

Hipermarket::Hipermarket(std::string nume, int etaj, bool e_deschis) :Magazin(),
MagazinElectronice(nume, etaj, e_deschis), MagazinHaine(nume, etaj, e_deschis),
MagazinMancare(nume, etaj, e_deschis)
{

}
void Hipermarket::Print(std::ostream& os) const
{
	os << "|Hipermarket|ID:" << m_id << "|Nume:" << m_nume << "|Etaj:" << m_etaj
		<< "|E deschis:" << m_e_deschis << "|" << std::endl;
}
int Hipermarket::Tip() const
{
	return 4;
}
void Hipermarket::AdaugaProdus()
{
	int op;
	std::cout << "Ce fel de produs vrei sa adaugi?" << std::endl;
	std::cout << "1.Gadget" << std::endl;
	std::cout << "2.Haina" << std::endl;
	std::cout << "3.Mancare" << std::endl;
	std::cout << "4.Bautura" << std::endl;
	std::cin >> op;
	std::cin.ignore();
	if (op == 1)
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
	if (op == 2)
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
	if (op == 3)
	{
		std::string denumire;
		double pret;
		int gramaj, nr_ingrediente, nr_alergeni;
		std::vector<std::string> ingrediente;
		std::vector<std::string> alergeni;
		std::cout << "Denumire:" << std::endl;
		std::getline(std::cin, denumire);
		std::cout << "Pret:" << std::endl;
		std::cin >> pret;
		std::cin.ignore();
		std::cout << "Gramaj:" << std::endl;
		std::cin >> gramaj;
		std::cin.ignore();
		std::cout << "Cate ingrediente contine produsul?" << std::endl;
		std::cin >> nr_ingrediente;
		std::cin.ignore();
		std::string strng;
		for (int i = 0;i < nr_ingrediente;i++)
		{
			std::cout << "Ingredientul " << i << std::endl;
			std::getline(std::cin, strng);
			ingrediente.push_back(strng);
		}
		std::cout << "Cati alergeni contine produsul?" << std::endl;
		std::cin >> nr_alergeni;
		std::cin.ignore();
		for (int i = 0;i < nr_alergeni;i++)
		{
			std::cout << "Alergenul " << i << std::endl;
			std::getline(std::cin, strng);
			alergeni.push_back(strng);
		}
		Mancare produs(denumire, pret, gramaj, ingrediente, alergeni);
		m_catalog_mancare.push_back(produs);
	}
	if (op == 4)
	{
		std::string denumire;
		double pret, procentaj_alcool;
		int gramaj;
		bool este_pet;
		std::cout << "Denumire:" << std::endl;
		std::getline(std::cin, denumire);
		std::cout << "Pret:" << std::endl;
		std::cin >> pret;
		std::cin.ignore();
		std::cout << "Gramaj:" << std::endl;
		std::cin >> gramaj;
		std::cin.ignore();
		std::cout << "Procentaj alcool:" << std::endl;
		std::cin >> procentaj_alcool;
		std::cin.ignore();
		std::cout << "Este pet?:1/0" << std::endl;
		std::cin >> este_pet;
		std::cin.ignore();
		Bautura produs(denumire, pret, procentaj_alcool, gramaj, este_pet);
		m_catalog_bauturi.push_back(produs);
	}
}
void Hipermarket::AfiseazaCatalog() 
{
	if (m_catalog_mancare.empty())
	{
		std::cout << "Nu avem mancaruri in catalog!" << std::endl;
	}
	else
	{
		std::cout << "Catalog mancare:" << std::endl;
		for (const auto& m : m_catalog_mancare)
		{
			std::cout << "|ID:" << m.GetId() << "|Denumire:" << m.GetDenumire() << "|Pret:" << m.GetPret()
				<< "|Gramaj:" << m.GetGramaj();
			std::cout << "|Ingrediente:";
			for (const auto& s : m.GetIngrediente())
			{
				std::cout << s << " ";
			}
			std::cout << "|Alergeni:";
			for (const auto& s : m.GetAlergeni())
			{
				std::cout << s << " ";
			}
			std::cout << std::endl;
		}
	}
	if (m_catalog_bauturi.empty())
	{
		std::cout << "Nu avem bauturi in catalog!" << std::endl;
	}
	else
	{
		std::cout << "Catalog bauturi:" << std::endl;
		for (const auto& b : m_catalog_bauturi)
		{
			std::cout << "|ID:" << b.GetId() << "|Denumire:" << b.GetDenumire() << "|Pret:" << b.GetPret()
				<< "|Gramaj:" << b.GetGramaj() << "|Este PET:" << b.GetEstePet() << "|Procentaj alcool:"
				<< b.GetProcentajAlcool() << "%" << std::endl;
		}
	}
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
				<< "|Gen:" << h.GetGen() << "|Marime:" << h.GetMarime() << "|Material:" << h.GetMaterial() << std::endl;
		}
	}
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
				<< "|Baterie:" << g.GetBaterie() << "|Memorie:" << g.GetMemorie() << "|Garantie:" << g.GetGarantie()
				<< std::endl;
		}
	}
}