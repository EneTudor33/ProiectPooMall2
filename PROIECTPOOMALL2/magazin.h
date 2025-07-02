#pragma once
#include"casier.h"
#include "bucatar.h"
#include "securitate.h"
#include "manager.h"
#include<string>
#include<vector>
#include<iostream>
class Magazin {
protected:
	std::string m_nume;
	int m_etaj;
	bool m_e_deschis;//vreau aici sa adaptez sa verifice asta in timp real
	static int m_next_id;
	const int m_id;
	std::vector<Casier> m_echipa_casieri;
	std::vector<Securitate>  m_echipa_securitate;
	std::vector<Manager>  m_echipa_manageri;
public:
	Magazin();
	virtual ~Magazin() = default;
	std::string GetNume() const;
	int GetEtaj() const;
	bool GetEDeschis() const;
	int GetId() const;
	virtual void Print(std::ostream& os) const = 0;
	virtual int Tip() const = 0;
	virtual void AdaugaProdus() = 0;
	virtual void AfiseazaCatalog() = 0;
	virtual void AdaugaAngajat();
	virtual void AfiseazaAngajat();
	virtual void ModificaStoc(int id,int cantitate) = 0;
	virtual int GetStoc(int id) = 0;
};
std::ostream& operator<<(std::ostream& os, const Magazin& m);