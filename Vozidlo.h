#pragma once

#include <iostream>
#include <string>
#include <vector>

class Vozidlo{

    protected:
    std::string spz;
    std::vector<double> historieJizd;
    int static pocetVozidel;

    public:
    Vozidlo(std::string spz, std::vector<double> historieJizd);
    virtual ~Vozidlo();
    int static getpocetVozidel();
    const std::string getspz();
    std::vector<double>& gethistorieJizd();
    const std::vector<double>& gethistorieJizd() const;
    void pridejJizdu(double hodnota);
    void pridejJizdu(const std::vector<double>& hodnoty);
    virtual void analyzujVozidlo() const = 0;
    virtual void vypisInfo() const;



};