#include <iostream>
#include <string>

using namespace std;

/*1. Produkt v e-shopu
Vytvořte třídu Produkt.
Konstruktor: Přijme název a cenu, uloží je do atributů a vypíše 
"Vytvořen produkt: [nazev]".
Destruktor: Vypíše "Zničen produkt: [nazev]".
V main vytvořte produkt uvnitř bloku { ... }. 
Sledujte, kdy se vypíše zpráva z destruktoru (mělo by to být při ukončení bloku).*/

class Produkt {
    public:
        string nazev;
        int cenu;

        Produkt (string n, int c){
            nazev = n;
            cenu = c;
            cout<<"Vytvoren produkt: "<<nazev<<endl;
        }

        ~Produkt(){
            cout<<"Znicen produkt: "<<nazev<<endl;
        }
};

int main(){
    Produkt produkt1("Laptop", 1500);
    Produkt produkt2("Smartphone", 800);
    return 0;
}