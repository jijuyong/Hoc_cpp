#pragma once
#include <iostream>

class Senzor{
    protected:
    std::string nazev;
    double* namereneHodnoty;
    int pocetMereni;

    public:
    Senzor(std::string nazev, double* naMereneHodnoty, int pocetMereni);
    virtual ~ Senzor();
    virtual void vypis()const =0;
    virtual double vypocetMaxima()const;
    bool operator==(const Senzor &druhy)const;
};