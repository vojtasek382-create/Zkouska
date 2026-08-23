#include <iostream>
#include <string>
#include <vector>
#include "Vozidlo.h"

int Vozidlo::pocetVozidel = 0;

Vozidlo::Vozidlo(std::string spz, std::vector<double> historieTankovani){
    this-> spz = spz;
    this-> historieTankovani = historieTankovani;
    pocetVozidel++;
}

Vozidlo::~Vozidlo(){
    pocetVozidel--;
}

std::vector<double>& Vozidlo::gethistorieTankovani(){
    return historieTankovani;
}

int Vozidlo::getpocetVozidel(){
    return pocetVozidel;
}

double Vozidlo::getAktualniTankovani() const{
    return historieTankovani.back();
}

void Vozidlo::pridejTankovani(double litry){
    historieTankovani.push_back(litry);
}

void Vozidlo::pridejTankovani(const std::vector<double>& litry){
    for (int i = 0; i < litry.size(); i++){
        historieTankovani.push_back(litry[i]);
    }
}
//která vypíše SPZ a počet záznamů v historii tankování.
void Vozidlo::vypisInfo() const{
    std::cout << "Spz: " << spz << " | Pocet zaznamu tankovani: " << historieTankovani.size() << std::endl;
}