#include <iostream>
#include "LuxusniPokoj.h"

LuxusniPokoj :: LuxusniPokoj  
(int cisloPokoje, double cena, double servis, bool welness) : Pokoj(cisloPokoje,cena){
    this->poplatekZaServis = servis;
    this->wellnessVCene = welness;
}

void LuxusniPokoj :: vypis ()const{
    std::cout<<"Luxusni pokoj - Cislo ["<<this->cisloPokoje<<"] cenu za noc ["
    <<*(this->cenaZaNoc)<<"] servisni poplatku ["<<this->poplatekZaServis<<"] wellness["
    <<this->wellnessVCene<<"]."<<std::endl;
}

double LuxusniPokoj :: spoctiCenu(int pocetNoci)const{
    // Základní cena za noci + fixní servis se platí vždy
    double celkovaCena = Pokoj::spoctiCenu(pocetNoci) + this->poplatekZaServis;

    // Pokud je wellness v ceně, přičte se navíc 1000 Kč
    if (this->wellnessVCene) {
        celkovaCena += 1000.0;
    }
    return celkovaCena;
    
}



