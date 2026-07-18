#include <bits/stdc++.h>
#include <set>
#include <map>

using namespace std;

void khai_bao_set(){
    set<int> s;
    s.insert(3);
    s.insert(1);
    s.insert(5);
    s.insert(3);// size cua set = 3, vi so 3 da xuat hien roi
    cout <<"Size of set: " << s.size() << endl; // Output: 3
    cout <<"Elements in set: ";
    for (int x : s){
        cout << x << " "; // Output: 1 3 5
    }cout<<endl;
}

void tim_so(){
    set<int> s1;

    for (int i = 0; i <10; i++){
        s1.insert(i);
    }
    cout<<"Size of set: " << s1.size() << endl; // Output: 10
    if(s1.count(5)!=0){
        cout<<"5 is in the set"<<endl;
    }else {
        cout<<"5 is not in the set"<<endl;
    }
    
    //find se tra ve iterator 
    if(s1.find(5)!=s1.end()){
        cout<<"5 is in the set"<<endl;
    }
    else {
        cout<<"5 is not in the set"<<endl;
    }
}

void xoa_phan_tu(){
     //erase
    set<int> s1;
    for (size_t i = 0; i < 10; i++){
        s1.insert(i);
    }
    
    s1.erase(5);
    for (int x : s1){
        cout << x << " ";
    }
    //truy cap phan tu be nhat va lon hay (dau tien, cuoi cung)
    cout << "\nSmallest element: " << *s1.begin() << endl; // Output: 0
    cout << "Largest element: " << *s1.rbegin() << endl; //
}

void cac_so_khac_nhau(){
    int n; cout<<"nhap vao size cho mang: "; cin>>n;
    set<int> s2;
    for (int i = 0; i < n; i++){
        int x; cin>>x;
        s2.insert(x);
    }
    cout<< "cac phan tu trong mang la: ";
    for (const auto& i : s2){
        cout<<"["<<i <<"] ";
    }cout<<endl;
    cout<<"co "<<s2.size() << " phan tu khac nhau trong mang"<<endl;
    
    
}

void cac_tu_khac_nhau(){
    int n; 
    cout<<"nhap vao so luong tu: ";
    cin >> n;
    set<string> str;
    cin.ignore(); // Để loại bỏ ký tự newline còn lại trong bộ đệm sau khi đọc n
    cout<<"nhap vao cac tu: "<<endl;
    for (int i = 0; i <n; i++){
        string s;
        getline(cin, s); // Sử dụng getline để đọc cả dòng, bao gồm cả khoảng trắng
        //dung cin chi doc den space thi dung
        str.insert(s);
    }
    cout<<"co "<< str.size()<<" tu khac nhau trong doan ban vua nhap"<< endl;
    cout<< "cac tu day la: ";
    for (auto s : str){
        cout<<"["<< s <<"] ";
    }cout<<endl;
    

}

void MULTISET(){
    multiset<int> ms;
    int n;
    cout<<"nhap vao so phan tu cho multiset: ";
    cin>>n;
    cout<<"nhap vao gia tri cac phan tu: "<<endl;
    for (int i = 0; i < n; i++){
        int x; cin>>x;
        ms.insert(x);
    }
    ms.erase(ms.find(5));
    cout<<"cac phan tu trong multiset la: ";
    for (int x : ms){
        cout <<"[" << x <<"] ";
    }cout<<endl;
    cout<<"size cua multiset la: "<< ms.size();
    
    
}

void bai_tap(){
    multiset<int> ms;
    int n,m;
    cout<<"nhap vao so phan tu cho multiset: ";
    cin>>n;
    int a[n];
    for (int &x : a){
        cin>>x;
    }   

}
 int main (){
    // srand(time(0));
    // khai_bao_set();
    // tim_so();
    // xoa_phan_tu();

    // cac_so_khac_nhau();
    // cac_tu_khac_nhau();
    MULTISET();
    return 0; 
    



}

