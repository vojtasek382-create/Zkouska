#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Vozidlo.h"

class SpalovaciAuto : public Vozidlo{

    private:
    double objemNadrze;

    public:
    SpalovaciAuto(std::string spz, std::vector<double> historieJizd, double objemNadrze);
    virtual void vypisInfo() const override;
    virtual void analyzujVozidlo() const override;
    friend std::ostream& operator <<(std::ostream& os, const SpalovaciAuto& druhy);
    void operator +=(double hodnota);
    bool operator == (const SpalovaciAuto& druhy);

};