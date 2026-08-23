#include <iostream>
#include <string>
#include "Vybaveni.h"

int Vybaveni::pocetKusu = 0;

Vybaveni::Vybaveni(std::string kodOznaceni, double hmotnost){
    this->kodOznaceni = kodOznaceni;
    this->hmotnost = hmotnost;
    pocetKusu++;
}

Vybaveni::~Vybaveni(){
    pocetKusu--;
}

int Vybaveni::getPocetKusu(){
    return pocetKusu;
}

std::ostream& operator << (std::ostream& os, const Vybaveni& v){
    os << v.kodOznaceni << " (hmotnost: " << v.hmotnost << " kg)";
    return os;
}
