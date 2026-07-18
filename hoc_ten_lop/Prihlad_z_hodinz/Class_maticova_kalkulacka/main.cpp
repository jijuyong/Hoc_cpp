#include <iostream>
#include <time.h>

class Matice{
    private:
        int** matice;
        int radek,sloupce;
    public:
        Matice(int radky, int sloupce, int incializaci_hodnot = NULL);
        Matice* vytvor_matici(int radky, int sloupce, int inicializacni_hodnot = NULL);
        void smazMatici(Matice *&matice);
        void vypisMatice (Matice *matice);
        Matice *secti_matice(const Matice& matice1, const Matice& matice2);
        Matice *nasob_matice(const Matice& matice1, const Matice& matice2);
        Matice *transponuj_matici(const Matice &matice);
        Matice *skalarni_nasobeni_matice(const Matice& matice);

};

int main(){
    srand(time(0));
}


Matice:: Matice(int radky, int sloupce, int incializaci_hodnot = NULL){
    this->radek = radky;
    this->sloupce = sloupce;
    this->matice = new int*[radky];

    for (int i = 0; i < radky; i++){
        this->matice[i] = new int [sloupce];//alokuje 2D pamet

        for (int j = 0; j < sloupce; i++){
            this->matice[i][j] = incializaci_hodnot;
        }
        
    }
}

Matice* Matice::vytvor_matici(int radky, int sloupce, int inicializacni_hodnot = NULL){
    Matice* matice = new Matice (radky,sloupce,inicializacni_hodnot);

    for (int i = 0; i < radky; i++){
        for (int j = 0; j < sloupce; j++)
        {
            matice[i][j] = rand()%10;
        }
        
    }        
    
}

//void Matice:: smazMatici(Matice *ma)