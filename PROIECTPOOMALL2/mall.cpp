#include "mall.h"

void Mall::AddMagazin(std::shared_ptr<Magazin> magazin)
{
	m_magazine.push_back(magazin);
}