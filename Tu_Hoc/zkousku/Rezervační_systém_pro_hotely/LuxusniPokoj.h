#include <iostream>
#include "Pokoj.h"

class LuxusniPokoj : public Pokoj{
    private:
    bool wellnessVCene; //příznak, zda má host přístup do hotelového spa/wellness
    double poplatekZaServis;

    public:
    LuxusniPokoj (int cisloPokoje, double cena, double servis, bool welness);
    void vypis()const override;
    double spoctiCenu(int pocetNoci)const override;
};