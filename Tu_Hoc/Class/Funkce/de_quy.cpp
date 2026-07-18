#include <iostream>

using namespace std;

int giaiThua(int n){
    if (n<= 1){
        return 1;
    }
    return n * giaiThua(n - 1);
}
int main(){
    int n;
    cout << "Nhap mot so nguyen duong: ";
    cin >> n;
    cout << "Giai thua cua " << n << " la: " << giaiThua(n) << endl;
    return 0;
}