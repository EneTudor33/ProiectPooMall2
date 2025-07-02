#pragma once
#include "produs.h"
#include<vector>
class Mancare :public Produs {
private:
	int m_gramaj;
	std::vector<std::string> m_ingrediente;
	std::vector<std::string> m_alergeni;
public:
	Mancare(std::string denumire, double pret, int gramaj, std::vector<std::string> ingrediente,
		std::vector<std::string> alergeni);
	std::vector<std::string> GetIngrediente() const;
	std::vector<std::string> GetAlergeni() const;
	double PretUnitate() const override;
	int GetGramaj() const;
	bool EsteReturnabil() const override;
};