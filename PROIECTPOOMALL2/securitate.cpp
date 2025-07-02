#include "securitate.h"

Securitate::Securitate(std::string nume, std::string prenume, int varsta, std::string email,
	bool tura, bool inarmat,int salariu) :Angajat()
{
	m_nume = nume;
	m_prenume = prenume;
	m_varsta = varsta;
	m_email = email;
	m_tura_noapte = tura;
	m_inarmat = inarmat;
	m_salariu = salariu;
}
bool Securitate::GetTura() const
{
	return m_tura_noapte;
}
bool Securitate::GetInarmat() const
{
	return m_inarmat;
}