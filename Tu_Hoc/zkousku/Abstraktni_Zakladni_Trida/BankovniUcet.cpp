#include "BankovniUcet.h"
#include <iostream>


BankonvniUcet:: BankonvniUcet(std::string majitel, double zustatek){
    this->majitel = majitel;
    this->zustatek  = new double(zustatek);
}

BankonvniUcet:: ~BankonvniUcet(){
    delete this->zustatek;
}

double BankonvniUcet :: spoctiUroku ()const{
    return (*(this->zustatek)*0.01);
}

std::string BankonvniUcet:: getMajitel(){
    return this->majitel;
}

bool BankonvniUcet :: operator==(const BankonvniUcet& druha)const{
    return this->majitel == druha.majitel;
}