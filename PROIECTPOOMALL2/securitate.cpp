#include "securitate.h"

Securitate::Securitate(std::string nume, std::string prenume, int varsta, std::string email,
	std::string tura, bool inarmat) :Angajat()
{
	m_nume = nume;
	m_prenume = prenume;
	m_varsta = varsta;
	m_email = email;
	m_tura = tura;
	m_inarmat = inarmat;
}
std::string Securitate::GetTura() const
{
	return m_tura;
}
bool Securitate::GetInarmat() const
{
	return m_inarmat;
}