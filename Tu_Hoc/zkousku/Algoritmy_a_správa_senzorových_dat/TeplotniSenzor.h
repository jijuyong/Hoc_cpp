#include <iostream>
#include "Senzor.h"

class TeplotniSenzor : public Senzor {
    private:
    double kriticatTeplota;

    public:
    TeplotniSenzor(std::string nazev, double* hodnoty, int pocet, double kriticka);
    void vypis()const override;
    int spoctiKritickeStavy()const;
    //spočítá, kolikrát teplota překročila hranici
    double spoctiPrumerBezExtremu()const;
    //spočítá průměr bez nejvyšší a nejnižší hodnoty

};