#include "UI.h"
#include<iostream>
#include<memory>

void MainMenu()
{
	std::cout << "Bine ai venit in sistemul de gestiune al mall-ului! Ce ai dori sa faci?"
		<< std::endl;
	std::cout << "1.Gestioneaza Magazinele" << std::endl;
	std::cout << "2.Gestioneaza Cataloagele" << std::endl;
	std::cout << "3.Gestioneaza Angajatii" << std::endl;
	std::cout << "4.Gestioneaza Stocul" << std::endl;
	std::cout << "5.Afiseaza valorea produselor" << std::endl;
	std::cout << "6.Gestioneaza clientii" << std::endl;
	std::cout << "7.Gestioneaza tranzactii" << std::endl;
	std::cout << "0.Iesi din program" << std::endl;
}
void ShowStocMenu()
{
	std::cout << "Ce ai dori sa gestionezi in privinta stocului?" << std::endl;
	std::cout << "1.Schimba stocul unui produs al unui magazin" << std::endl;
	std::cout << "2.Afiseaza stocul unui produs al unui magazin" << std::endl;
	std::cout << "0. Inapoi" << std::endl;
}
void ShowMagazinMenu()
{
	std::cout << "Ce ai dori sa gestionezi in privinta magazinelor?" << std::endl;
	std::cout << "1.Adauga un magazin" << std::endl;
	std::cout << "2.Afiseaza magazinele" << std::endl;
	std::cout << "0. Inapoi" << std::endl;
}
void ShowCataloageMenu()
{
	std::cout << "Ce ai dori sa gestionezi in privinta cataloagelor?" << std::endl;
	std::cout << "1. Adauga produse in catalogul unui magazin" << std::endl;
	std::cout << "2. Afiseaza catalogul unui magazin" << std::endl;
	std::cout << "0. Inapoi" << std::endl;
}
void ShowAngajatiMenu()
{
	std::cout << "Ce ai dori sa gestionezi in privinta angajatilor?" << std::endl;
	std::cout << "1. Adauga angajati in echipa unui magazin" << std::endl;
	std::cout << "2. Afiseaza angajatii unui magazin" << std::endl;
	std::cout << "0. Inapoi" << std::endl;
}
void ShowValoareProduseMenu()
{
	std::cout << "1.Afiseaza calculul valorii produselor unui magazin" << std::endl;
	std::cout << "2.Afiseaza calculul valorii produselor intregului mall" << std::endl;
	std::cout << "0.Inapoi" << std::endl;
}
void ShowClientiMenu()
{
	std::cout << "Ce vrei sa gestionezi in privinta clientilor?" << std::endl;
	std::cout << "1.Creaza un client" << std::endl;
	std::cout << "2.Afiseaza toti clientii" << std::endl;
	std::cout << "3.Schimba balanta unui client" << std::endl;
	std::cout << "0.Inapoi" << std::endl;
}
void ShowTranzactieMenu()
{
	std::cout << "1.Cumpara un produs" << std::endl;
	std::cout << "2.Returneaza un produs" << std::endl;
	std::cout << "3.Afiseaza vanzarile totale ale unui magazin" << std::endl;
	std::cout << "0.Inapoi" << std::endl;
}
void MagazinMenu(Mall& mall)
{
	bool back = false;
	while (!back)
	{
		ShowMagazinMenu();
		int op;
		std::cin >> op;
		std::cin.ignore();
		switch (op)
		{
		case 1:
		{
			std::cout << "Numele magazinului:" << std::endl;
			std::string nume;
			std::getline(std::cin, nume);
			std::cout << "La ce etaj se afla magazinul?" << std::endl;
			int etaj;
			std::cin >> etaj;
			std::cin.ignore();
			std::cout << "E deschis magazinul? 0/1" << std::endl;
			bool deschis;
			std::cin >> deschis;
			std::cin.ignore();
			std::cout << "Ce fel de magazin este?" << std::endl;
			std::cout << "1.Magazin de Mancare" << std::endl;
			std::cout << "2.Magazin de Haine" << std::endl;
			std::cout << "3.Magazin de Electronice" << std::endl;
			std::cout << "4.Hipermaket" << std::endl;
			std::cout << "0.Anulare" << std::endl;
			int optiune;
			std::cin >> optiune;
			std::cin.ignore();
			switch (optiune)
			{
			case 1:
			{
				auto m = std::make_shared<MagazinMancare>(nume, etaj, deschis);
				mall.AddMagazin(m);
				break;
			}
			case 2:
			{
				auto m = std::make_shared<MagazinHaine>(nume, etaj, deschis);
				mall.AddMagazin(m);
				break;
			}
			case 3:
			{
				auto m = std::make_shared<MagazinElectronice>(nume, etaj, deschis);
				mall.AddMagazin(m);
				break;
			}
			case 4:
			{
				auto m = std::make_shared<Hipermarket>(nume, etaj, deschis);
				mall.AddMagazin(m);
				break;
			}
			case 0:
			{
				back = true;
				break;
			}
			default:
			{
				std::cout << "Varianta invalida!" << std::endl;
			}
			}
			break;
		}
		case 2:
		{
			mall.AfisMagazin();
			break;
		}
		case 0:
		{
			back = true;
		}
		}
	}
}
void AngajatMenu(Mall& mall)
{
	bool back = false;
	while (!back)
	{
		ShowAngajatiMenu();
		int op;
		std::cin >> op;
		std::cin.ignore();
		switch (op)
		{
		case 1:
		{
			mall.AfisMagazin();
			std::cout << "ID-ul magazinului caruia vrei sa ii adaugi un angajat:" << std::endl;
			int id;
			std::cin >> id;
			std::cin.ignore();
			std::shared_ptr<Magazin> magazin = mall.GetMagazinID(id);
			if (!magazin)
			{
				std::cout << "Acest magazin nu exista!" << std::endl;
			}
			else
			{
				magazin->AdaugaAngajat();
			}
			break;
		}
		case 2:
		{
			mall.AfisMagazin();
			std::cout << "ID-ul magazinului caruia vrei sa ii adaugi un angajat:" << std::endl;
			int id;
			std::cin >> id;
			std::cin.ignore();
			std::shared_ptr<Magazin> magazin = mall.GetMagazinID(id);
			if (!magazin)
			{
				std::cout << "Acest magazin nu exista!" << std::endl;
			}
			else
			{
				magazin->AfiseazaAngajat();
			}
			break;
		}
		case 0:
		{
			back = true;
			break;
		}
		default:
		{
			std::cout << "Optiune invalida!" << std::endl;
		}
		}
	}
}
void StocMenu(Mall& mall)
{
	bool back = false;
	while (!back)
	{
		ShowStocMenu();
		int op;
		std::cin >> op;
		std::cin.ignore();
		switch (op)
		{
		case 1:
		{
			mall.AfisMagazin();
			std::cout << "Scrie id-ul magazinului caruia vrei sa ii modifici un produs din stoc" << std::endl;
			int id_magazin;
			std::cin >> id_magazin;
			std::cin.ignore();
			std::shared_ptr<Magazin> magazin=mall.GetMagazinID(id_magazin);
			magazin->AfiseazaCatalog();
			std::cout << "Scrie id-ul produsului al carui stoc vrei sa il modifici" << std::endl;
			int id_produs;
			std::cin >> id_produs;
			std::cin.ignore();
			std::cout << "Scrie noua cantitate" << std::endl;
			int cantitate;
			std::cin >> cantitate;
			std::cin.ignore();
			magazin->ModificaStoc(id_produs, cantitate);
			break;
		}
		case 2:
		{
			mall.AfisMagazin();
			std::cout << "Scrie id-ul magazinului caruia vrei sa ii verifici un produs din stoc" << std::endl;
			int id_magazin;
			std::cin >> id_magazin;
			std::cin.ignore();
			std::shared_ptr<Magazin> magazin = mall.GetMagazinID(id_magazin);
			magazin->AfiseazaCatalog();
			std::cout << "Scrie id-ul produsului al carui stoc vrei sa il verifici" << std::endl;
			int id_produs;
			std::cin >> id_produs;
			std::cin.ignore();
			int stoc=magazin->GetStoc(id_produs);
			if (stoc>=0)
			{
				std::cout << "Produsul mai are in stoc " << stoc << " unitati" << std::endl;
			}
			break;
		}
		case 0:
		{
			back = true;
		}
		default:
		{
			std::cout << "Optiune invalida!" << std::endl;
		}
		}
	}
}
void CataloageMenu(Mall& mall)
{
	bool back = false;
	while (!back)
	{
		ShowCataloageMenu();
		int op;
		std::cin >> op;
		std::cin.ignore();
		switch (op)
		{
		case 1:
		{
			mall.AfisMagazin();
			std::cout << "Scrie ID-ul magazinului caruia vrei sa ii gestionezi catalogul" << std::endl;
			int id;
			std::cin >> id;
			std::cin.ignore();
			std::shared_ptr<Magazin> magazin = mall.GetMagazinID(id);
			if (magazin)
			{
				magazin->AdaugaProdus();
			}
			else
				std::cout << "Magazinul nu exista!" << std::endl;
			break;
		}
		case 2:
		{
			mall.AfisMagazin();
			std::cout << "Scrie ID-ul magazinului caruia vrei sa ii gestionezi catalogul" << std::endl;
			int id;
			std::cin >> id;
			std::cin.ignore();
			std::shared_ptr<Magazin> magazin = mall.GetMagazinID(id);
			if (magazin)
			{
				magazin->AfiseazaCatalog();
			}
			else
				std::cout << "Magazinul nu exista!" << std::endl;
			break;
		}
		case 0:
		{
			back = true;
			break;
		}
		default:
		{
			std::cout << "Optiune invalida!" << std::endl;
		}
		}
	}
	
}
void ValoareProduseMenu(Mall& mall)
{
	bool back = false;
	while (!back)
	{
		ShowValoareProduseMenu();
		int op;
		std::cin >> op;
		std::cin.ignore();
		switch (op)
		{
		case 1:
		{
			mall.AfisMagazin();
			std::cout << "Scrie ID-ul magazinului al carui valoare a produselor vrei sa il aflii" << std::endl;
			int id_magazin;
			std::cin >> id_magazin;
			std::cin.ignore();
			std::shared_ptr<Magazin> magazin=mall.GetMagazinID(id_magazin);
			std::cout << "Valoarea produselor din magazinul cerut este de " << magazin->CalculValoareProduse() << " lei" << std::endl;
			break;
		}
		case 2:
		{
			int suma = 0;
			std::vector<std::shared_ptr<Magazin>> magazine = mall.GetMagazine();
			for (const auto& m : magazine)
			{
				suma = suma + m->CalculValoareProduse();
			}
			std::cout << "Valoarea produselor din mall este de " << suma << " lei" << std::endl;
			break;
		}
		case 0:
		{
			back = true;
			break;
		}
		default:
		{
			std::cout << "Optiune invalida!" << std::endl;
		}
		}
	}
}
void ClientiMenu(Mall& mall)
{
	bool back = false;
	while (!back)
	{
		ShowClientiMenu();
		int op;
		std::cin >> op;
		std::cin.ignore();
		switch (op)
		{
		case 1:
		{
			std::string nume, prenume, email;
			int varsta;
			double credit;
			std::cout << "Nume:" << std::endl;
			std::getline(std::cin, nume);
			std::cout << "Prenume:" << std::endl;
			std::getline(std::cin, prenume);
			std::cout << "Email:" << std::endl;
			std::getline(std::cin, email);
			std::cout << "Varsta:" << std::endl;
			std::cin >> varsta;
			std::cin.ignore();
			std::cout << "Credit:" << std::endl;
			std::cin >> credit;
			std::cin.ignore();
			bool optiune;
			std::cout << "Detine abonament?0/1" << std::endl;
			std::cin >> optiune;
			std::cin.ignore();
			if (optiune == 0)
			{
				Client client(nume, prenume, varsta, email, credit);
				mall.AddClient(client);
			}
			else
			{
				std::string denumire_abonament;
				int discount;
				std::cout << "Denumire abonament:" << std::endl;
				std::getline(std::cin, denumire_abonament);
				std::cout << "Discount:" << std::endl;
				std::cin >> discount;
				std::cin.ignore();
				Abonament abonament;
				abonament.discount = discount;
				abonament.nume_abonament = denumire_abonament;
				Client client(nume, prenume, varsta, email, abonament,credit);
				mall.AddClient(client);
			}
			break;
		}
		case 2:
		{
			mall.ShowClient();
			break;
		}
		case 3:
		{
			mall.ShowClient();
			std::cout << "Scrie ID-ul clientului al carui credit vrei sa il schimbi" << std::endl;
			int id;
			std::cin >> id;
			std::cin.ignore();
			Client* client=mall.GetClientID(id);
			if (client)
			{
				std::cout << "Credit nou:" << std::endl;
				double credit;
				std::cin >> credit;
				std::cin.ignore();
				client->SetCredit(credit);
			}
			else
			{
				std::cout << "Clientul nu exista!" << std::endl;
			}
			break;
		}
		case 0:
		{
			back = true;
			break;
		}
		default:
		{
			std::cout << "Optiune invalida!" << std::endl;
		}
		}

	}
}
void TranzactieMenu(Mall& mall)
{
	bool back = false;
	while (!back)
	{
		ShowTranzactieMenu();
		int op;
		std::cin >> op;
		std::cin.ignore();
		switch (op)
		{
		case 1:
		{
			mall.AfisMagazin();
			std::cout << "Scrie id-ul magazinului din care vrei sa cumperi" << std::endl;
			int id_magazin, id_client, id_produs, cantitate, zi, luna, an;
			std::cin >> id_magazin;
			std::cin.ignore();
			mall.ShowClient();
			std::cout << "Scrie id-ul clientului care cumpara" << std::endl;
			std::cin >> id_client;
			std::cin.ignore();
			std::shared_ptr<Magazin> magazin = mall.GetMagazinID(id_magazin);
			magazin->AfiseazaCatalog();
			std::cout << "Scrie id-ul produsului cumparat" << std::endl;
			std::cin >> id_produs;
			std::cin.ignore();
			std::cout << "Cantitate:" << std::endl;
			std::cin >> cantitate;
			std::cin.ignore();
			std::cout << "Ziua cumparaturii:" << std::endl;
			std::cin >> zi;
			std::cin.ignore();
			std::cout << "Luna cumparaturii:" << std::endl;
			std::cin >> luna;
			std::cin.ignore();
			std::cout << "Anul cumparaturii:" << std::endl;
			std::cin >> an;
			std::cin.ignore();
			if (mall.AddTranzactie(id_magazin, id_client, id_produs, cantitate, zi, luna, an))
				std::cout << "Tranzactie procesata cu succes!" << std::endl;
			break;
		}
		case 2:
		{
			mall.AfisMagazin();
			std::cout << "ID Magazin:" << std::endl;
			int id_magazin;
			std::cin >> id_magazin;
			std::cin.ignore();
			std::vector<Tranzactie> tranzactii = mall.GetTranzactiiMagazin(id_magazin);
			if (tranzactii.empty())
			{
				std::cout << "Magazinul nu are tranzactii!" << std::endl;
			}
			for (int i = 0;i < (int)tranzactii.size(); i++)
			{
				std::cout << "|ID Tranzactie:" << i << "|ID Produs:" << tranzactii[i].GetIdProdus() << "|Cantitate:"
					<< tranzactii[i].GetCantitate() << "|Suma:" << tranzactii[i].GetCantitate() << std::endl;
			}
			std::cout << "Id-ul tranzactiei care o returnam:" << std::endl;
			int id_tranzactie;
			std::cin >> id_tranzactie;
			std::cin.ignore();
			if (mall.ReturTranzactie(id_magazin, id_tranzactie))
				std::cout << "Tranzactie returnata cu succes!" << std::endl;
			else
				std::cout << "Eroare!" << std::endl;
			break;
		}
		case 3:
		{
			mall.AfisMagazin();
			std::cout << "Id magazin:" << std::endl;
			int id_magazin;
			std::cin >> id_magazin;
			std::cin.ignore();
			std::cout<<"Magazinul a avut vanzari in valoare de "<<mall.GetVanzariMagazin(id_magazin)
			<<" lei"<<std::endl;
		}
		case 0:
		{
			back = true;
			break;
		}
		default:
		{
			std::cout << "Optiune invalida!" << std::endl;
		}
		}
	}
}
void RunUI(Mall& mall)
{
	bool back = false;
	while (!back)
	{
		MainMenu();
		int op;
		std::cin >> op;
		std::cin.ignore();
		switch (op)
		{
		case 1:
		{
			MagazinMenu(mall);
			break;
		}
		case 2:
		{
			CataloageMenu(mall);
			break;
		}
		case 3:
		{
			AngajatMenu(mall);
			break;
		}
		case 4:
		{
			StocMenu(mall);
			break;
		}
		case 5:
		{
			ValoareProduseMenu(mall);
			break;
		}
		case 6:
		{
			ClientiMenu(mall);
			break;
		}
		case 7:
		{
			TranzactieMenu(mall);
			break;
		}
		case 0:
		{
			back = true;
			break;
		}
		default:
		{
			std::cout << "Optiune invalida!" << std::endl;
		}
		}
	}


}