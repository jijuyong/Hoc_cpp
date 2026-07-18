#include <iostream>
#include <string>

using namespace std;

void vyplnit_pole(int n, int pole[]){
    for (int i = 0; i < n; i++){
        pole[i] = rand()%100;   
    }

    cout << "vase pole " << endl;
    for (int i = 0; i < n; i++)
    {
        cout<< "["<<pole[i] <<"] " ;
    }

    cout << endl;
    
}

int Soucet (int n, int pole[]){
    int soucet=0;
    for (int i = 0; i < n; i++)
    {
        soucet += pole[i];
    }

    return soucet;
    
}


double Prumer(int n, int pole[]){
    int soucet = Soucet(n,pole);
    double P= (double)soucet/n;

    return P;
}

int max(int n, int pole[]){
    int Max_num = pole[0];
    for (int i = 0; i < n; i++){
        if (Max_num< pole[i]){
            Max_num=pole[i];
        }
    }

    return Max_num;
    
}



int main (){
    srand(time(0));
    int n;
    cout<< "zadejte velikosti pole: ";
    cin>>n;
    int pole[n];

    //soucet
    vyplnit_pole(n,pole);
    int soucet = Soucet(n,pole);
    cout << "soucet pole: " << soucet << endl;
    //prumer
    int prumer = Prumer(n,pole);
    cout << "Prumer pole: " << prumer << endl;
    //nejvetsi cislo
    int MAX = max(n,pole);
    cout<< "nejvetsi cislo v poli je: "<< MAX << endl;

    //3 ukol
    string krestni, prijmeni;
    cout<<"zadej krestni jmeno: ";
    cin>> krestni;
    cout<< "zadej prijmeni: ";
    cin>> prijmeni;

    string cele_jmeno = krestni + " " + prijmeni;
    cout << "cele vase jmeno je: " << cele_jmeno << endl;
    cout << "delka jmeno je: " << cele_jmeno.length()-1 << endl;


    return 0;
}