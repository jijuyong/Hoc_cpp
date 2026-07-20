#include <iostream>
#include "Senzor.h"

Senzor :: Senzor (std::string nazev, double* hodnoty, int pocetMereni){
    this->nazev = nazev;
    this->pocetMereni = pocetMereni;

    this->namereneHodnoty = new double[pocetMereni];
    for (int i = 0; i < pocetMereni; i++) {
        this->namereneHodnoty[i] = hodnoty[i];
    }
    
}

Senzor ::~ Senzor(){
    delete[] namereneHodnoty;
}

double Senzor :: vypocetMaxima()const{
    int index_max = 0;
    for (int i = 0; i < pocetMereni; i++){
        if(namereneHodnoty[i]> namereneHodnoty[index_max]){
            index_max = i;
        }
    }
    if (pocetMereni == 0){
        return 0.0;
    } else return namereneHodnoty[index_max];
}

bool Senzor::operator==(const Senzor& druhy) const {
    return this->nazev == druhy.nazev;
}









