#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void cteni_po_radku(const char* ten_file){
    ifstream file (ten_file);
    string radek;

    if (file.is_open()){
        while (getline(file,radek)){
            cout<< radek<< endl;
        }file.close();  
    }
}

void cteni_po_slovo (const char* ten_file){
    ifstream file (ten_file);
    string slovo;

    if (file.is_open()){
        while (file >> slovo){
            cout<< "["<<slovo << "] ";
        }
        
    }file.close();
    
}


int main (){
    //cteni_po_radku("data.txt");
    cteni_po_slovo("data.txt");
}