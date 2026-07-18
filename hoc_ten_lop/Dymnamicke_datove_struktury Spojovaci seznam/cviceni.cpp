#include <iostream>
using namespace std;

struct Uzel{
    int data;
    Uzel* dalsi;

    Uzel (int hodnota) : data(hodnota), dalsi(nullptr) {};
};

int main(){

    /*1. Manuální spojování
    Použijte strukturu Uzel z textu.
    V main dynamicky vytvořte 3 uzly (s daty 1, 2, 3).
    Manuálně je propojte (ukazatel prvního na druhý, druhého na třetí).
    Vypište data procházením přes ukazatele ( head->data, head->dalsi->data ...).
    Všechny uzly uvolněte (delete).*/
    Uzel* head = nullptr;
    Uzel* uzel1 = new Uzel(1);
    head = uzel1;
    Uzel* uzel2 = new Uzel(2);
    Uzel* uzel3 = new Uzel(3);
    //propojit
    uzel1->dalsi = uzel2;
    uzel2->dalsi = uzel3;

    cout<<"TOA1: "<<uzel1->data<<endl;
    cout<<"TOA2: "<<uzel1->dalsi->data<<endl;
    cout<<"TOA3: "<<uzel1->dalsi->dalsi->data<<endl;

    
    cout<<"NULL"<<endl;
        //xoa cac toa tau
    while(head!=nullptr){
        Uzel* temp = head;
        head= temp->dalsi;
        delete temp;
    }cout<<"da xoa tau"<<endl;

    
    /*2. Výpis cyklem
    Zkuste napsat cyklus while, který projde vámi vytvořený seznam a 
    vypíše všechny hodnoty, dokud nenarazí na nullptr.*/
    cout<<"in ra cac toa tau bang vong while: "<<endl;
    Uzel* temp= head;
    while(temp!=nullptr){
        cout<<"["<<temp->data<<"]->";
        temp = temp->dalsi;
    } // o truoc do da xoa cac toa nen khi run se khong in ra cai gi ca

    return 0;

}