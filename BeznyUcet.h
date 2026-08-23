#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Ucet.h"

class BeznyUcet : public Ucet{

    private:
    double poplatky;
    
    public:
    BeznyUcet(std::string cisloUctu, std::vector<double> historieTransakci, double poplatky);
    virtual void analyzujUcet() const override;
    virtual void vypisInfo() const override;
    /*
    Operátor == : Porovná dva běžné účty a vrátí true , pokud mají nastavený úplně stejný poplatek .
Operátor += : Přijme desetinné číslo (typu double ) a přidá ho jako novou transakci na konec historie daného účtu. (Například zavoláním
ucet += 500.0; se přidá kladný vklad 500).
Operátor << : Umožní výpis běžného účtu např. ve formátu: BeznyUcet[CISLO], transakci: X .
*/
bool operator==(const BeznyUcet& druhy);
void operator+=(double hodnota);
friend std::ostream& operator<<(std::ostream& os, const BeznyUcet& novy);

/*
1. operator++ (Prefixový inkrement: ++u1)

    Co dělá: Zvýší měsíční poplatek účtu (poplatek) o 10.0 Kč.

    Návratová hodnota: Vrací referenci na upravený objekt (BeznyUcet&).

    Použití v main: ++u1;

2. operator[] (Indexovací operátor pro čtení transakce)

    Co dělá: Vrátí hodnotu transakce z historieTransakci na zadaném indexu (typ double).

    Návratová hodnota: double.

    Důležité: Operátor nesmí měnit objekt (const).

    Použití v main: double prva = u1[0];

3. operator< (Porovnání velikosti poplatků)

    Co dělá: Porovná dva účty a zjistí, zda má levý účet menší poplatek než pravý účet.

    Návratová hodnota: bool (true / false).

    Důležité: Operátor nesmí měnit ani jeden objekt (const).

    Použití v main: if (u1 < u2) { ... }

*/

void operator()();


double operator[](int index) const;

};