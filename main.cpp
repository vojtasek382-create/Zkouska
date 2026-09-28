#include <iostream>
#include <string>
#include <vector>

#include "Vozidlo.h"
#include "SpalovaciAuto.h"
#include "Elektromobil.h"

int nejdelsiRadaTankovani(const Vozidlo& vozidlo){

    const std::vector<double>& Historie = vozidlo.gethistorieJizd();
    int nejdelsi_rada = 0;
    int soucasna_nejdelsi_rada = 0;
    for (int i = 0; i < Historie.size(); i++){
        if (Historie[i] > 0.0){
            soucasna_nejdelsi_rada++;
            if (soucasna_nejdelsi_rada > nejdelsi_rada){
                nejdelsi_rada = soucasna_nejdelsi_rada;
            }
        } else{
            soucasna_nejdelsi_rada = 0;
        }
    }
    return nejdelsi_rada;
}

void vycistiDrobneJizdy(Vozidlo& vozidlo){
    std::vector<double>& Historie = vozidlo.gethistorieJizd();

    for (int i = 0; i < Historie.size();){
        if (Historie[i] < 0 && Historie[i] > -4.99){
            Historie.erase(Historie.begin() + i);
        }
        else{
            ++i;
        }
    }

}



int main(void){

    std::cout << "Pocet vozidel: " << Vozidlo::getpocetVozidel() << std::endl;

    std::vector<Vozidlo*> seznamVozidel;

    SpalovaciAuto *s1 = new SpalovaciAuto("4T5 8468", {60.0, 50.0, -40.0, -45.5, 20}, 60.0);
    SpalovaciAuto *s2 = new SpalovaciAuto("8S5 1899", {40.0, -20.0, 35.5}, 40.0);
    Elektromobil *e1 = new Elektromobil("5Z5 4194", {200.0, -150.0, 100.0}, 200.0);

    seznamVozidel.push_back(s1);
    seznamVozidel.push_back(s2);
    seznamVozidel.push_back(e1);

    for (int i = 0; i < seznamVozidel.size(); i++){
        seznamVozidel[i] -> vypisInfo();
        seznamVozidel[i] -> analyzujVozidlo();
    }

    std::cout << "Pocet vozidel: " << Vozidlo::getpocetVozidel() << std::endl;

    std::cout << "Nejdelsi rada: " << nejdelsiRadaTankovani(*s1) << std::endl;
    {
        SpalovaciAuto s1 =  SpalovaciAuto("4T5 8468", {60.0, -45.5, 20}, 60.0);
        SpalovaciAuto s2 =  SpalovaciAuto("8S5 1899", {40.0, -20.0, 35.5}, 60.0);
        Elektromobil e1 =  Elektromobil("5Z5 4194", {200.0, -150.0, 100.0}, 200.0);

        std::cout << s1 << std::endl;
        std::cout << "Jsou nadrze stejne? " << (s1 == s2);
        s1+=(100);
    }

    for (int i = 0; i < seznamVozidel.size(); i++){
        delete seznamVozidel[i];
    }

    std::cout << "Pocet vozidel: " << Vozidlo::getpocetVozidel() << std::endl;
}