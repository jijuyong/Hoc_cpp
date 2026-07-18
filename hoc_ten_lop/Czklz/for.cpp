#include <iostream>

using namespace std;

int main (){
    srand(time(0));

    int vyska,sirka,vyska_kmen;
    cout<<"Zadej vysku strom, sirka strom a vysku kmen: ";
    cin>> vyska >> sirka >> vyska_kmen;

    for (int i = 0; i < vyska; i++){
        for (int j= 0; j < vyska-1-i; j++){
            cout<<" ";
        }for (int k = 0; k<(2*i+1); k++){
            char c = (rand()%6==0) ? '$' : '*';
            cout <<c;
        }
        cout<< endl;
    }

    for (int i = 0; i < vyska_kmen; i++){
        for (int j =0; j<(vyska - sirka/2-1);j++ ){
            cout<<" ";
        }for (int k = 0; k < sirka; k++){
            cout<<"|";
        }
        cout<< endl;
        
    }
    
    
    
}