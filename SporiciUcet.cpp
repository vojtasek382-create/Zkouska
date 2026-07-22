#include <vector>
#include <string>
#include <iostream>
#include "SporiciUcet.h"




SporiciUcet::SporiciUcet(std::string cisloUctu, std::vector<double> historieTransakci, double urokovaSazba) : Ucet (cisloUctu, historieTransakci){
    this->urokovaSazba = urokovaSazba;
}
    //spočítá a vypíše průměrnou hodnotu vkladů (vklad je každá transakce větší než 0).
void SporiciUcet::analyzujUcet() const {
    int pocet_vkladu = 0;
    double suma = 0;
    for (int i = 0; i < historieTransakci.size(); i++){
        if (historieTransakci[i] > 0){
            suma += historieTransakci[i];
            pocet_vkladu++;
        }
    }

    double prumer = 0;
    if (pocet_vkladu == 0){
        suma = 0;
    } else {
        prumer = suma / pocet_vkladu;
    }

    std::cout << "Analyza " << cisloUctu <<": Prumerna vyssi vkladu je: " << prumer << "Kc";
}
void SporiciUcet::vypisInfo() const{
    std::cout << "Ucet: " << cisloUctu << " | Pocet transakci: "  << historieTransakci.size() << "| Urok: " << urokovaSazba << std::endl;
}