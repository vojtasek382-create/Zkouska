#include <iostream>
#include <vector>
#include <string>

int jeden_krok (int cislo){
    if (cislo % 2 == 0){
        return cislo / 2;
    } else {
        return 3 * cislo + 1;
    } 
}

void cela_posloupnost (int cislo){
    int pocet_kroku = 0;
    while(cislo != 1){
        std::cout << cislo << " -> ";
        cislo = jeden_krok(cislo);
        pocet_kroku++;
    }
    if (cislo == 1){
        std::cout << cislo << std::endl;
        std::cout << "Pocet kroku: " << pocet_kroku << std::endl;
    }
}

int main (void){
    while (true){
        int cislo = 0;
        std::cout << "Zadejte kladne cislo (0 nebo zaporne pro ukonceni): ";
        std::cin >> cislo;
        std::cout << std::endl;
        if (cislo <= 0){
            std::cout << "Konec programu.";
            return 0;
        }
        cela_posloupnost(cislo);
    }
}