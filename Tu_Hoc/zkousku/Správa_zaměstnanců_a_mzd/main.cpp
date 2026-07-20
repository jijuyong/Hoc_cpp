#include <iostream>
#include "Manazer.h"
#include "Zamestnanec.h"
#include <vector>
#include <string>

std::ostream &operator<<(std::ostream &os, const Zamestnanec &zamestnanec){
    zamestnanec.vypis();
    return os;
}

void zvysZaklad(double& aktualniMzda, double castka){
    aktualniMzda+=castka;
}

int main(){
    std::vector <Zamestnanec*> seznam;
    seznam.push_back(new Manazer("Vu Thi Lan Huong",21340.0,1500.0,"IT"));
    seznam.push_back(new Manazer("Vu Thi Lan Huong",23560.0,1500.0,"ChEM"));
    seznam.push_back(new Manazer("Sara Schacherlova",20986.0,3500.0,"ZDRV"));

    for(const Zamestnanec* z : seznam){
        std::cout<<*z <<std::endl;
        std::cout << "Jeho cista mzda je [" << z->spoctiMzda() << "]." << std::endl; 
        std::cout<<std::endl;  
    }
        
    if (*seznam[0] == *seznam[1]){
        std::cout<<"1. zamestnanec = 2. zamestnanec"<<std::endl;
    }else std::cout<<"2 nhan vien khac nhau"<<std::endl;

    for(Zamestnanec* z : seznam){ delete z;}

    seznam.clear();

}