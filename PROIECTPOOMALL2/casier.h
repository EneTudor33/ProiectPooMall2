#pragma once
#include"angajat.h"
#include "vanzari_luna.h"
#include<vector>
/*vom renunta la clasa Salesman care aparea in poza cu lista cu clasele intrucat e destul
de redundanta din cauza faptului ca in aproape toate magazinele dintr-un mall casierii sunt si
salesman si invers*/
class Casier :public Angajat {
private:
	std::vector<VanzariLuna> m_vanzari_lunare;
	int m_nr_casa;
	int m_prag;//daca depaseste acest prag ii oferim niste bonusuri
	int m_bonus;
public:
	std::vector<VanzariLuna> GetVanzariLunare() const;
	int GetNrCasa() const;
	int GetBonus() const;
	Casier(std::string nume, std::string prenume, int varsta, std::string email,
		int nr_casa, int prag);
};