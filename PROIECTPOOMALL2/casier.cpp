#include "casier.h"

std::vector<VanzariLuna> Casier::GetVanzariLunare() const
{
	return m_vanzari_lunare;
}
int Casier::GetNrCasa() const
{
	return m_nr_casa;
}
int Casier::GetBonus() const
{
	return m_bonus;
}
Casier::Casier(std::string nume, std::string prenume, int varsta, std::string email,
	int nr_casa, int prag,int salariu) :Angajat()
{
	m_nume = nume;
	m_prenume = prenume;
	m_varsta = varsta;
	m_email = email;
	m_nr_casa = nr_casa;
	m_prag = prag;
	m_salariu = salariu;
}

