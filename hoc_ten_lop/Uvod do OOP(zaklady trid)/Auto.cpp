#include <iostream>
#include <string>

using namespace std;

/*1. Třída Auto
Vytvořte třídu Auto, která bude mít:

Privátní atributy: znacka (string), rokVyroby (int).
Public metody:
nastavHodnoty(string z, int r)
vypisInfo() - vypíše např. "Skoda, rok 2010"*/

class Auto{
    private :
        string znacka;
        int rokVyroby;
    public: 
        Auto (string znacka,int rokVyroby){
            this->rokVyroby = rokVyroby;
            this->znacka = znacka;
        }

        void nastavHodnoty (string z, int r){
            znacka = z;
            rokVyroby = r;
        }

        void vypisInfo(){
            cout<<"Znacka: "<<znacka<<", Rok vyroby: "<<rokVyroby<<endl;
        }
    
};


int main (){
    Auto auto1("Toyota",2020);
    auto1.vypisInfo();

    auto1.nastavHodnoty("Honda",2022);
    auto1.vypisInfo();

   // cout<<"znacka: "<<auto1.znacka<<endl; // Chyba: 'znacka' je privátní a nelze přistupovat z main

    return 0;
}