#pragma once
#include "magazin_electronice.h"
#include "magazin_haine.h"
#include "magazin_mancare.h"

class Hipermarket :public MagazinElectronice, public MagazinHaine, public MagazinMancare {
public:
	Hipermarket(std::string nume, int etaj, bool e_deschis);
};
