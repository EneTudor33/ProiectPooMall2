#include "gadget.h"

Gadget::Gadget(std::string denumire, double pret, int baterie, int memorie,
	int garantie) :Produs()
{
	m_cantitate_stoc = 0;
	m_denumire = denumire;
	m_pret = pret;
	m_baterie = baterie;
	m_memorie = memorie;
	m_garantie = garantie;
}
int Gadget::GetBaterie() const
{
	return m_baterie;
}
int Gadget::GetMemorie() const
{
	return m_memorie;
}
int Gadget::GetGarantie() const
{
	return m_garantie;
}
double Gadget::PretUnitate() const
{
	return m_pret + m_pret * 0.19;
}
bool Gadget::EsteReturnabil() const
{
	return true;
}