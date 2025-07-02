#include "bucatar.h"

Bucatar::Bucatar(std::string nume, std::string prenume, int varsta, std::string email,
	int ani_experienta, int portii_zilnice,int salariu) :Angajat()
{
	m_nume = nume;
	m_prenume = prenume;
	m_varsta = varsta;
	m_email = email;
	m_ani_experienta = ani_experienta;
	m_portii_zilnice = portii_zilnice;
	m_salariu = salariu;
}
int Bucatar::GetAniExperienta() const
{
	return m_ani_experienta;
}
int Bucatar::GetPortiiZilnice() const
{
	return m_portii_zilnice;
}