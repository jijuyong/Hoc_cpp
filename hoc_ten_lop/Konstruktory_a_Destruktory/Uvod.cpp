#include <iostream>

using namespace std;

//Konstructor
class Person{
    public: 
        string ten;
        int tuoi;
    //toto je konstructor
    Person(string jmeno, int vek){
        ten = jmeno;
        tuoi = vek;
    }

};

//vychozi konstruktor - ktera neprijma zadne argumenty
class Auto{
    public:
        int pocetDveri;
    //vychozi konstruktor
    Auto(){
        pocetDveri = 4;
    }
};

//dekonstructor
class Trida{
    public:
        int* data;
        //konstruktor:alokuje pamet
        Trida(int hodnota){
            data = new int(hodnota);//alokuje pamet
            *data = hodnota;
            cout<<"Objekt vytvoren. Hodnota: "<<hodnota<<endl;
        }

        //dekonstrukce
        ~Trida(){
            delete data;//uvolneni alokovane pameti
            cout<<"Objekt zničen."<<endl;
        }
};
int main (){
    //zde se automaticky vola konstruktor tridy Person
    Person osoba1("Alice", 30);

    //nyni objekt 'osoba1' rovnou nastavene hodnoty
    cout<<"ten cua osoba1: "<<osoba1.ten<<endl;

    Auto auto1; //tady se vola vychozi konstruktor
    cout<<"pocet dveri u auta: "<<auto1.pocetDveri<<endl;

    Trida* trida1 = new Trida(42); //vytvoreni objektu trida1, konstruktor se vola
    delete trida1; //uvolneni pameti, dekonstructor se vola
    cout<<trida1->data<<endl;// se in ra thong tin rac, hoac la dia chi trong

    return 0;

}