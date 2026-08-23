#include <iostream>
#include <string>
#include <vector>
#include "OsobniAuto.h"



OsobniAuto::OsobniAuto(std::string spz, std::vector<double> historieTankovani, int pocetSedadel) : Vozidlo(spz, historieTankovani){
    this-> pocetSedadel = pocetSedadel;
}

void OsobniAuto::analyzujVozidlo() const{
    double sum = 0;
    double pocet_tankovani = 0;
    for (int i = 0; i < historieTankovani.size(); i++){
        if (historieTankovani[i] > 0){
            sum += historieTankovani[i];
            pocet_tankovani++;
        }
    }
    double prumer = 0;
    if (pocet_tankovani == 0){
        prumer = 0;
    } else {
        prumer = sum / pocet_tankovani;
    }
    std::cout << "Prumerne natankovano: " << prumer << "litru." << std::endl;
}
//vypisInfo(): Navíc vypíše počet sedadel.  analyzujVozidlo(): Spočítá a vypíše průměrné natankované množství paliva na jedno tankování.  
void OsobniAuto::vypisInfo() const{
    std::cout << "Spz: " << spz << " | Pocet zaznamu tankovani: " << historieTankovani.size() << "| Aktualni tankovani: " << getAktualniTankovani()<<" Typ: Osobni | Pocet sedadel: " << pocetSedadel << std::endl;
}