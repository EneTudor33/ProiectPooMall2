#include "mancare.h"

Mancare::Mancare(std::string denumire, double pret, int gramaj,
	std::vector<std::string> ingrediente, std::vector<std::string> alergeni) :Produs()
{
	m_cantitate_stoc = 0;
	m_denumire = denumire;
	m_pret = pret;
	m_gramaj = gramaj;
	m_ingrediente = ingrediente;
	m_alergeni = alergeni;
}
std::vector<std::string> Mancare::GetIngrediente() const
{
	return m_ingrediente;
}
std::vector<std::string> Mancare::GetAlergeni() const
{
	return m_alergeni;
}
double Mancare::PretUnitate() const
{
	return m_pret + m_pret * 0.09;
}
int Mancare::GetGramaj() const
{
	return m_gramaj;
}
bool Mancare::EsteReturnabil() const
{
	return false;
}