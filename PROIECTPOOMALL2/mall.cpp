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