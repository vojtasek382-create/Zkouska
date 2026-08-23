#include <iostream>
#include <string>
#include <vector>
#include "NakladniAuto.h"



NakladniAuto::NakladniAuto(std::string spz, std::vector<double> historieTankovani, double nosnost_v_tunach) : Vozidlo(spz, historieTankovani){
    this-> nosnost_v_tunach = nosnost_v_tunach;
}

void NakladniAuto::analyzujVozidlo() const{
    double sum = 0;
    for (int i = 0; i < historieTankovani.size(); i++){
        if (historieTankovani[i] > 0){
            sum += historieTankovani[i];
        }
    }
    
    std::cout << "Celkove natankovano: " << sum << "litru." << std::endl;
}
//vypisInfo(): Navíc vypíše počet sedadel.  analyzujVozidlo(): Spočítá a vypíše průměrné natankované množství paliva na jedno tankování.  
void NakladniAuto::vypisInfo() const{
    std::cout << "Spz: " << spz << " | Pocet zaznamu tankovani: " << historieTankovani.size() << " Typ: Nakladni | Celkova nosnost: " << nosnost_v_tunach << std::endl;
}
//NakladniAuto [SPZ: ABC-1234, Tankování: X, Nosnost: Y t]
std::ostream& operator<<(std::ostream& os, const NakladniAuto& druhe){
    os << "Nakladni auto " << druhe.spz << ", Tankovani: " << druhe.historieTankovani.size() << ", Nosnost: " << druhe.nosnost_v_tunach << std::endl;
    return os;
}

double NakladniAuto::operator[](int index) const{
    return historieTankovani[index];
}

void NakladniAuto::operator()() {
    historieTankovani.clear(); // Vymaže celý vector
}

