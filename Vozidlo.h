#pragma once

#include <iostream>
#include <string>
#include <vector>

class Vozidlo{

    protected:
    std::string spz;
    std::vector<double> historieTankovani;
    int static pocetVozidel;

    public:
    Vozidlo(std::string spz, std::vector<double> historieTankovani);
    virtual ~Vozidlo();
    std::vector<double>& gethistorieTankovani();
    int static getpocetVozidel();
    double getAktualniTankovani() const;
    void pridejTankovani(double litry);
    void pridejTankovani(const std::vector<double>& litry);
    virtual void analyzujVozidlo() const = 0;
    virtual void vypisInfo() const;
};