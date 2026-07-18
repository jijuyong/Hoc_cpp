#include "Zasilka.h"

Zasilka::Zasilka(std::string id, double vaha){
    double *pDouble = new double();
    this->id = id;
    this->vaha = new double(vaha);// dymnamicke alokace
}

Zasilka:: ~Zasilka(){
    delete this->vaha;
}

double Zasilka ::spoctiCenu()const{
    return (*(this->vaha))*50.0;
}

// Porovnání dvou zásilek podle jejich ID řetězce
bool Zasilka:: operator==(const Zasilka& druha)const{
    return this->id == druha.id;
}