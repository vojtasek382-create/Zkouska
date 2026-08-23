#include <iostream>
#include <vector>
#include <string>
#include "Atlet.h"


int Atlet::pocetAtletu = 0;

Atlet::Atlet(std::string jmeno, std::vector<double> historieCasu){
    this -> jmeno = jmeno;
    this-> historieCasu = historieCasu;
    pocetAtletu++;
}

Atlet::~Atlet(){
    pocetAtletu--;
}

std::string Atlet::getjmeno() const{
    return jmeno;
}

double Atlet::getAktualniCas() const{
    historieCasu.back();
}

std::vector<double>& Atlet::getHistorieCasu(){
    return historieCasu;
}

void Atlet::pridejCas(double cas){
    historieCasu.push_back(cas);
}

void Atlet::pridejCas(const std::vector<double> &casy){
    for (int i = 0; i < casy.size(); i++){
        historieCasu.push_back(casy[i]);
    }
}

void Atlet::vypisInfo() const{
    std::cout << "Jmeno: " << jmeno << " | Pocet zavodu: " << historieCasu.size() << " | Aktualni cas: " << getAktualniCas() << std::endl;
}
