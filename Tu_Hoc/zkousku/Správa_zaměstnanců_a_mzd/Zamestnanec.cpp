#include <iostream>
#include "Zamestnanec.h"

Zamestnanec :: Zamestnanec(std::string jmeno,double mzda){
    this->jmeno = jmeno;
    this->zakladniMzda = new double(mzda);
}

Zamestnanec ::~ Zamestnanec(){
    delete zakladniMzda;
}

double Zamestnanec:: spoctiMzda()const{
    return (*(this->zakladniMzda))*0.85;
}

bool Zamestnanec ::operator==(const Zamestnanec& druhy)const{
    return this->jmeno == druhy.jmeno;
}