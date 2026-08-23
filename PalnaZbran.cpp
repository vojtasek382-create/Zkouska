#include <iostream>
#include <string>
#include "PalnaZbran.h"

PalnaZbran::PalnaZbran (std::string kodOznaceni, double hmotnost, int kadence) : Vybaveni (kodOznaceni, hmotnost){
    this->kadence = kadence;
}

void PalnaZbran::pripravKAkci(){
    std::cout << "* Nabijeni zbrane " << kodOznaceni << ", nastaveni kadence na " << kadence <<" ran/min *"<< std::endl; 
}

PalnaZbran PalnaZbran::operator+ (const PalnaZbran& druha) const{
    std::string novyKod = this-> kodOznaceni + " a " + druha.kodOznaceni;
    double novahmotnost = this-> hmotnost + druha.hmotnost;
    int novakadence = this-> kadence + druha.kadence;
    return PalnaZbran(novyKod, novahmotnost, novakadence);
}