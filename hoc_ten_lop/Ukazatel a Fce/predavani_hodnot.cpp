#include <iostream>

using namespace std;

void nezmeni(int a){
    a=20;
}
void zmeni (int* a){
    *a=30;
}

int main(){
    // pass by value
    int x=10;
    cout<<"x = "<< x<<endl;
    nezmeni(x);
    cout<<"x sau khi dung pass byvalue: "<<x<<endl;
    // pas by pointer
    zmeni(&x);
    cout<<"x sau khi dung pass by pointer: "<<x<<endl;
    


}