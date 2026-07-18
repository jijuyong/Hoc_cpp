#include <iostream>

using namespace std;

int zmena (int* cislo){
    *cislo = 20;
    return *cislo;
}
int main (){
    int cislo =10;
    int *pCislo;
    pCislo = &cislo;

    cout<<"dia chi cua bien cislo: "<<pCislo <<endl;
    cout<<"gia tri cua cislo: "<<*pCislo<<endl;
    int so_moi = zmena(&cislo);
    cout<<"so moi la: "<< so_moi<<endl;

    int cisla [] = {10,20,30};
    int* pPole = cisla;
    cout<< *pPole <<endl;
    cout<< *(pPole+1) <<endl;
    cout<< *(pPole+2)<<endl;


}
