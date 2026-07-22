#include <vector>
#include <string>
#include <iostream>
#include "Ucet.h"
#include "SporiciUcet.h"
#include "BeznyUcet.h"

void nejdelsiRadaVkladu(Ucet& nazevUctu);
void odstraneniMalychVyberu(Ucet& nazevUctu);


int main(void){

    std::cout << "Pocatecni aktivni ucty: " << Ucet::getpocetUctu() << std::endl;

    // --- 2. Vytvoření vektoru ukazatelů ---
    std::vector<Ucet*> seznamUctu;

    // Dynamická alokace u1, u2, u3
    BeznyUcet* u1 = new BeznyUcet("CZ-1111", {1000.0, 2000.0, -500.0}, 50.0);
    BeznyUcet* u2 = new BeznyUcet("CZ-2222", {500.0, -100.0, -200.0}, 0.0);
    SporiciUcet* u3 = new SporiciUcet("CZ-3333", {5000.0, 10000.0, -2000.0}, 4.5);

    u1->pridejTransakci(-30.0);
    u2->pridejTransakci(1200.0);
    u3->pridejTransakci(3000.0);

    seznamUctu.push_back(u1);
    seznamUctu.push_back(u2);
    seznamUctu.push_back(u3);

    std::cout << "Aktivni ucty po alokaci: " << Ucet::getpocetUctu() << std::endl << std::endl;

    // --- 3. Polymorfní průchod vektorem ---
    std::cout << "--- Pocatecni Polymorfismus a Analyza ---" << std::endl;
    for (size_t i = 0; i < seznamUctu.size(); i++) {
        seznamUctu[i]->vypisInfo();
        seznamUctu[i]->analyzujUcet();
        std::cout << std::endl;
    }

    {
        // --- 4. Test operátorů na LOKÁLNÍCH proměnných (na zásobníku) ---
    std::cout << "\n=== Test operatoru ===" << std::endl;

    // DALI JSME JINÉ NÁZVY (lokA, lokB), aby se nehádaly s u1 a u2 nahoře!
    BeznyUcet lokA("LOKAL-A", {100}, 50);
    BeznyUcet lokB("LOKAL-B", {200, -50}, 40);

    // Test operatoru ==
    if (lokA == lokB) {
        std::cout << "lokA a lokB maji stejne poplatky." << std::endl;
    } else {
        std::cout << "lokA a lokB nemaji stejne poplatky." << std::endl;
    }

    // Test operatoru << a +=
    std::cout << "\n=== Test operatoru += a << ===" << std::endl;
    std::cout << "Pred pridanim: " << lokA << std::endl;

    lokA += 500; // Pridani transakce

    std::cout << "Po pridani:   " << lokA << std::endl;
    }
    
    std::cout << "=== Test algoritmů ===" << std::endl;
    nejdelsiRadaVkladu(*u1);

    std::cout << "Maly vyber (-50 az 0) v u1 po procisteni: ";
    odstraneniMalychVyberu(*u1);
    std::cout << std::endl;


    // --- Úklid paměti ---
    for (size_t i = 0; i < seznamUctu.size(); i++) {
        delete seznamUctu[i];
    }

    std::cout << "Konecny pocet uctu v pameti: " << Ucet::getpocetUctu() << std::endl;

    return 0;
}


// --- Definice algoritmů ---

void nejdelsiRadaVkladu(Ucet& nazevUctu)
{
    int aktualni = 0;
    int nejdelsi = 0;
    std::vector<double>& historie = nazevUctu.gethistorieTransakci(); // Opravený název getteru
    for(size_t i = 0; i < historie.size(); i++)
    {
        if(historie[i] > 0)
        {
            aktualni++;
            if(aktualni > nejdelsi)
            {
                nejdelsi = aktualni;
            }
        }
        else
        {
            aktualni = 0;
        }
    }
    std::cout << "Nejdelsi rada vkladu v danem uctu: " << nejdelsi << std::endl;
}

void odstraneniMalychVyberu(Ucet& nazevUctu)
{
    std::vector<double>& historie = nazevUctu.gethistorieTransakci(); // Opravený název getteru
    for(size_t i = 0; i < historie.size(); i++)
    {
        if(historie[i] < 0 && historie[i] > -50)
        {
            historie.erase(historie.begin() + i);
            i--;
        }
    }
    for(size_t i = 0; i < historie.size(); i++)
    {
        std::cout << historie[i] << " | ";
    }
    std::cout << std::endl;
}