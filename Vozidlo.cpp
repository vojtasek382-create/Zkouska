#include <iostream>
#include <string>
#include <vector>

#include "Vozidlo.h"

int Vozidlo::pocetVozidel = 0;

Vozidlo::Vozidlo(std::string spz, std::vector<double> historieJizd)
{
    this -> spz = spz;
    this -> historieJizd = historieJizd;
    pocetVozidel++;
}

Vozidlo::~Vozidlo()
{
    pocetVozidel--;
}

int Vozidlo::getpocetVozidel()
{
    return pocetVozidel;
}

const std::string Vozidlo::getspz()
{
    return spz;
}

std::vector<double> &Vozidlo::gethistorieJizd()
{
    return historieJizd;
}

const std::vector<double> &Vozidlo::gethistorieJizd() const
{
    return historieJizd;
}

void Vozidlo::pridejJizdu(double hodnota)
{
    historieJizd.push_back(hodnota);
}

void Vozidlo::pridejJizdu(const std::vector<double> &hodnoty)
{
    for (int i = 0; i < hodnoty.size(); i++){
        historieJizd.push_back(hodnoty[i]);
    }
}

void Vozidlo::vypisInfo() const
{
    std::cout << "Spz: " << spz << ", pocet zaznamu: " << historieJizd.size() << std::endl;
}