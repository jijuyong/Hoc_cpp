#include <iostream>
#include <vector>
#include <string>
#include "BankovniUcet.h"
#include "SporiciUcet.h"

std::ostream& operator<<(std::ostream &os,const BankonvniUcet &bankovniUcet){
    bankovniUcet.VypisInfo();
    return os;
}

void VlozPenize(double& aktualniZustatek, double castka){
    aktualniZustatek+=castka;
}

int main(){
    std::vector <BankonvniUcet*> seznam;
    
    seznam.push_back(new SporiciUcet("Hana",50000.0,4.2));
    seznam.push_back(new SporiciUcet("Stepan",20000.0,3.5));
    seznam.push_back(new SporiciUcet("Sarinka",10000.0,2.1));

    for(const BankonvniUcet* b : seznam){
        std::cout<<*b<<std::endl;

        std::cout << "Rocni uroku: " << b->spoctiUroku() << " Kc" << std::endl;
        std::cout << "------------------------------------------" << std::endl;

        std::cout << "\n--- Porovnani ---" << std::endl;
        if (*seznam[0] == *seznam[1]){
            std::cout << "Majitel {"<<seznam[0]->getMajitel()<<"} ma stejny zustatek jako majitel {"
            <<seznam[1]->getMajitel()<<"}"<<std::endl;
        }else{
            std::cout << "maji ruzne zustatek" << std::endl;
        }

    }

    for(BankonvniUcet* b : seznam){
        delete b;
    }

    seznam.clear();

}