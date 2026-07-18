#include <iostream>
#include <fstream>
#include <string>

typedef struct{
    int cislo_dne;
    double teplota;
}Mereni;

void ulozdata(){
    //otevr pro zapis
    std::ofstream file ("teploty.txt");

    if (!file.is_open()){
        std::cerr<<"khong mo duoc file ma oi"<<std::endl;
        return;
    }

    std::cout<<"Zadej teploty pro 7 dni"<<std::endl;
    for (size_t i = 0; i < 7; i++){
        double teplota;
        std::cout<<"moi nhap nhiet do cho ngay "<<i+1<<". : ";
        std::cin >> teplota;

        file <<i+1 <<" "<<teplota<<std::endl;
    }

    file.close();
    std::cout<<"data byla ulozene do souboru"<<std::endl;
    
}
//cteni
void analyzujData(){
    Mereni tydenni_mereni [7];
    //otevr pro cteni
    std::ifstream file ("teploty.txt");

    if (!file.is_open()){
        std::cerr<<"khong mo duoc file ma oi"<<std::endl;
        return;
    }
    int i = 0;
    while (i < 7 && file >> tydenni_mereni[i].cislo_dne >> tydenni_mereni[i].teplota) {
        i++;
    } // lua vao pole n nn                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        +
    

    file.close();
    
    double suma =0 ;
    for (int i = 0; i < 7; i++){
        suma+=tydenni_mereni[i].teplota;
    }
    double prumer = suma/7;
    std::cout<<"nhhiet do trung binh trong tuan la: "<<prumer<<std::endl;
    
    int index = 0;
    for (int i = 0; i < 7; i++){
        if (tydenni_mereni[i].teplota > tydenni_mereni[index].teplota){
            index = i;
        }
        
    }

    std::cout<<"ngay co nhiet do cao nhat la: "<<tydenni_mereni[index].cislo_dne<<". voi nhiet do la: "<<tydenni_mereni[index].teplota<<std::endl;
    
}

int main(){
    ulozdata();
    analyzujData();
}