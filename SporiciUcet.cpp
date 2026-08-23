#include <iostream>
#include <string>
#include <vector>
#include "SporiciUcet.h"

SporiciUcet::SporiciUcet(std::string cisloUctu, std::vector<double> historieTransakci, double urokovaSazba) : Ucet (cisloUctu, historieTransakci){
    this -> urokovaSazba = urokovaSazba;
}

//V metodě analyzujUcet() spočítá a vypíše průměrnou hodnotu vkladů (vklad je každá transakce větší než 0).

void SporiciUcet::analyzujUcet() const{
    double suma = 0;
    int pocet_vkladu = 0;
    for (int i = 0; i < historieTransakci.size(); i++){
        if (historieTransakci[i] > 0){
            suma += historieTransakci[i];
            pocet_vkladu++;
        }
    }
    double prumer = 0;
        if (pocet_vkladu == 0){
            prumer = 0;
        } else {
            prumer = suma / pocet_vkladu;
        }
    std::cout << "Prumer vkladu je: " << prumer << std::endl;
}


void SporiciUcet::vypisInfo() const{
    std::cout << "Ucet: " << cisloUctu << " | Pocet transakci: " << historieTransakci.size() << " | Typ uctu: Sporici | Urok: " << urokovaSazba << "%" << std::endl;
}