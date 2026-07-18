#include <iostream>

using namespace std;

//predani hodnot (fce dostane jen kopii)
void nezmenihodnot(int cisla){
    cisla = 100;
}

//predani hodnot (fce dostane adresa)
void zmenihodnot(int* cislo){
    *cislo = 100;
    cout<<cislo;
}

int main(){
    int cislo = 5;
    nezmenihodnot(cislo); // stale = 5
    zmenihodnot(&cislo);// nyni je 100
}