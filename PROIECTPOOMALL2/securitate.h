#pragma once
#include "angajat.h"
class Securitate :public Angajat {
private:
	bool m_tura_noapte;
	bool m_inarmat;
public:
	Securitate(std::string nume, std::string prenume, int varsta, std::string email,
		bool tura, bool inarmat,int salariu);
	bool GetTura() const;
	bool GetInarmat() const;
};