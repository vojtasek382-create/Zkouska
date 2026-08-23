#pragma once

#include <iostream>
#include <string>
#include <vector>




class Ucet {
    protected:
    std::string cisloUctu;
    std::vector<double> historieTransakci;
    int static pocetUctu;

    public:
    Ucet(std::string cisloUctu, std::vector<double> historieTransakci);
    virtual ~Ucet();
    int static getpocetUctu();
    std::vector<double>& gethistorieTransakci();
    void pridejTransakci(double hodnota);
    void pridejTransakce(const std::vector<double>& hodnoty);
    virtual void analyzujUcet() const = 0;
    virtual void vypisInfo() const;

};