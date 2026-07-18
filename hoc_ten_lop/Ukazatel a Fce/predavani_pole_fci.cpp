#include <iostream>

using namespace std;


//funkce prijma ukazatel na int a velikost
void vypisPole (int* arr, int velikost){
    for (int i=0; i<velikost; i++){
        //k prvkum muzeme prostupovat pomoci indexu arr[i]
        // nebo pomoci arimetiky s ukazateli (*(arr+i))
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main (){
    int mojePole[] = {1,2,3,4,5};
    int n = sizeof(mojePole)/sizeof(mojePole[0]);

    cout<<"Obsah pole: ";
    vypisPole(mojePole, n); // predani pole funkci

}