#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "Ucet.h"

class SporiciUcet : public Ucet{

    private:
    double urokovaSazba;

    public:
    SporiciUcet(std::string cisloUctu, std::vector<double> historieTransakci, double urokovaSazba);
    void analyzujUcet() const override;
    void vypisInfo() const override;


};