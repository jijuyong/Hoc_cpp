#include "Student.h"
#include <iostream>

Student :: Student (std::string, int* poleZnamek, int pocet){
    this-> pocetZnamek = pocet;
    this->jmeno = jmeno;
    this->znamka = new int[pocet];

    for(int i=0;i<pocet;i++){
        this->znamka[i] = poleZnamek[i];
    }
}

Student:: ~Student (){
    delete[] this->znamka;
}

double Student :: prumer()const{
    double tong = 0.0;
    for(int i=0;i<pocetZnamek;i++){
        tong+= znamka[i];
    }

    return tong/pocetZnamek;
}

