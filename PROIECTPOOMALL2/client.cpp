#include "client.h"
#include<iostream>
Client::Client(std::string nume, std::string prenume,
	int varsta, std::string email, double credit):Om()
{
	m_credit = credit;
	m_nume = nume;
	m_prenume = prenume;
	m_varsta = varsta;
	m_email = email;
	m_abonament.discount = 0;
	m_abonament.nume_abonament = "";
}
Client::Client(std::string nume, std::string prenume, int varsta,
	std::string email, Abonament abonament, double credit) :Om()
{
	m_credit = credit;
	m_nume = nume;
	m_prenume = prenume;
	m_varsta = varsta;
	m_email = email;
	m_abonament.discount = abonament.discount;
	m_abonament.nume_abonament = abonament.nume_abonament;
}
double Client::GetCredit() const
{
	return m_credit;
}
Abonament Client::GetAbonament() const
{
	return m_abonament;
}
std::ostream& operator<<(std::ostream& os, const Client& c)
{
	os <<"|ID:"<<c.GetId()<< "|Nume:" << c.GetNume() << "|Prenume:" << c.GetPrenume() << "|Email:" << c.GetEmail() << "|Varsta" << c.GetVarsta()
		<< "|Credit:" << c.GetCredit() << std::endl;
	return os;
}
void Client::SetCredit(int credit)
{
	m_credit = credit;
}