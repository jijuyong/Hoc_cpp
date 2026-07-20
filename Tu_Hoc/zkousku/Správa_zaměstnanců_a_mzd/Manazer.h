#include <iostream>
#include "Zamestnanec.h"

class Manazer : public Zamestnanec{
    private:
    double odmeny;// fixní manažerský bonus (v Kč)
    std::string oddeleni;//název oddělení, které manažer vede (např. "IT", "HR")

    public:
    Manazer(std::string jmeno,double mzda, double odmeny, std::string oddeleni);
    void vypis()const override;
    double spoctiMzda()const override;
};