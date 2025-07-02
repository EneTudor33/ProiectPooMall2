#pragma once
#include "hipermarket.h"
#include "client.h"
#include "securitate.h"
#include "casier.h"
#include "bucatar.h"
#include "manager.h"
#include "mancare.h"
#include "bautura.h"
#include "haina.h"
#include "gadget.h"
#include <vector>
#include<memory>
class Mall {
private:
	std::vector<std::shared_ptr<Magazin>> m_magazine;
	std::vector<Client> m_clienti;
public:
	void AddMagazin(std::shared_ptr<Magazin> magazin);
	void AfisMagazin() const;
	std::vector<std::shared_ptr<Magazin>> GetMagazine() const;
	std::shared_ptr<Magazin> GetMagazinID (int id) const;
	void AddClient(Client client);
	void ShowClient() const;
	Client* GetClientID(int id);
};