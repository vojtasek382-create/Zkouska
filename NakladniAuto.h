#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Vozidlo.h"

class NakladniAuto : public Vozidlo{

    private:
    double nosnost_v_tunach;

    public:
    NakladniAuto(std::string spz, std::vector<double> historieTankovani, double nosnost_v_tunach);
    virtual void analyzujVozidlo() const override;
    virtual void vypisInfo() const override;
    //Operátor << (Proudový výpis): Umožní výpis nákladního auta např. ve formátu: NakladniAuto [SPZ: ABC-1234, Tankování: X, Nosnost: Y t]
    friend std::ostream& operator<<(std::ostream& os, const NakladniAuto& druhe);

    /*
    Operátor [] (Indexování): Přijme index (size_t) a vrátí hodnotu tankování na zadané pozici v historii. 
    (Operátor nesmí měnit objekt – const).  
    Operátor () (Funktor – Servisní prohlídka): Nemanipuluje s parametry. 
    Při zavolání auto1(); vynuluje / vymaže celou historii tankování auta (např. vynulování počítadla před novou sezónou). 
    */

    double operator[](int index) const;
    void operator()() ;
};