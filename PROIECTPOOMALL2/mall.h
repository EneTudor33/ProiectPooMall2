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
#include"tranzactie.h"
#include <vector>
#include<memory>
#include<unordered_map>
class Mall {
private:
	std::vector<std::shared_ptr<Magazin>> m_magazine;
	std::vector<Client> m_clienti;
	std::unordered_map<int, std::vector<Tranzactie>> m_tranzactii;
	Mall() = default;
	Mall(const Mall&) = delete; 
	Mall& operator=(const Mall&) = delete;
public:
	static Mall& getInstance();
	void AddMagazin(std::shared_ptr<Magazin> magazin);
	void AfisMagazin() const;
	std::vector<std::shared_ptr<Magazin>> GetMagazine() const;
	std::shared_ptr<Magazin> GetMagazinID(int id) const;
	void AddClient(Client client);
	void ShowClient() const;
	Client* GetClientID(int id);
	bool AddTranzactie(int id_magazin, int id_client, int id_produs, int cantitate, int zi, int luna, int an);
	bool ReturTranzactie(int id_magazin, int index);
	const std::vector<Tranzactie>& GetTranzactiiMagazin(int id) const;
	double GetVanzariMagazin(int id) const;
};