#pragma once
#include "angajat.h"
#include<vector>
#include<string>
class Bucatar :public Angajat {
private:
	int m_ani_experienta;
	int m_portii_zilnice;
public:
	Bucatar(std::string nume, std::string prenume, int varsta, std::string email,
		int ani_experienta, int portii_zilnice,int salariu);
	int GetAniExperienta() const;
	int GetPortiiZilnice() const;
};
