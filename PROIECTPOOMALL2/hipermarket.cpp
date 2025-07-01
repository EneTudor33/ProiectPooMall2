#include "hipermarket.h"

Hipermarket::Hipermarket(std::string nume, int etaj, bool e_deschis) :Magazin(),
MagazinElectronice(nume, etaj, e_deschis), MagazinHaine(nume, etaj, e_deschis),
MagazinMancare(nume, etaj, e_deschis)
{

}
void Hipermarket::Print(std::ostream& os) const
{
	os << "|Hipermarket| ID:" << m_id << "|Nume:" << m_nume << "| Etaj:" << m_etaj
		<< "| E deschis:" << m_e_deschis << "|" << std::endl;
}
