#include <iostream>
#include <string>

typedef struct{
    std::string nazev;
    std::string autor;
    int rokVydani;
    double cena;

}Kniha;

void vypisKnihu(Kniha k){
    std::cout<<"sach ["<<k.nazev<<"] cua tac gia {"<<k.autor<<"} nsx ["<<k.rokVydani<<"] gia ["<<k.cena<<"]kc."<<std::endl;
}

int main(){
    Kniha ds[3] = {
        {"Hamlet","William Shakespear",1602,1000},
        {"Havran","Edgar Allan Poe",1845,800},
        {"Krysar","Victor Dyk",1915,500}

    };

    for (int i = 0; i <3; i++){
        vypisKnihu(ds[i]);
    }

    int index_max = 0;
    for (int i = 0; i < 3; i++){
        if (ds[i].cena >ds[index_max].cena){
            index_max= ds[i].cena;
        }
        
    }

    std::cout<<"cuon sach dat nhat la: {"<<ds[index_max].nazev<<"}"<<"voi gia ["<<ds[index_max].cena<<"]"<<std::endl;

    
    



    return 0;
}