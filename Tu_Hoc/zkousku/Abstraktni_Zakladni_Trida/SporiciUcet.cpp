#include "SporiciUcet.h"
#include <iostream>

SporiciUcet :: SporiciUcet (std::string majitel, double zustatek, double bonus) : BankonvniUcet(majitel,zustatek){
    this->bonusovaSazba = bonus;
}

void SporiciUcet :: VypisInfo()const{
    std::cout<<"Majitel {"<<this->majitel<<"}, zustatek ["
    <<*(this->zustatek)<<"], bonusova sazba ["
    <<this->bonusovaSazba<<"]."<<std::endl;
}

double SporiciUcet :: spoctiUroku()const{
    return BankonvniUcet::spoctiUroku() + (*(this->zustatek)+ bonusovaSazba);
}