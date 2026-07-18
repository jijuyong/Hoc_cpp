#include <iostream>

using namespace std;

void zmenateplo (double& teplo){
    teplo = 37.2;
}

void prohod(int* c, int* d){
    int temp= *c;
    *c = *d;
    *d=temp;
}
int main(){
    double teplota = 36.6;
    double& refTeplota = teplota;

    cout<<"puvodni teplota: "<<refTeplota<<endl;
    zmenateplo(teplota);
    cout<<"teplota po zmena je: "<<teplota<<endl;

    //2
    int a=10,b=20;
    int& ref =a;
    ref =b;
    cout<< "ref = a = " <<a<<endl;
    cout<<"red = b = "<<b<<endl;

    //3
    int c=5,d=9;
    cout<<"truoc khi doi c = "<<c<<", d = "<<d<<endl;
    prohod(&c,&d);
    cout<<"sau khi doi c = "<<c<<", d = "<<d<<endl;
    

}