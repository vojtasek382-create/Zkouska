#include <vector>
#include <string>
#include <iostream>
#include "Ucet.h"

int Ucet::pocetUctu = 0;

Ucet::Ucet(std::string cisloUctu, std::vector<double> historieTransakci){
    this-> cisloUctu = cisloUctu;
    this-> historieTransakci = historieTransakci;
    pocetUctu++;
}

Ucet::~Ucet(){
    pocetUctu--;
}

int Ucet::getpocetUctu(){
    return pocetUctu;
}

std::vector<double>& Ucet::gethistorieTransakci(){
    return historieTransakci;
}

void Ucet::pridejTransakci(double hodnota){ 
    historieTransakci.push_back(hodnota);
}

void Ucet::pridejTransakce(const std::vector<double>& hodnoty){

    for (int i = 0; i < historieTransakci.size(); i++){
        historieTransakci.push_back(hodnoty[i]);
    }
}

void Ucet::vypisInfo() const{
    std::cout << "Ucet: " << cisloUctu << " | Pocet transakci: "  << historieTransakci.size() << std::endl;
}
