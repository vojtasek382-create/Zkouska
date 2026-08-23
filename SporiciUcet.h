#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Ucet.h"

class SporiciUcet : public Ucet{

    private:
    double urokovaSazba;
    
    public:
    SporiciUcet(std::string cisloUctu, std::vector<double> historieTransakci, double urokovaSazba);
    virtual void analyzujUcet() const override;
    virtual void vypisInfo() const override;

};