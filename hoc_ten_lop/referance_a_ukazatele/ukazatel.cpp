#include <iostream>

using  namespace std;


// Předávání hodnotou - vytváří se kopie
void hodnotaZmen (int hodnota){
    hodnota = 10;
}

// Předávání ukazatelem - předáváme adresu a přes ní měníme originál
void ukazatelem(int* ukazatel){
    // u ukazatel je vzdy dobry kontrolovat nullptr
    if (ukazatel!=nullptr) {
        *ukazatel =20;
    }

}

//predavani referenci - fce pracuje primo s originalem pres alias
void referenceZmen(int& ref){
    ref=30;
}

int main(){
    int cislo =5;

    cout<<"puvodni hodnota: "<<cislo <<endl;
    hodnotaZmen(cislo);
    cout<<"po volani hodnotazmen: "<<cislo <<endl;
    ukazatelem(&cislo);
    cout<<"po volani ukazatelem: "<<cislo <<endl;
    referenceZmen(cislo);
    cout<<"po volani reference: "<<cislo <<endl;

    int a=100, b=200;
    int* ptr = &a;
    cout<<"ukazatel ukazuje na: "<<*ptr <<endl;
    ptr = &b;
    cout<<"ukazatel presmerovan na: "<<*ptr <<endl;

    //referenci nelze presmerovat
    int& ref = a;
    cout<<"reference ukazuje na: "<<ref<<endl;
    // Následující řádek NEPŘESMĚRUJE referenci, 
    // ale přiřadí hodnotu z 'b' do 'a' (protože ref je teď jen jiné jméno pro 'a'!)
    ref =b;
    cout << "Po (ref = b) je hodnota ref: " << ref << " a hodnota 'a': " << a << endl;

    return 0;
}