#include <iostream>

void swapPointer(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b= temp;
}

void swapReference(int& a, int&b){
    int temp = a;
    a=b;
    b=temp;
}

int main(){
    int x = 10, y =20;
    // swapPointer(&x,&y);
    // std::cout<<"hoan doi bang pointer: x = "<<x<<", y = "<<y<<std::endl;
    swapReference(x,y);
    std::cout<<"hoan doi bang &: x = "<<x<<", y = "<<y<<std::endl; // x se van in ra nhu cu ket qua se khong thay doi

    return 0;


}