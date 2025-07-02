#include "magazin.h"

int Magazin::m_next_id = 0;
Magazin::Magazin() :m_id(++m_next_id)
{

}
std::string Magazin::GetNume() const
{
	return m_nume;
}
int Magazin::GetEtaj() const
{
	return m_etaj;
}
bool Magazin::GetEDeschis() const
{
	return m_e_deschis;
}
int Magazin::GetId() const
{
	return m_id;
}
std::ostream& operator<<(std::ostream& os, const Magazin& m)
{
	m.Print(os);
	return os;
}
void Magazin::AdaugaAngajat()
{
	std::cout << "Ce fel de angajat vrei sa adaugi?" << std::endl;
	std::cout << "1.Casier" << std::endl;
	std::cout << "2.Securitate" << std::endl;
	std::cout << "3.Manager" << std::endl;
	int op;
	std::cin >> op;
	std::cin.ignore();
	switch (op)
	{
	case 1:
	{
		std::string nume, prenume, email;
		int varsta, nr_casa, prag,salariu;
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
		int varsta,salariu;
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
	default:
	{
		std::cout << "Optiune invalida!" << std::endl;
	}
	}
}
void Magazin::AfiseazaAngajat()
{
	if (m_echipa_casieri.empty())
		std::cout << "Nu evem casieri in echipa!" << std::endl;
	else
	{
		std::cout << "Echipa Casieri:" << std::endl;
		for (const auto& c : m_echipa_casieri)
		{
			std::cout << "|Nume:" << c.GetNume() << "|Prenume:" << c.GetPrenume() << "|Email:" << c.GetEmail() << "|Varsta:"
				<< c.GetVarsta() << "|Salariu:" << c.GetSalariu() << "|Numar casa:" << c.GetNrCasa()<<std::endl;
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
				<<"|Tura noapte:"<<s.GetTura()<<std::endl;
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
}
