#include <iostream>
#include <string>
#include <vector>
#include "BeznyUcet.h"

BeznyUcet:: BeznyUcet(std::string cisloUctu,double poplatek) : Ucet(cisloUctu){
    this->poplatek = poplatek;
}

void BeznyUcet :: vypisInfo()const{
    Ucet::vypisInfo();
    std::cout<<"Vysi poplatku ["<<this->poplatek<<"]kc."<<std::endl;
}

void BeznyUcet :: analyzujUcet()const{
    int sum =0;
    for(int i =0; i<historieTransakci.size();i++){
        if(historieTransakci[i]<0){
            sum++;
        }
    }
    std::cout<<"celkový počet provedených výběrů: "<<sum<<std::endl;
}

bool BeznyUcet::operator==(const Ucet& druhy) const 
{
    const BeznyUcet* b = dynamic_cast<const BeznyUcet*>(&druhy);
    return this->poplatek == b->poplatek;



}

BeznyUcet& BeznyUcet :: operator+=(double hodnota){
    this->pridejTransakci(hodnota);
    return *this;
}

std::ostream& operator<<(std::ostream& op, const BeznyUcet& ucet){
    ucet.vypisInfo();
    return op;
}