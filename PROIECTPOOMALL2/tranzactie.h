#pragma once
#include"data_calendaristica.h"
class Tranzactie {
private:
	DataCalendaristica m_data_tranzactie;
	int m_id_client, m_id_produs, m_cantitate;
	double m_suma_platita;
public:
	Tranzactie(int zi, int luna, int an, int id_client, int produs, int cantitate,double suma_platita);
	DataCalendaristica GetDataTranzactie() const;
	int GetIdClient() const;
	int GetIdProdus() const;
	int GetCantitate() const;
	double GetSumaPlatita() const;
};