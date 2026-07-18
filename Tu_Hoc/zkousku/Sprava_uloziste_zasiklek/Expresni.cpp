#include <iostream>
#include "Expresni.h"

expresni :: expresni(std::string id, double vaha, int priplatek) : Zasilka(id,vaha){
    this->priplatek= priplatek;
} 

void expresni::vypis()const{
    std::cout<<"Expresni zasilka ID["<<this->id
    <<"], vaha["<<*(this->vaha)<<"]kg,Priplatek["<<this->priplatek<<"]kc"<<std::endl;

}

double expresni :: spoctiCenu()const{
    return Zasilka::spoctiCenu() + this->priplatek;
}