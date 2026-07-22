#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "Ucet.h"


class BeznyUcet : public Ucet{

    private:
    double poplatek;

    public:
    BeznyUcet(std::string cisloUctu, std::vector<double> historieTransakci, double poplatek);
    void analyzujUcet() const override;
    void vypisInfo() const override;

    BeznyUcet& operator+=(double hodnota);
    bool operator==(const BeznyUcet& druhy);
    friend std::ostream& operator<<(std::ostream& os, const BeznyUcet& druhy);

};