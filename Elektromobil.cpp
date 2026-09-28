#include <iostream>
#include <string>
#include <vector>

#include "Vozidlo.h"
#include "Elektromobil.h"

Elektromobil::Elektromobil(std::string spz, std::vector<double> historieJizd, double kapacitaBaterie) : Vozidlo(spz, historieJizd)
{
    this -> kapacitaBaterie = kapacitaBaterie;
}

void Elektromobil::vypisInfo() const
{
    std::cout << "Spz: " << spz << ", pocet zaznamu: " << historieJizd.size() << ", kapacita baterie: " << kapacitaBaterie << std::endl;
}

void Elektromobil::analyzujVozidlo() const
{
    int pocet_jizd = 0;

    for (int i = 0; i < historieJizd.size(); i++){
        if (historieJizd[i] < 0.0){
            pocet_jizd++;
        }
    }

    std::cout << "Pocet jizd: " << pocet_jizd << std::endl;
}
