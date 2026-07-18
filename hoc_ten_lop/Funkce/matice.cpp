#include <iostream>

using namespace std;

void vyplnit(int matice[][3]){
    for (int i = 0; i <3; i++){
        for (int j = 0; j <3; j++){
            matice[i][j] = rand()%10;
        }
        
    }

    for (int i = 0; i <3; i++){
        for (int j = 0; j <3; j++){
            cout<<"["<<matice[i][j]<<"] ";
        }cout<<endl;
    }cout << endl;
}

void scitat(int matice1[][3], int matice2[][3]){
    int matice3[3][3];
    for (int i = 0; i <3; i++){
        for (int j = 0; j <3; j++){
            matice3[i][j] = matice1[i][j] + matice2[i][j];
        }
    }

    for (int i = 0; i <3; i++){
        for (int j = 0; j <3; j++){
            cout<<"["<<matice3[i][j]<<"] ";
        }cout<<endl;
    }cout << endl;


}

void nasobeni(int matice1[][3],int matice2[][3]){
    int matice3[3][3] = {0};
    for (int i = 0; i <3; i++){
        for (int j = 0; j <3; j++){
            for (int k = 0; k< 3; k++){
               matice3[i][j]+= matice1[i][k]*matice2[k][j]; 
            }
        }
    }

    for (int i = 0; i <3; i++){
        for (int j = 0; j <3; j++){
            cout<<"["<<matice3[i][j]<<"] ";
        }cout<<endl;
    }cout << endl;


}

void skalarni_soucin(int matice1[][3], int matice2[][3]){
    int n;
    int matice3[3][3] ={0};
    cout<<"tvoje cinitel je: ";
    cin>> n;
    int choice;
    cout<<"s jakou matice chces vynasobit: ";
    cin>>choice;
    
    switch (choice){
        case 1:
            for (int i = 0; i <3; i++){
                for (int j = 0; j <3; j++){
                    matice3[i][j] = n* matice1[i][j] ;
                }
            }
            for (int i = 0; i <3; i++){
                for (int j = 0; j <3; j++){
                    cout<<"["<<matice1[i][j]<<"] ";
                }cout<<endl;
            }cout << endl;   
        break;

        case 2:
            for (int i = 0; i <3; i++){
                for (int j = 0; j <3; j++){
                    matice3[i][j] = n* matice2[i][j] ;
                }
            }
            for (int i = 0; i <3; i++){
                for (int j = 0; j <3; j++){
                    cout<<"["<<matice3[i][j]<<"] ";
                }cout<<endl;
            }cout << endl;
            break;
        default:
        cout<<"Tvoje vybrana matice nexistuje";
        break;     
    }
}
int main(){
    srand(time(0));  

    int matice1[3][3];
    cout<< "Matice1" << endl;
    vyplnit(matice1);
    cout<< "Matice2" << endl;
    int matice2 [3][3];
    vyplnit(matice2);

    cout << "matice1 + matice2 = " << endl;
    scitat(matice1,matice2);
    cout << "matice1 . matice2 = " << endl;
    nasobeni(matice1,matice2);

    cout<<"sklarni soucin " << endl;
    skalarni_soucin(matice1,matice2);


    return 0;
}