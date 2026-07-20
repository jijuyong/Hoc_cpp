#include <vector>
#include <string>
#include "Pokoj.h"
#include "LuxusniPokoj.h"

std::ostream &operator<<(std::ostream &os, const Pokoj &pokoj){
    pokoj.vypis();
    return os;
}

void  upravuCenu(double& aktualniCenu, double novacena){
    aktualniCenu = novacena;
}

int main(){
    std::vector <Pokoj*> seznam;

    seznam.push_back(new LuxusniPokoj(13,1500.0,1000,true));
    seznam.push_back(new LuxusniPokoj(13,2000.0,1000,false));
    seznam.push_back(new LuxusniPokoj(45,3000.0,1000,true));

    for(const Pokoj* p : seznam){
        std::cout<<*p<<std::endl;
        std::cout<<"konečnou cenu za pobyt na **4 noci** : " <<p->spoctiCenu(4)<<std::endl;
        std::cout<<"=========================="<<std::endl;
    }

    if (*seznam[0] == *seznam[1]){
        std::cout<<"1.pokoj a 2. pokoj jsou stejne"<<std::endl;
    }else std::cout<<"1.pokoj a 2. pokoj nejsou stejne"<<std::endl;

    for(Pokoj* p : seznam ){ delete p;}

    seznam.clear();
}


