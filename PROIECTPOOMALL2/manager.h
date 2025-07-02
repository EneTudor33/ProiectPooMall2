#pragma once
#include "angajat.h"
#include<vector>

class Manager :public Angajat {
private:
	std::vector<int> m_echipa;//retinem id-urile angajatorilor din echipa sa 
	bool m_masina_serviciu;
	double m_target_vanzari_echipa;
public:
	Manager(std::string nume, std::string prenume, int varsta, std::string email,
		bool masina_serviciu, double target_vanzari_echipa,int salariu);
	bool GetMasinaServiciu() const;
	double GetTargetVanzariEchipa() const;
};