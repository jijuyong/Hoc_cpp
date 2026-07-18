#include <iostream>

using namespace std;


void podminky(int matice1[][100], int matice2[][100],int a,int b,int c,int d){

    if (a!=d){
        cout<< "radek 1.matice se lisi od 2. matice!!!!" << endl;
        cout<< "zadejte znovu velikosti matice 1 (sloupec,radek): ";
        cin >> a >> b;
        cout<< "zadejte znovu velikosti matice 2 (sloupec,radek): ";
        cin >> c >> d;  
    }
}



int main(){
    srand(time(0));

    int matice1 [3][3];
    int matice2 [3][4];
    


}