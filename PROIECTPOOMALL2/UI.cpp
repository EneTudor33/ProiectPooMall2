#include "UI.h"
#include<iostream>
#include<memory>

void MainMenu()
{
	std::cout << "Bine ai venit in sistemul de gestiune al mall-ului! Ce ai dori sa faci?"
		<< std::endl;
	std::cout << "1.Gestioneaza Magazinele" << std::endl;
	std::cout << "2.Gestioneaza Cataloagele" << std::endl;
	std::cout << "3.Gestioneaza Clientii" << std::endl;
	std::cout << "4.Gestioneaza Produsele" << std::endl;
	std::cout << "0.Iesi din program" << std::endl;
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

}
void ClientMenu(Mall& mall)
{

}
void ProdusMenu(Mall& mall)
{

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
			ClientMenu(mall);
			break;
		}
		case 4:
		{
			ProdusMenu(mall);
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