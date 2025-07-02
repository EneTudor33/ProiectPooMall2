#include "mall.h"
#include "functii_data.h"
Mall& Mall::getInstance()
{
	static Mall instance;
	return instance;
}
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
bool Mall :: AddTranzactie(int id_magazin, int id_client, int id_produs, int cantitate, int zi, int luna, int an)
{
	if (cantitate < 0)
		return false;
	std::shared_ptr<Magazin> magazin = GetMagazinID(id_magazin);
	Client* client = GetClientID(id_client);
	if (!magazin)
	{
		std::cout << "Magazinul nu exista!" << std::endl;
		return false;
	}
	if (!client)
	{
		std::cout << "Clientul nu exista!" << std::endl;
		return false;
	}
	double pret = magazin->GetPretProdus(id_produs);
	if (pret < 0)
	{
		std::cout << "Produsul nu exista!" << std::endl;
		return false;
	}
	if (!magazin->VindeProdus(id_produs, cantitate))
	{
		std::cout << "Stoc insuficient!" << std::endl;
		return false;
	}
	double discount = client->GetAbonament().discount / 100;
	double total = pret * cantitate;
	total = total - total * discount;
	if (client->GetCredit() < total)
	{
		std::cout << "Credit insuficient!" << std::endl;
		return false;
	}
	client->SetCredit(client->GetCredit() - total);
	Tranzactie tranzactie(zi, luna, an, id_client, id_produs, cantitate, total);
	m_tranzactii[id_magazin].push_back(tranzactie);
}
bool Mall::ReturTranzactie(int id_magazin, int index)
{
	auto it = m_tranzactii.find(id_magazin);
	if (it == m_tranzactii.end())
	{
		std::cout << "Magazinul nu exista!" << std::endl;
		return false;
	}
	std::vector<Tranzactie>& tranzactii = it->second;
	if (index >= tranzactii.size())
	{
		std::cout << "Id invalid!" << std::endl;
		return false;
	}
	Tranzactie tranzactie = tranzactii[index];
	if (!Sub60Zile(tranzactie.GetDataTranzactie()))
	{
		std::cout << "Produsul nu e returnabil!" << std::endl;
		return false;
	}
	std::shared_ptr<Magazin> magazin = GetMagazinID(id_magazin);
	Client* client = GetClientID(tranzactie.GetIdClient());
	if (!magazin || !client)
	{
		std::cout << "Magazinul sau clienul nu exista!" << std::endl;
		return false;
	}
	Produs* produs = magazin->CautaProdus(tranzactie.GetIdProdus());
	if (!produs || !produs->EsteReturnabil())
	{
		std::cout << "Produsul nu exista sau nu este returnabil!" << std::endl;
		return false;
	}
	magazin->AdaugaStoc(tranzactie.GetIdProdus(), tranzactie.GetCantitate());
	client -> SetCredit(client->GetCredit() + tranzactie.GetSumaPlatita());
	it->second.erase(it->second.begin() + index);
	std::cout << "Tranzactie returnata cu succes!" << std::endl;
	return true;
}
const std::vector<Tranzactie>& Mall::GetTranzactiiMagazin(int id) const
{
	static const std::vector<Tranzactie> null;
	for (const auto& pereche : m_tranzactii)
		if (pereche.first == id)
			return pereche.second;
	return null;
}
double Mall::GetVanzariMagazin(int id) const
{
	double total = 0;
	for (const auto& pereche : m_tranzactii)
		if (pereche.first == id)
		{
			const std::vector<Tranzactie>& tranzactii = pereche.second;
			for (const auto& t : tranzactii)
				total=total+t.GetSumaPlatita();
			break;
		}
	return total;
}
