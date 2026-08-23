#include <iostream>
#include <string>
#include <vector>
#include "BeznyUcet.h"

BeznyUcet::BeznyUcet(std::string cisloUctu, std::vector<double> historieTransakci, double poplatky) : Ucet (cisloUctu, historieTransakci){
    this -> poplatky = poplatky;
}

//metodě analyzujUcet() spočítá a vypíše celkový počet provedených výběrů (výběr je každá transakce menší než 0).

void BeznyUcet::analyzujUcet() const{
    double suma = 0;
    int pocet_vyberu = 0;
    for (int i = 0; i < historieTransakci.size(); i++){
        if (historieTransakci[i] < 0){
            pocet_vyberu ++;
        }
    }
    std::cout << "Pocet vyberu je: " << pocet_vyberu << std::endl;
}
bool BeznyUcet::operator==(const BeznyUcet& druhy){
    return (poplatky == druhy.poplatky);
}

void BeznyUcet::operator+=(double hodnota){
    historieTransakci.push_back(hodnota);
}
std::ostream& operator<<(std::ostream& os, const BeznyUcet& novy){
    os << "BeznyUcet" << novy.cisloUctu << ", pocet transakci: " << novy.historieTransakci.size() << ", poplatky: " << novy.poplatky << std::endl;
    return os;
}

void BeznyUcet::vypisInfo() const{
    std::cout << "Ucet: " << cisloUctu << " | Pocet transakci: " << historieTransakci.size() << " | Typ uctu: Bezny | Poplatek: " << poplatky << "Kc." << std::endl;
}

void BeznyUcet::operator()(){
    historieTransakci.push_back(-poplatky);
}

double BeznyUcet::operator[](int index) const{
    return historieTransakci[index];
}