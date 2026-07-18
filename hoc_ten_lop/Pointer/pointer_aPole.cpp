#include <iostream>

using namespace std;

int main(){
    int cisla [5] = {10,20,30,40,50};
    int* pole = cisla;//khong can &
    cout<< *pole<<endl;;//in ra 10;
    //cout<<*pole++ se in ra 20
    //cout<<*(pole+2) in ra 30
    for (int i=0; i<5; i++){
        cout<<"["<<pole[i]<<"] ";
    }

    //aritmetika s ukazateli
    

}