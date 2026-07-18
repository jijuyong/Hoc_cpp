#include <iostream>

using namespace std;

int main(){
    srand(time(0));
    /*1. Jednoduchá alokace
    Vytvořte program, který:
    Alokuje na haldě jedno celé číslo
    Uloží do něj hodnotu.
    Vypíše ji.
    Uvolní paměť.*/

    int *pPointer = nullptr;                                            // deklarace ukazatele
    pPointer = new int;                                                 // alokace pameti pro jedno cele cislo
    *pPointer = 42;                                                     // ulozeni hodnoty do alokovaneho cele
    cout << "Hodnota ulozena v alokovanem cele: " << *pPointer << endl; // vypis hodnoty
    cout << "Adresa alokovaneho cele: " << pPointer << endl;            // vypis adresy
    delete pPointer;                                                    // uvolneni pameti
    pPointer = nullptr;                                                 // nastaveni ukazatele na null

    /*2. Dynamické pole
    Zeptejte se uživatele, jak velké pole chce vytvořit.
    Alokujte pole intů dané velikosti.
    Naplňte ho čísly (např. od 0 do N).
    Vypište ho.
    Správně uvolněte paměť ().
    */
    int n;
    cout<<"nhao vao size cua pole: ";
    cin>> n;
    int* pN = nullptr;
    pN = new int[n]; //alokace pole intů dané velikosti
    for(int i =0; i<n; i++){
        pN[i] = rand() % 100; //naplňte ho čísly (např. od 0 do N)
    }
    cout<<"Cac phan tu trong mang: "<<endl;
    for (int i = 0; i < n; i++){
        cout<<"["<<pN[i]<<"] ";
    }cout <<endl;

    delete[] pN;
    pN = nullptr;

    /*3. 2D Matice (Bonus)
    Zkuste alokovat dynamickou matici 3x3 (pomocí pole ukazatelů), naplnit ji a uvolnit.*/
    int hang = 3;
    int cot =3;

    int** pPole2D = nullptr; //deklarace dvojiteho ukazatele pro 2D pole
    pPole2D = new int* [hang];

    for(int i =0; i<cot; i++){
        pPole2D[i] = new int [cot];
    }

    
    for (int i = 0; i < hang; i++){
        for(int j = 0;j<cot;j++){
            pPole2D[i][j] = rand() % 100; //naplňte ho čísly (např. od 0 do N)
        }
    }

    cout<<"Cac phan tu trong mang 2D: "<<endl;
    for (int i = 0; i < hang; i++){
        for(int j = 0;j<cot;j++){
            cout<<"["<<pPole2D[i][j]<<"] ";
        }
        cout<<endl;
    }

    for (int i=0;i <hang;i++){
        delete[] pPole2D[i];
        pPole2D[i] = nullptr;    
    }

    delete[] pPole2D;   
    pPole2D = nullptr;

}