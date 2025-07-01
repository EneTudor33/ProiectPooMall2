#pragma once
#include"om.h"

class Angajat :public Om {
protected:
	double m_salariu;
public:
	virtual ~Angajat() = default;
	Angajat();
	double GetSalariu() const;
};