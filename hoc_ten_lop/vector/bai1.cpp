#include <bits/stdc++.h>
#include <vector> 

using namespace std;

int main(){

    vector <int> v;
    v.push_back(10); // them 1 phan tu vao cuoi vector
    v.push_back(20);
    cout<< "kich thuoc cua vector: " << v.size() << endl; // kich thuoc cua vector
    cout<<"cac phan tu trong vector: ";
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    v.push_back(30);
    cout << "\nkich thuoc cua vector sau khi them 1 phan tu: " << v.size() << endl;

    int n;
    cout<<"nhap so luong phan tu can them vao vector: ";
    cin >> n;
    vector <int> v2; // tao 1 vector moi
    for (int i = 0; i < n; i++){
        int x;
        cout << "nhap phan tu thu " << i + 1 << ": ";
        cin >> x;
        v2.push_back(x); // them phan tu vao vector v2
    }
    for (int i = 0; i < n; i++){
        cout << v2[i] << " ";
    }cout << endl;
    
    vector <int> v3 (n,10); // sao chep vector v sang vector v3
    for (auto it = v3.begin(); it != v3.end(); it++){
        cout<< *it ;
    }
    cout << endl;

    string s = "Hello, world  my name is  Nguyen Van A";  
    stringstream ss(s); // tao 1 stringstream de tach chuoi s
    string word;
    vector <string> v5;
    while (ss >> word){ // tach chuoi s thanh cac tu va luu vao vector v5
        if (word.back() == ',') // xoa dau phay o cuoi tu
            word.pop_back();
        v5.push_back(word);

    }

    for (string x: v5)
    {
        cout << x << endl;
    }
    

    return 0;

    

   

}