#include <iostream>
#include <string>
#include <vector>
#include "Vozidlo.h"
#include "OsobniAuto.h"
#include "NakladniAuto.h"


void skok(Vozidlo& nazevVozidla){
    std::vector<double>& Historie = nazevVozidla.gethistorieTankovani();

    double nejvetsi_skok = 0;
    for (size_t i = 0; i + 1 < Historie.size(); i++) {
        double rozdil = Historie[i+1] - Historie[i];
        if (rozdil > nejvetsi_skok) {
            nejvetsi_skok = rozdil;
        }
    }
    
    std::cout << "Nejvetsi skok mezi tankovanim je: " << nejvetsi_skok << std::endl;
}

void mazani(Vozidlo& nazevVozidla){
    std::vector<double>& Historie = nazevVozidla.gethistorieTankovani();

    for(int i = 0; i < Historie.size(); i++){
        if (Historie[i] > 100){
            Historie.erase(Historie.begin() + i);
            i--;
        }
    }
    

    for(int i = 0; i < Historie.size(); i++){
        std::cout << Historie[i] << " | ";
    }
    std::cout << std::endl;
}
/*
Vypište počáteční počet aktivních vozidel (měl by být 0).
Vytvořte std::vector<Vozidlo*>. Do vektoru vložte (přes operátor new) alespoň 2 nákladní auta a 1 osobní auto. Každému autu přidejte nějaká tankování.  
Projděte tento vektor běžným cyklem a u každého auta zavolejte vypisInfo() a analyzujVozidlo() (ukázka polymorfismu).  
Algoritmus 1 (Největší skok v tankování): Napište funkci, která dostane vozidlo a projde jeho historii. Zjistí a vypíše největší rozdíl (nárůst) mezi dvěma po sobě následujícími tankováními (např. pokud auto natankovalo 20.0 litrů a hned příště 70.0 litrů, skok je 50.0 litrů).  
ých tankování): Napište funkci, která projde vozidlo a vymaže z jeho historie všechna tankování, která byla vyšší než 100 litrů (např. chyba obsluhy nebo tankování do externích kanystrů).  
Otestujte přetížení operátorů (<<, [], ()) na lokálních objektech vytvořených na zásobníku.  Algoritmus 2 (Odstranění nadměrn
Nezapomeňte uvolnit veškerou paměť, kterou jste pomocí new alokovali, a na konci vypište přes statickou metodu stav čítače, aby bylo vidět, že v paměti nic nezůstalo (0).  
*/

int main(void){

    std::cout << "Pocet aktivnich vozidel: " << Vozidlo::getpocetVozidel() << std::endl;

    std::vector<Vozidlo*> seznamAut;
    OsobniAuto* v1 = new OsobniAuto("5T5 5769", {50, 130, 100}, 5);
    OsobniAuto* v2 = new OsobniAuto("2T8 5162", {60, 20, 35, 20}, 8);
    NakladniAuto* v3 = new NakladniAuto("6T5 4878", {300, 150, 200}, 15.5);

    seznamAut.push_back(v1);
    seznamAut.push_back(v2);
    seznamAut.push_back(v3);
    

    for (int i = 0; i < seznamAut.size(); i++){
        seznamAut[i] -> vypisInfo();
        seznamAut[i] -> analyzujVozidlo();
    }

    std::cout << "Pocet aktivnich vozidel: " << Vozidlo::getpocetVozidel() << std::endl;

    skok(*v1);
    mazani(*v1);
    

    {

        
        NakladniAuto n1 =  NakladniAuto("6T5 4878", {300, 150, 200}, 15.5);

        std::cout << n1 << std::endl;
        std::cout << "Na indexu mame: " << n1[0] << std::endl;
        n1.pridejTankovani({50, 30});
    }


    for (int i = 0; i < seznamAut.size(); i++){
        delete seznamAut[i];
    }

    std::cout << "Pocet aktivnich vozidel: " << Vozidlo::getpocetVozidel() << std::endl;
}