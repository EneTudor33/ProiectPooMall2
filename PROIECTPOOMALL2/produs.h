#pragma once
#include<string>
#include "returnabil.h"
class Produs :public Returnabil {
protected:
	const int m_id;
	static int m_next_id;
	std::string m_denumire;
	double m_pret;
	int m_cantitate_stoc;
public:
	Produs();
	virtual ~Produs() = default;
	virtual double PretUnitate() const = 0;
	int GetId() const;
	std::string GetDenumire() const;
	double GetPret() const;
	int GetStoc() const;
	void SetStoc(int cantitate);
	bool EsteReturnabil() const override;
};