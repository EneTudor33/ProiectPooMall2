#pragma once
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
public:
	Magazin();
	virtual ~Magazin() = default;
	std::string GetNume() const;
	int GetEtaj() const;
	bool GetEDeschis() const;
	int GetId() const;
	virtual void Print(std::ostream& os) const = 0;
};
std::ostream& operator<<(std::ostream& os, const Magazin& m);