#include <iostream>
#include <vector>

using namespace std;

void vyplnit_pole(int n,int m, int matice[][5]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j <m; j++){
            matice[i][j] = rand()%10;
        }  
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j<m; j++){
            cout<< "["<<matice[i][j] <<"] ";
        }
        cout<< endl;
    }
    cout << endl;
    
}

void podminky(int a,int b, int *matice1[][5], int c, int d,int *matice2[][5]){
//    vector<vector<int>>matice2(c,vector<int>(d));
//    vector<vector<int>>matice1(a,vector<int>(b));
   int out =0;

   if (a!=d){
    cout<<"radek 1.matice se lisi od 2. matice!!!!" << endl;
    do{
        cout << "zadejte znovu velikosti matice 1 (sloupec,radek): " ;
        cin >> a >> b;
        cout << "zadejte znovu velikosti matice 2 (sloupec,radek): " ;
        cin >> c >> d;
        out=1;
    } while (out = 0);
   }
   
   
   
   
}

// void scitani(int n,int m, int matice1, int matice2){
//     int sum[n][m];
//     for (int i = 0; i <n; i++){
//        for (int j = 0; j < m; j++){
//         sum[i][j] = matice1[i][j] + matice2[i][j];
//         }
//     }

//     for (int i = 0; i < n; i++){
//         for (int j = 0; j<m; j++){
//             cout<< "["<<sum[i][j] <<"] ";
//         }
//         cout<< endl;
//     }
//     cout << endl;    
// }


int main (){
    srand(time(0));

    int a,b,c,d;
    cout<<"Zadej velikosti 1. matici" << endl;
    cout <<"Sloupec: ";
    cin>>a;
    cout << "Radek: ";;
    cin >>b;
    int *matice1[a][b];
    //vector<vector<int>>matice1(a,vector<int>(b));

    cout<<"Zadej velikosti 2.matici" << endl;
    cout <<"Sloupec: ";
    cin>>c;
    cout << "Radek: ";;
    cin >>d;
    //vector<vector<int>>matice2(c,vector<int>(d));
    int *matice2 [c][d];
    podminky(a,b,matice1,c,d,matice2);
    cout<< "Matice1" << endl;
    vyplnit_pole(a,b,matice1);

    cout<< "Matice2" << endl;
    vyplnit_pole(c,d,matice2);

    //scitani(a,b,matice1,matice2);



    return 0;



}