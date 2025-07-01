#pragma once
#include "hipermarket.h"
#include "client.h"
#include "securitate.h"
#include "casier.h"
#include "bucatar.h"
#include "manager.h"
#include "mancare.h"
#include "bautura.h"
#include "haina.h"
#include "gadget.h"
#include <vector>
#include<memory>
class Mall {
private:
	std::vector<std::shared_ptr<Magazin>> m_magazine;
public:
	void AddMagazin(std::shared_ptr<Magazin> magazin);
};