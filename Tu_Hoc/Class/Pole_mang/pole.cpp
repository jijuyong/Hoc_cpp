// #include <iostream>
// #include <string>
#include <bits/stdc++.h>
using namespace std;


int main(){
    srand(time(0));
    int n;
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;
    int pole[n];

    for (int i = 0; i < n; i++){
        pole[i] = rand() % 100;
    }
    
    cout << "Mang vua duoc tao la: " << endl;
    for (int i = 0; i < n; i++){
        cout <<"[" << pole[i] << "] ";
    }


    //chuoi kieu string - char
    char str[] = "Ahoj, svete"; 
    cout << "\nChuoi str la: " << str << endl;

    //string
    string ten = "Thi Lan Huong";
    string ho = "Vu";
    string tenDayDu = ho +" "+ ten;
    cout << "Ten day du la: " << tenDayDu << endl; 

    //mang hai chieu
    int a,b;
    cout << "nhap so hang va so cot: ";
    cin >> a >> b;
    int pole2[a][b];

    for (int i = 0; i < a; i++){
        for (int j = 0; j < b; j++){
            pole2[i][j] = rand() % 100;
        }
    }

    cout << "Mang hai chieu vua duoc tao la: " << endl;
    for (int i = 0; i < a; i++){
        for (int j = 0; j < b; j++){
            cout << "[" << pole2[i][j] << "] ";
        }
        cout << endl;
    }

    //mang ky tu
    char M1[5] = {'a', 'b', 'c', 'd', 'e'};
    cout << M1<< endl;


    char* M2;
    M2 = new char[3];
    M2[0] = 'h';   
    M2[1] = 'e';
    M2[2] = '\0 ';

    cout << M2 << endl;


    
    

}