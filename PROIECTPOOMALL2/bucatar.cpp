#include "bucatar.h"

Bucatar::Bucatar(std::string nume, std::string prenume, int varsta, std::string email,
	std::vector<std::string> mancare, int ani_experienta, int portii_zilnice) :Angajat()
{
	m_nume = nume;
	m_prenume = prenume;
	m_varsta = varsta;
	m_email = email;
	m_mancare = mancare;
	m_ani_experienta = ani_experienta;
	m_portii_zilnice = portii_zilnice;
}
std::vector<std::string> Bucatar::GetMancare() const
{
	return m_mancare;
}
int Bucatar::GetAniExperienta() const
{
	return m_ani_experienta;
}
int Bucatar::GetPortiiZilnice() const
{
	return m_portii_zilnice;
}