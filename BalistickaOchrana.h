#pragma once

#include <iostream>
#include <string>
#include "Vybaveni.h"


class BalistickaOchrana : public Vybaveni {

    private:
    int tridaOdolnosti;

    public:
    BalistickaOchrana(std::string kodOznaceni, double hmotnost, int tridaOdolnosti);
    void pripravKAkci() override;

};