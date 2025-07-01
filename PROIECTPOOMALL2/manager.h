#pragma once
#include "angajat.h"
#include<vector>

class Manager :public Angajat {
private:
	std::vector<int> m_echipa;//retinem id-urile angajatorilor din echipa sa sau pointeri daca nu uit
	bool m_masina_serviciu;
	double m_target_vanzari_echipa;
public:
	Manager(std::string nume, std::string prenume, int varsta, std::string email,
		std::vector<int>echipa, bool masina_serviciu, double target_vanzari_echipa);
	bool GetMasinaServiciu() const;
	double GetTargetVanzariEchipa() const;
};