#pragma once

#include <vector>
#include <string>
#include <iostream>

class Ucet {

    protected:
    std::string cisloUctu;
    std::vector<double> historieTransakci;
    static int pocetUctu;

    public:
    Ucet(std::string cisloUctu, std::vector<double> historieTransakci);
    virtual ~Ucet();

    static int getpocetUctu();
    std::vector<double>& gethistorieTransakci();

    void pridejTransakci(double hodnota);
    void pridejTransakce(const std::vector<double>& hodnoty);

    virtual void analyzujUcet() const = 0;
    virtual void vypisInfo() const;

};