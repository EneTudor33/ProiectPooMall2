#include "tranzactie.h"

Tranzactie::Tranzactie(int zi, int luna, int an, int id_client, int produs, int cantitate,double suma_platita):
	m_id_client(id_client),m_id_produs(produs),m_cantitate(cantitate),m_suma_platita(suma_platita)
{
	m_data_tranzactie.zi = zi;
	m_data_tranzactie.luna = luna;
	m_data_tranzactie.an = an;
}
DataCalendaristica Tranzactie::GetDataTranzactie() const
{
	return m_data_tranzactie;
}
int Tranzactie::GetIdClient() const
{
	return m_id_client;
}
int Tranzactie::GetIdProdus() const
{
	return m_id_produs;
}
int Tranzactie::GetCantitate() const
{
	return m_cantitate;
}
double Tranzactie::GetSumaPlatita() const
{
	return m_suma_platita;
}