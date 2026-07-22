#include <iostream>
#include <string>
#include <vector>
#include "Ucet.h"

Ucet :: Ucet(std::string cisloUctu){
    this->cisloUctu = cisloUctu;
    citac++;
} 

int Ucet :: getInt(){
    return citac;
}

void Ucet::pridejTransakci(double hodnota) {
    historieTransakci.push_back(hodnota);
}

void Ucet::pridejTransakci(const std::vector<double>& hodnoty) {
    for (double h : hodnoty) {
        historieTransakci.push_back(h);
    }
}
std::ostream& operator<<(std::ostream& op, const Ucet& ucet){
    ucet.vypisInfo();
    return op;
}

const std::vector<double>& Ucet :: getter()const{
    return this->historieTransakci;
}

Ucet :: ~ Ucet(){ citac--;}

void Ucet :: vypisInfo()const{
    std::cout<<"BK: ["<<this->cisloUctu<<"] pocet transakci: ["<<this->historieTransakci.size()<<"] ";
}






