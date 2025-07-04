#include "haina.h"

Haina::Haina(std::string denumire, double pret, std::string gen, std::string marime,
	std::string material) :Produs()
{
	m_cantitate_stoc = 0;
	m_denumire = denumire;
	m_pret = pret;
	m_gen = gen;
	m_marime = marime;
	m_material = material;
}
std::string Haina::GetGen() const
{
	return m_gen;
}
std::string Haina::GetMarime() const
{
	return m_marime;
}
std::string Haina::GetMaterial() const
{
	return m_material;
}
double Haina::PretUnitate() const
{
	return m_pret + m_pret * 0.19;
}
bool Haina::EsteReturnabil() const
{
	return true;
}