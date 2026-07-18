#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void psat_do_souboru(const char* ten_file){
    ofstream file(ten_file);

    if (!file.is_open()){
        cout<<"loi file khong ton tai ma oi"<< endl;
    }

    if (file.is_open()){
        file <<"xin chaao"<<endl;
        file<< "toi ten la mimi"<<endl;
        file.close();
    }
}

void pridat_na_konec_souboru(const char* ten_file){
    ofstream file (ten_file,ios::app);

    if (file.is_open()){
        file<< "dong nay moi duoc toi them vao cuoi soubor" <<endl;
        file.close();
    }
    
}

int main(){

    psat_do_souboru("data1.txt");
    pridat_na_konec_souboru("data1.txt");

}