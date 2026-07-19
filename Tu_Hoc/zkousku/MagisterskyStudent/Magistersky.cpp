#include "Magistersky.h"
#include <iostream>

MagisterskyStudent:: MagisterskyStudent
(std::string jmeno, int* poleZnamek, int pocet, bool diplom) : Student(jmeno,poleZnamek,pocet){
    this->cervenyDiplom = diplom;
}

void MagisterskyStudent :: vypis()const {
    std::cout <<"Magistersky Student {"<<this->jmeno<<"} prumer znamek ["
    <<prumer()<<"], stav diplom ["<<cervenyDiplom<<"]."<<std::endl;
}

double MagisterskyStudent :: spoctiStidendia()const{
    int stipko =0.0;
    if (cervenyDiplom == true){
        stipko = 5000.0;

    }
    if(prumer()<=1.5  && cervenyDiplom == true){
        stipko+=2000.0;
    }else if (prumer()>1.5 ){ stipko=0.0; }

    return stipko;
}