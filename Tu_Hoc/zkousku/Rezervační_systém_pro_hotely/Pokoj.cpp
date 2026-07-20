#include <iostream>
#include "Pokoj.h"

Pokoj :: Pokoj(int cisloPokoje, double cenaZaNoc){
    this->cisloPokoje = cisloPokoje;
    this->cenaZaNoc = new double(cenaZaNoc);
}

Pokoj :: ~ Pokoj(){
    delete cenaZaNoc;
}

double Pokoj :: spoctiCenu(int pocetNoci)const{
    return (*(this->cenaZaNoc))*pocetNoci;
}

bool Pokoj :: operator==(const Pokoj &druhy)const{
    return this->cisloPokoje == druhy.cisloPokoje;
}