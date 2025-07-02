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