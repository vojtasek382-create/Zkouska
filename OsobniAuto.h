#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Vozidlo.h"

class OsobniAuto : public Vozidlo{

    private:
    int pocetSedadel;

    public:
    OsobniAuto(std::string spz, std::vector<double> historieTankovani, int pocetSedadel);
    virtual void analyzujVozidlo() const override;
    virtual void vypisInfo() const override;


};