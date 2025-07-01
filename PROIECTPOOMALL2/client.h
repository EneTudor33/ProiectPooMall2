#pragma once
#include "abonament.h"
#include "om.h"
/*Ne gandim la un client ca un om care poate avea un abonament ce ii permite
sa beneficieze de preturi mai ieftine, sau care poate avea un giftcard primit cadou de la cineva,
acei bani intrand in contul sau
*/

class Client :public Om {
private:
	double m_credit;
	Abonament m_abonament;
public:
	Client(std::string nume, std::string prenume, int varsta, std::string email, double credit = 0);
	Client(std::string nume, std::string prenume, int varsta,
		std::string email, Abonament Abonament, double credit = 0);
	double GetCredit() const;
	Abonament GetAbonament() const;
};
