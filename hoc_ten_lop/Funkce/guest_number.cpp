#include <iostream>

using namespace std;

void kiem_tra(int n, int rand_n);

void hadat(int n){
    int random_number = rand()%100;
    do
    {
        cout<< "Spatne, hadej znovu, ";
        kiem_tra(n,random_number);
        cin >> n;
    } while (n!=random_number);
    cout << "Gratuluji vyhralijste🏆🌟" << endl;
    cout << "Tajna cisla je: " << random_number << endl;
}

void kiem_tra(int n, int rand_n){

    if (n<=rand_n){
        cout<<"je to vetsi nez: " << n  << endl;
    }
    else if (n>=rand_n){
        cout << "je to nizsi nez:  " << n << endl;
    }
    if (n+1==rand_n || n+2==rand_n || n+3==rand_n || n-1==rand_n || n-2==rand_n || n-3==rand_n){
        cout << "je to blizko hadej znovu: ";
    }
}


int main(){
    srand(time(0));
    int number;
    int choice;

    do
    {
        cout << "Hadej cislo 0->100: ";
        cin >> number;
        hadat(number);
        cout<<"chcete pokracovat? 1(ano) 0(ne): ";
        cin >> choice;
        if (choice ==0){
            break;
        }
    
    } while (choice==1);
    
}