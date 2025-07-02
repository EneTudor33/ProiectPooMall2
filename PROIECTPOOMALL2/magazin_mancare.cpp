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
void MagazinMancare::AdaugaAngajat()
{
	std::cout << "Ce fel de angajat vrei sa adaugi?" << std::endl;
	std::cout << "1.Casier" << std::endl;
	std::cout << "2.Securitate" << std::endl;
	std::cout << "3.Manager" << std::endl;
	std::cout << "4.Bucatar" << std::endl;
	int op;
	std::cin >> op;
	std::cin.ignore();
	switch (op)
	{
	case 1:
	{
		std::string nume, prenume, email;
		int varsta, nr_casa, prag, salariu;
		std::cout << "Nume:" << std::endl;
		std::getline(std::cin, nume);
		std::cout << "Prenume:" << std::endl;
		std::getline(std::cin, prenume);
		std::cout << "Email:" << std::endl;
		std::getline(std::cin, email);
		std::cout << "Varsta:" << std::endl;
		std::cin >> varsta;
		std::cin.ignore();
		std::cout << "Salariu:" << std::endl;
		std::cin >> salariu;
		std::cin.ignore();
		std::cout << "Numar casa:" << std::endl;
		std::cin >> nr_casa;
		std::cin.ignore();
		std::cout << "Prag pentru bonus:" << std::endl;
		std::cin >> prag;
		std::cin.ignore();
		Casier angajat(nume, prenume, varsta, email, nr_casa, prag, salariu);
		m_echipa_casieri.push_back(angajat);
		break;
	}
	case 2:
	{
		std::string nume, prenume, email;
		int varsta, salariu;
		bool tura, inarmat;
		std::cout << "Nume:" << std::endl;
		std::getline(std::cin, nume);
		std::cout << "Prenume:" << std::endl;
		std::getline(std::cin, prenume);
		std::cout << "Email:" << std::endl;
		std::getline(std::cin, email);
		std::cout << "Varsta:" << std::endl;
		std::cin >> varsta;
		std::cin.ignore();
		std::cout << "Salariu:" << std::endl;
		std::cin >> salariu;
		std::cin.ignore();
		std::cout << "Tura noapte:0/1" << std::endl;
		std::cin >> tura;
		std::cin.ignore();
		std::cout << "Inarmat:0/1" << std::endl;
		std::cin >> inarmat;
		std::cin.ignore();
		Securitate angajat(nume, prenume, varsta, email, tura, inarmat, salariu);
		m_echipa_securitate.push_back(angajat);
		break;
	}
	case 3:
	{
		std::string nume, prenume, email;
		int varsta, salariu;
		bool masina;
		double target;
		std::cout << "Nume:" << std::endl;
		std::getline(std::cin, nume);
		std::cout << "Prenume:" << std::endl;
		std::getline(std::cin, prenume);
		std::cout << "Email:" << std::endl;
		std::getline(std::cin, email);
		std::cout << "Varsta:" << std::endl;
		std::cin >> varsta;
		std::cin.ignore();
		std::cout << "Salariu:" << std::endl;
		std::cin >> salariu;
		std::cin.ignore();
		std::cout << "Masina de serviciu:0/1" << std::endl;
		std::cin >> masina;
		std::cin.ignore();
		std::cout << "Target vanzari ale echipei sale:" << std::endl;
		std::cin >> target;
		std::cin.ignore();
		Manager angajat(nume, prenume, varsta, email, masina, target, salariu);
		m_echipa_manageri.push_back(angajat);
		break;
	}
	case 4:
	{
		std::string nume, prenume, email;
		int varsta, salariu,ani,portii;
		std::cout << "Nume:" << std::endl;
		std::getline(std::cin, nume);
		std::cout << "Prenume:" << std::endl;
		std::getline(std::cin, prenume);
		std::cout << "Email:" << std::endl;
		std::getline(std::cin, email);
		std::cout << "Varsta:" << std::endl;
		std::cin >> varsta;
		std::cin.ignore();
		std::cout << "Salariu:" << std::endl;
		std::cin >> salariu;
		std::cin.ignore();
		std::cout << "Ani experienta:" << std::endl;
		std::cin >> ani;
		std::cin.ignore();
		std::cout << "Portii pe care le poate face zilnic:" << std::endl;
		std::cin >> portii;
		std::cin.ignore();
		Bucatar angajat(nume, prenume, varsta, email, ani, portii, salariu);
		m_echipa_bucatari.push_back(angajat);
		break;
	}
	default:
	{
		std::cout << "Optiune invalida!" << std::endl;
	}
	}
}
void MagazinMancare::AfiseazaAngajat()
{
	if (m_echipa_casieri.empty())
		std::cout << "Nu evem casieri in echipa!" << std::endl;
	else
	{
		std::cout << "Echipa Casieri:" << std::endl;
		for (const auto& c : m_echipa_casieri)
		{
			std::cout << "|Nume:" << c.GetNume() << "|Prenume:" << c.GetPrenume() << "|Email:" << c.GetEmail() << "|Varsta:"
				<< c.GetVarsta() << "|Salariu:" << c.GetSalariu() << "|Numar casa:" << c.GetNrCasa() << std::endl;
		}
	}
	if (m_echipa_securitate.empty())
		std::cout << "Nu evem securitate in echipa!" << std::endl;
	else
	{
		std::cout << "Echipa Securitate:" << std::endl;
		for (const auto& s : m_echipa_securitate)
		{
			std::cout << "|Nume:" << s.GetNume() << "|Prenume:" << s.GetPrenume() << "|Email:" << s.GetEmail() << "|Varsta:"
				<< s.GetVarsta() << "|Salariu:" << s.GetSalariu() << "|Inarmat:" << s.GetInarmat()
				<< "|Tura noapte:" << s.GetTura() << std::endl;
		}
	}
	if (m_echipa_manageri.empty())
		std::cout << "Nu evem manageri in echipa!" << std::endl;
	else
	{
		std::cout << "Echipa Manageri:" << std::endl;
		for (const auto& m : m_echipa_manageri)
		{
			std::cout << "|Nume:" << m.GetNume() << "|Prenume:" << m.GetPrenume() << "|Email:" << m.GetEmail() << "|Varsta:"
				<< m.GetVarsta() << "|Salariu:" << m.GetSalariu() << "|Masina de serviciu:" << m.GetMasinaServiciu()
				<< "|Target Vanzari echipa:" << m.GetTargetVanzariEchipa() << std::endl;
		}
	}
	if (m_echipa_bucatari.empty())
		std::cout << "Nu evem bucatari in echipa!" << std::endl;
	else
	{
		std::cout << "Echipa Bucatari:" << std::endl;
		for (const auto& b : m_echipa_bucatari)
		{
			std::cout << "|Nume:" << b.GetNume() << "|Prenume:" << b.GetPrenume() << "|Email:" << b.GetEmail() << "|Varsta:"
				<< b.GetVarsta() << "|Salariu:" << b.GetSalariu() << "|Ani experienta:" << b.GetAniExperienta()
				<< "|Portii zilnice:" << b.GetPortiiZilnice() << std::endl;
		}
	}
}
void MagazinMancare::ModificaStoc(int id, int cantitate)
{
	bool found = false;
	for (auto& g : m_catalog_bauturi)
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
		for (auto& g : m_catalog_mancare)
		{
			if (g.GetId() == id)
			{
				g.SetStoc(cantitate);
				found = true;
				break;
			}
		}
	}
	if (!found)
	{
		std::cout << "Produsul nu exista!" << std::endl;
	}
}
int MagazinMancare::GetStoc(int id)
{
	bool found = false;
	for (auto& g : m_catalog_mancare)
	{
		if (g.GetId() == id)
			return g.GetStoc();
	}
	for (auto& g : m_catalog_bauturi)
	{
		if (g.GetId() == id)
			return g.GetStoc();
	}
	std::cout << "Produsul nu exista!" << std::endl;
	return -1;
}
double MagazinMancare::CalculValoareProduse() const
{
	double suma = 0;
	for (auto& g : m_catalog_mancare)
	{
		suma = suma + g.GetPret() * g.GetStoc();
	}
	for (auto& g : m_catalog_bauturi)
	{
		suma = suma + g.GetPret() * g.GetStoc();
	}
	return suma;
}
bool MagazinMancare::VindeProdus(int id_produs, int cantitate)
{
	if (cantitate < 0)
		return false;
	for (auto& g : m_catalog_mancare)
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
	for (auto& g : m_catalog_bauturi)
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
double MagazinMancare::GetPretProdus(int id) const
{
	for (const auto& g : m_catalog_mancare)
	{
		if (g.GetId() == id)
		{
			return g.PretUnitate();
		}
	}
	for (const auto& g : m_catalog_bauturi)
	{
		if (g.GetId() == id)
		{
			return g.PretUnitate();
		}
	}
	return -1;
}
void MagazinMancare::AdaugaStoc(int id, int cantitate)
{
	if (cantitate <= 0)
		return;
	for (auto& g : m_catalog_mancare)
	{
		if (g.GetId() == id)
		{
			g.SetStoc(g.GetStoc() + cantitate);
			break;
		}
	}
	for (auto& g : m_catalog_bauturi)
	{
		if (g.GetId() == id)
		{
			g.SetStoc(g.GetStoc() + cantitate);
			break;
		}
	}
}
Produs* MagazinMancare::CautaProdus(int id)
{
	for (auto& g : m_catalog_mancare)
		if (g.GetId() == id)
			return &g;
	for (auto& g : m_catalog_bauturi)
		if (g.GetId() == id)
			return &g;
	return nullptr;
}