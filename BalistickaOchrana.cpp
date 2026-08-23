#include <iostream>
#include <string>
#include "BalistickaOchrana.h"

BalistickaOchrana::BalistickaOchrana(std::string kodOznaceni, double hmotnost, int tridaOdolnosti) : Vybaveni (kodOznaceni, hmotnost){
    this->tridaOdolnosti = tridaOdolnosti;
}

void BalistickaOchrana::pripravKAkci() {
    std::cout << "Kontrola celistvosti balisticke ochrany " << kodOznaceni << " (trida odolnosti: T" << tridaOdolnosti << ")." << std::endl;
}