#include <iostream>
#include <string>
#include <vector>
#include "BeznyUcet.h"
#include "SporiciUcet.h"
#include "Ucet.h"


void Nejdelsi_rada_vkladu(const Ucet* ucet){
    const std::vector <double>& h = ucet->getter();
    int aktualni=0, maxPocet=0;
    for (double t : h)
    {
        if (t > 0)
        {
            aktualni++;

            if (aktualni > maxPocet)
                maxPocet = aktualni;
        }
        else
        {
            aktualni = 0;    // reset khi gặp rút tiền
        }
    }
    std::cout << "Nejdelsi souvisla rada vkladu: "<< maxPocet << std::endl;
    
    
} 

void Drobnych_vklad(const Ucet* ucet){
    const std::vector <double>& u1 = ucet->getter();
    std::vector <double> u2;

    for (double t : u1){
        if (t>0){
            u2.push_back(t);
        }else if (t<0) continue;   
    }

    std::cout<<"vklady po odstraneni drobny"<<std::endl;
    for(double t : u2){ std::cout<<"["<<t<<"] ";}
    std::cout<<std::endl;
    
}


int main(){
    std::cout<<"pocatecni pocet aktivnich uctu: "<<citac<<std::endl;

    std::vector <Ucet*> seznam;

    seznam.push_back(new BeznyUcet("CZ-1111",50.0));
    seznam[0]->pridejTransakci({500, 1000, -20, -100, 300, 400, 500, -15});

    seznam.push_back(new BeznyUcet("CZ-2222",50.0));
    seznam[1]->pridejTransakci({-200, 500, -30, -40, 1000});

    seznam.push_back(new SporiciUcet("CZ-2222",4.5));
    seznam[2]->pridejTransakci({ 1000, 2000, 6400, -500 });

    std::cout<<"aktualni pocet aktivnich uctu: "<<citac<<std::endl;
    std::cout<<"-------------------------------------"<<std::endl;
    for(const Ucet* s: seznam){
        std::cout<<*s<<std::endl;
            std::cout<<"-------------------------------------"<<std::endl;
    }
    if (*seznam[0] == *seznam[1]){
            std::cout<<*seznam[0]<<"ma stejny poplatek jako "<<*seznam[1]<<std::endl;
        }else {
            std::cout<<*seznam[0]<<"nema stejny poplatek jako "<<*seznam[1]<<std::endl;
        }
        std::cout<<"-------------------------------------"<<std::endl;

    Nejdelsi_rada_vkladu(seznam[0]);
    Drobnych_vklad(seznam[0]);

    for(Ucet* s : seznam){delete s;}

    seznam.clear();

}