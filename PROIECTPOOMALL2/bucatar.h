#pragma once
#include "angajat.h"
#include<vector>
#include<string>
class Bucatar :public Angajat {
private:
	std::vector<std::string> m_mancare;//ce stie sa gateasca
	int m_ani_experienta; //daca are experienta mai mare il platim mai mult
	int m_portii_zilnice;
public:
	Bucatar(std::string nume, std::string prenume, int varsta, std::string email,
		std::vector<std::string> mancare, int ani_experienta, int portii_zilnice);
	std::vector<std::string> GetMancare() const;
	int GetAniExperienta() const;
	int GetPortiiZilnice() const;
};
