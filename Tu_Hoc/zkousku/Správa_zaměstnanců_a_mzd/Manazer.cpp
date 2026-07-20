#include <iostream>
#include "Manazer.h"

Manazer :: Manazer (std::string jmeno, double mzda, double bonus, std::string oddeleni)
: Zamestnanec(jmeno,mzda){
    this->oddeleni = oddeleni;
    this->odmeny = bonus;
}

void Manazer :: vypis()const{
    std::cout<<"Manazer oddeleni ["<<this->oddeleni<<"] {"<<this->jmeno<<"} zakladni mzdy ["
    <<*(this->zakladniMzda)<<"] vysi odmeny["<<this->odmeny<<"].";
}

double Manazer :: spoctiMzda()const{
    if(this->oddeleni== "IT"){
        return (*(this->zakladniMzda)) + (odmeny+5000);
    }else return (*(this->zakladniMzda))+odmeny;
}