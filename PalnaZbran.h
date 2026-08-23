#pragma once

#include <iostream>
#include <string>
#include "Vybaveni.h"

class PalnaZbran : public Vybaveni {

    protected:
    int kadence;

    public:
    PalnaZbran(std::string kodOznaceni, double hmotnost, int kadence);
    void pripravKAkci() override;
    PalnaZbran operator+(const PalnaZbran& druha) const;

};