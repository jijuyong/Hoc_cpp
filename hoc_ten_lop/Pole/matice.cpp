#include <iostream>


using namespace std;

void vyplnit(int matice[][3],int radek,int sloupec){
    for (int i = 0; i < radek; i++){
        for (int j = 0; j <sloupec; j++){
            matice[i][j]=rand()%10;
        }
    }

    for (int i = 0; i < radek; i++){
        for (int j = 0; j < sloupec; j++){
            cout<<"["<<matice[i][j]<<"] ";
        }
        cout<< endl; 
    }
    
    
}

int main(){
    srand(time(0));
    int matice1[3][3];
    int matice2[3][3];
    cout<<"matice1"<<endl;
    vyplnit(matice1,3,3);

    cout<<"matice2"<<endl;
    vyplnit(matice2,3,3);


}