#include <iostream>
//#define PI 3.14
#include <cmath> //meu muon dung PI trong thu vien toan

using namespace std;

double chuvi_hinhTRON(int r){
    return 2*M_PI*r;
}
double dien_tich_hinhTron(int r){
    return M_PI*pow(r,2);
}

int chuvi_hnn(int a,int b){
    return (a+b)*2;
}

int dientich_hnn(int a,int b){
    return a*b;
}
int main(){
    int r;
    cout<<"moi nhap vao r: ";
    cin >> r;
    double chuvi = chuvi_hinhTRON(r);
    cout<<"Chu Vi hinh tron: " << chuvi <<endl;
    double dientich = dien_tich_hinhTron(r);
    cout<< "dien tich hinh tron: "<< dientich <<endl;

    int a,b;
    cout << "moi nhap vao canh a,b: ";
    cin >>a>>b;
    double chuvi_HNN = chuvi_hnn(a,b);
    cout<<"Chu Vi hinh chu nhat: " << chuvi_HNN <<endl;
    double dientich_HNN = dientich_hnn(a,b);
    cout<< "dien tich hinh chu nhat: "<< dientich_HNN <<endl;

    

    return 0;
}