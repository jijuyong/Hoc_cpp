#include <iostream>
#include <vector>
#include <string>
#include <fstream>


using namespace std;

int main (){
    srand(time(0));
    ifstream soubor ("data.txt");
    string radek;
    vector <int> cisla;

    if (soubor.is_open()){
        while (getline(soubor,radek)){
            cisla.push_back(stoi(radek));
        }
        soubor.close();
    }

    

    for (int i = 0; i < cisla.size(); i++){
        for (int j= i+1; j<cisla.size(); j++){
            if ((cisla[i]+ cisla[j] )== 2020){
                cout << cisla[i] << " + " << cisla[j] << " = 2020" << endl;
            } 
        }
        
    }

    return 0;
    
}