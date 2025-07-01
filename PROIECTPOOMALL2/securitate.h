#pragma once
#include "angajat.h"
class Securitate :public Angajat {
private:
	std::string m_tura;
	bool m_inarmat;
public:
	Securitate(std::string nume, std::string prenume, int varsta, std::string email,
		std::string tura, bool inarmat);
	std::string GetTura() const;
	bool GetInarmat() const;
};