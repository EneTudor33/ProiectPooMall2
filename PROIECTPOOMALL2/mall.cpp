#include "mall.h"

void Mall::AddMagazin(std::shared_ptr<Magazin> magazin)
{
	m_magazine.push_back(magazin);
}
void Mall :: AfisMagazin() const
{
	if (m_magazine.empty())
		std::cout << "Nu exista magazne inregistrate!" << std::endl;
	else
	{
		for (const auto& m : m_magazine)
		{
			std::cout << *m << std::endl;
		}
	}
}
std::shared_ptr<Magazin> Mall::GetMagazinID(int id) const
{
	for (const auto& m : m_magazine)
	{
		if (m->GetId() == id)
			return m;
	}
	return nullptr;
}
std::vector<std::shared_ptr<Magazin>> Mall::GetMagazine() const
{
	return m_magazine;
}
void Mall::AddClient(Client client)
{
	m_clienti.push_back(client);
}
void Mall::ShowClient() const
{
	if (m_clienti.empty())
		std::cout << "Nu exista clienti inregistrati!" << std::endl;
	else
	{
		for (const auto& c : m_clienti)
		{
			std::cout << c;
		}
	}
}
Client* Mall::GetClientID(int id)
{
	for (auto& m : m_clienti)
	{
		if (m.GetId() == id)
			return &m;
	}
	return nullptr;
}