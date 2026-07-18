#include <iostream>

using namespace std;

int* vytvorDymnamickePole (int velikosti){
    int* pole = new int[velikosti];
    if(velikosti<=0){
        return nullptr;
    }
    else{
        for (int i = 0; i < velikosti; i++){
            pole[i] = 0;
        }
        return pole;
    }
}

void prohod (int* a, int* b){
    srand(time(0));
    int temp =*a;
    *a = *b;
    *b = temp;
}


void zmenaPole(int* pole,int velikosti){
    for(int i=0;i<velikosti;i++){
        pole[i] = pole[i]*2;    
    }
}

int main(){
    // Bài tập 1: Hoán đổi giá trị của hai biến sử dụng con trỏ
    int a =5, b=10;
    cout<<"truoc khi hoan doi vi tri: a = "<<a<<",b = "<<b<<endl;
    prohod(&a,&b);
    cout<<"Sau khi goi ham hoan doi la: a = "<<a<<",b = "<<b <<endl;
// Bài tập 2: Tạo một mảng động và in ra các phần tử của nó
    int* pole = vytvorDymnamickePole(5);
    if(pole != nullptr){
        cout<<"cac phan tu trong mang la: ";
        for(int i =0;i<5;i++){
            cout<<"["<<pole[i]<<"] ";
        }cout<<endl;

        delete[] pole;
        pole = nullptr;
    }else cout<< "velikost khong hop le!"<<endl;
    
    // Bài tập 3: zmena pole
    int pole3[] = {1,2,3,4,5};
    cout<<"pole3 truoc khi thay doi la: "<<endl;
    for(int i=0;i<5;i++){
        cout<<"["<<pole3[i]<<"] ";
    }cout<<endl;
    zmenaPole(pole3,sizeof(pole3));
    cout<<"pole3 sau khi thay doi la: "<<endl;
    for(int i=0;i<5;i++){
        cout<<"["<<pole3[i]<<"] ";
    }cout<<endl;



    return 0;
}