#include "produs.h"
#include <string>

int Produs::m_next_id = 0;
Produs::Produs() :m_id(++m_next_id)
{

}
int Produs::GetId() const
{
	return m_id;
}
std::string Produs::GetDenumire() const
{
	return m_denumire;
}
double Produs::GetPret() const
{
	return m_pret;
}
void Produs::SetStoc(int cantitate)
{
	m_cantitate_stoc = cantitate;
}
int Produs::GetStoc() const
{
	return m_cantitate_stoc;
}