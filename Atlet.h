#pragma once

#include <iostream>
#include <vector>
#include <string>

class Atlet{

    protected:
    std::string jmeno;
    std::vector<double> historieCasu;
    int static pocetAtletu;

    public:
    Atlet(std::string jmeno, std::vector<double> historieCasu);
    virtual ~Atlet();

    std::string getjmeno() const;
    double getAktualniCas() const;
    std::vector<double>& getHistorieCasu();

    void pridejCas(double cas);
    void pridejCas(const std::vector<double>& casy);

    virtual void vyhodnotFormu() const = 0;
    virtual void vypisInfo() const;

};