#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
void denicek(const char* ten_file){
    ofstream file (ten_file);
    string cau;

    if (!file.is_open()){
        cout<<"khong tim duoc file ma oioiii" <<endl;
    }else{
        do{
            cout <<"moi ban nhap vao nhat ky"<<endl;
            getline(cin >>ws, cau);
            file << cau << endl;
        } while (cau != "KONEC" && cau !="konec");
        
    }
    
}

void doc_nhat_ky(const char* ten_file){
    ifstream file (ten_file);
    string dong;
    int so_dong=1;

    if (!file.is_open()){
        cout<<"khong mo duoc nhat ky ma oi";
    }else{
        while(getline(file,dong)){
            cout<<so_dong<<". "<<dong<<endl;
            so_dong++;
        }
    }
    
}

int main(){
    //denicek("denicek.txt");
    doc_nhat_ky("denicek.txt");
}