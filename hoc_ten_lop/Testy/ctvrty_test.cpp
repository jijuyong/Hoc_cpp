#include <iostream>

class Hrac{
    private:
        std::string jmeno;
        int zdravi;
        int zkusenosti;

    public:
        Hrac(std::string jmeno);
        ~Hrac();
        void utrpPoskozeni(int);
        void pridejZkusenosti(int);
        void vypisStatus();
        bool daruujZkusenosti(Hrac& prijemce, int body);
        
};

int main(){
    Hrac hrac1 ("Argon");
    hrac1.pridejZkusenosti(100);
    {
        Hrac hrac2 ("Legodas");
        hrac1.daruujZkusenosti(hrac2,40);
        hrac1.vypisStatus();
        hrac2.vypisStatus();
    }
        hrac1.vypisStatus();


}

Hrac:: Hrac(std::string jmeno){
    this->jmeno = jmeno;
    this->zdravi =100;
    this->zkusenosti = 0;
    std:: cout<<"Hrdina ["<<jmeno<<"] vstoupil do hry"<<std::endl;
}

Hrac:: ~Hrac(){
    std:: cout<<"Hrdina ["<<jmeno<<"] odstoupil hru"<<std::endl;
}

void Hrac:: utrpPoskozeni(int body){
    zdravi-=body;
    if (zdravi==0){
        zdravi=0;
    }
    
}

void Hrac:: pridejZkusenosti(int body ){
    zkusenosti+=body;
}

void Hrac::vypisStatus(){
    std::cout<<"Hrac ["<<jmeno<<"] Zdravi ["<<zdravi<<"] Zkusenosti ["<<zkusenosti<<"]."<<std::endl; 
}

bool Hrac::daruujZkusenosti(Hrac& prijemce, int body){
    if (body>zkusenosti){
        std::cout<<"nemas dostatek zkusenosti"<<std::endl;
        return false;
    }else {
        zkusenosti-=body;
        prijemce.zkusenosti+=body;
        return true;
    }
    
}


