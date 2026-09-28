#include <iostream>
#include <string>
#include <vector>

#include "SpalovaciAuto.h"
#include "Vozidlo.h"

SpalovaciAuto::SpalovaciAuto(std::string spz, std::vector<double> historieJizd, double objemNadrze) : Vozidlo(spz, historieJizd)
{
    this -> objemNadrze = objemNadrze;
}

void SpalovaciAuto::vypisInfo() const
{
    std::cout << "Spz: " << spz << ", pocet zaznamu: " << historieJizd.size() << ", objem nadrze: " << objemNadrze << std::endl;
}

void SpalovaciAuto::analyzujVozidlo() const
{
    double prumerNatankovanehoPaliva = 0;
    double suma = 0;
    double pocet_tankovani = 0;
    for (int i = 0; i < historieJizd.size(); i++){
        if (historieJizd[i] > 0.0){
            suma += historieJizd[i];
            pocet_tankovani++;
        }
    }

    prumerNatankovanehoPaliva = suma / pocet_tankovani;

    std::cout << "Prumer natankovaneho paliva: " << prumerNatankovanehoPaliva << std::endl;
}

void SpalovaciAuto::operator+=(double hodnota)
{
    historieJizd.push_back(hodnota);
}

bool SpalovaciAuto::operator==(const SpalovaciAuto &druhy)
{
    if (druhy.objemNadrze == objemNadrze){
        return true;
    } else {
        return false;
    }
}

std::ostream &operator<<(std::ostream& os, const SpalovaciAuto& druhy)
{
    os << "[Spz: " << druhy.spz << ", pocet jizd: " << druhy.gethistorieJizd().size() << ", objem nadrze: " << druhy.objemNadrze << "]";
    return os;
}
