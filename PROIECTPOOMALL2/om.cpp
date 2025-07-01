#include "om.h"

int Om::m_next_id = 0;
Om::Om() :m_id(++m_next_id)
{

}
std::string Om::GetNume() const
{
	return m_nume;
}
std::string Om::GetPrenume() const
{
	return m_prenume;
}
int Om::GetVarsta() const
{
	return m_varsta;
}
std::string Om::GetEmail() const
{
	return m_email;
}