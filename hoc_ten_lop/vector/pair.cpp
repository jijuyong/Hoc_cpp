#include <bits/stdc++.h>

using namespace std;


int main(){
    pair <int, string> p1; // khai bao 1 doi tuong pair co kieu int va string
    p1.first = 10; // gan gia tri cho phan tu dau tien cua pair
    p1.second = "Hello"; // gan gia tri cho phan tu thu hai cua pair
    cout << "Gia tri cua p1: " << p1.first << " " << p1.second << endl;

    pair <int, string> p2 (20, "World"); // khai bao 1 doi tuong pair va gan gia tri cho no
    cout << "Gia tri cua p2: " << p2.first << " " << p2.second << endl; 

    pair <int,int> p3 = make_pair(30, 40); // su dung ham make_pair de tao 1 doi tuong pair
    cout << "Gia tri cua p3: " << p3.first << " " << p3.second << endl;
    
     // khai bao 1 doi tuong tuple co 3 phan tu
    tuple <int, string, double> t (50, "Nguyen Van A", 3.14);
    cout << "Gia tri cua t: " << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl; 
    // su dung ham get de lay gia tri cua cac phan tu trong tuple   


    return 0;
}