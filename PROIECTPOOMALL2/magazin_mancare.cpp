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
	os << "|Magazin Mancare|ID:" << m_id << "|Nume:" << m_nume << "|Etaj:" << m_etaj
		<< "|E deschis:" << m_e_deschis << "|" << std::endl;
}
int MagazinMancare::Tip() const
{
	return 3;
}
void MagazinMancare::AdaugaProdus()
{
	int op;
	std::cout << "Vrei sa adaugi Mancare sau Bautura? 1/2" << std::endl;
	std::cin >> op;
	std::cin.ignore();
	if (op == 1)
	{
		std::string denumire;
		double pret;
		int gramaj,nr_ingrediente,nr_alergeni;
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
	if (op == 2)
	{
		std::string denumire;
		double pret,procentaj_alcool;
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
void MagazinMancare::AfiseazaCatalog()
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
}