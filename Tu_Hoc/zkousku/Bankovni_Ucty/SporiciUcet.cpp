#include <iostream>
#include <string>
#include <vector>
#include "SporiciUcet.h"

SporiciUcet:: SporiciUcet(std::string cisloUctu, double urokovaSazba)
: Ucet(cisloUctu){
    this->urokovaSazba = urokovaSazba;
}

void SporiciUcet :: vypisInfo()const{
    Ucet::vypisInfo();
    std::cout<<"Urokova sazba ["<<this->urokovaSazba<<"]%."<<std::endl;
}
bool SporiciUcet::operator==(const Ucet& druhy) const 
{
    const SporiciUcet* b = dynamic_cast<const SporiciUcet*>(&druhy);
    return this->urokovaSazba == b->urokovaSazba;
}
void SporiciUcet :: analyzujUcet()const{
    int sum =0; double prumer=0.0;
    for(int i =0; i<historieTransakci.size();i++){
        if (historieTransakci[i] >0){
            sum+=historieTransakci[i];
        }
    }

    prumer = (double)sum/historieTransakci.size();

    std::cout<<"průměrnou hodnotu vkladů: "<<prumer<<"kc"<<std::endl;
}
