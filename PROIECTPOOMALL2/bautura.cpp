#include"bautura.h"

double Bautura::GetProcentajAlcool() const
{
	return m_procentaj_alcool;
}
Bautura::Bautura(std::string denumire, double pret, int cantitate,
	double procentaj_alcool, int gramaj, bool este_pet) :Produs()
{
	m_denumire = denumire;
	m_pret = pret;
	m_cantitate = cantitate;
	m_procentaj_alcool = procentaj_alcool;
	m_gramaj = gramaj;
	m_este_pet = este_pet;
}
bool Bautura::GetEstePet() const
{
	return m_este_pet;
}
double Bautura::PretUnitate() const
{
	return m_pret + m_pret * 0.09 + GetEstePet() * 0.5;
}
int Bautura::GetGramaj() const
{
	return m_gramaj;
}