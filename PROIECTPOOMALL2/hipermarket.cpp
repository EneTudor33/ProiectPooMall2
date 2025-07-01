#include "hipermarket.h"

Hipermarket::Hipermarket(std::string nume, int etaj, bool e_deschis) :Magazin(),
MagazinElectronice(nume, etaj, e_deschis), MagazinHaine(nume, etaj, e_deschis),
MagazinMancare(nume, etaj, e_deschis)
{

}
