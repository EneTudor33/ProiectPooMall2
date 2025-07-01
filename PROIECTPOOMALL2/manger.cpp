#include "manager.h"

Manager::Manager(std::string nume, std::string prenume, int varsta, std::string email,
	std::vector<int>echipa, bool masina_serviciu, double target_vanzari_echipa) :Angajat()
{
	m_nume = nume;
	m_prenume = prenume;
	m_varsta = varsta;
	m_email = email;
	m_echipa = echipa;
	m_masina_serviciu = masina_serviciu;
	m_target_vanzari_echipa = target_vanzari_echipa;
}
bool Manager::GetMasinaServiciu() const
{
	return m_masina_serviciu;
}
double Manager::GetTargetVanzariEchipa() const
{
	return m_target_vanzari_echipa;
}