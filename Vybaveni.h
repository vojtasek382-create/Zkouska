#pragma once

#include <iostream>
#include <string>

class Vybaveni {

    protected:
    std::string kodOznaceni;
    double hmotnost;
    static int pocetKusu;

    public:
    Vybaveni(std::string kodOznaceni, double hmotnost);
    virtual ~Vybaveni();
    static int getPocetKusu();
    virtual void pripravKAkci() = 0;
    friend std::ostream& operator << (std::ostream& os, const Vybaveni& v);
};