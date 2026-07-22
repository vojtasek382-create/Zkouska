#include <vector>
#include <string>
#include <iostream>
#include "BeznyUcet.h"




BeznyUcet::BeznyUcet(std::string cisloUctu, std::vector<double> historieTransakci, double poplatek) : Ucet (cisloUctu, historieTransakci){
    this->poplatek = poplatek;
}
    //V metodě analyzujUcet() spočítá a vypíše celkový počet provedených výběrů (výběr je každá transakce menší než 0).
void BeznyUcet::analyzujUcet() const {
    int pocet_vyberu = 0;

    for (int i = 0; i < historieTransakci.size(); i++){
        if (historieTransakci[i] < 0){
            
            pocet_vyberu++;
        }
    }

    

    std::cout << "Analyza " << cisloUctu <<": Provedeno " << pocet_vyberu << "vyberu.";
}
void BeznyUcet::vypisInfo() const{
    std::cout << "Ucet: " << cisloUctu << " | Pocet transakci: "  << historieTransakci.size() << "| Poplatek: " << poplatek << std::endl;
}

bool BeznyUcet::operator==(const BeznyUcet& druhy){
    return(poplatek == druhy.poplatek);
}

BeznyUcet& BeznyUcet::operator+=(double hodnota){
    this->historieTransakci.push_back(hodnota);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const BeznyUcet& druhy){
    os << "BeznyUcet " << druhy.cisloUctu << ", transakci: " <<druhy.historieTransakci.size(); 
    return os;
}