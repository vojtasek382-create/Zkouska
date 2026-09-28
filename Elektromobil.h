#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Vozidlo.h"

class Elektromobil : public Vozidlo{

    private:
    double kapacitaBaterie;

    public:
    Elektromobil(std::string spz, std::vector<double> historieJizd,  double kapacitaBaterie);
    virtual void vypisInfo() const override;
    virtual void analyzujVozidlo() const override;
    
};