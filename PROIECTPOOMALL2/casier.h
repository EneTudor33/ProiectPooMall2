#pragma once
#include"angajat.h"
#include<vector>
/*vom renunta la clasa Salesman care aparea in poza cu lista cu clasele intrucat e destul
de redundanta din cauza faptului ca in aproape toate magazinele dintr-un mall casierii sunt si
salesman si invers*/
class Casier :public Angajat {
private:
	int m_nr_casa;
	int m_prag;
	int m_bonus;
public:
	int GetNrCasa() const;
	int GetBonus() const;
	Casier(std::string nume, std::string prenume, int varsta, std::string email,
		int nr_casa, int prag,int salariu);
};