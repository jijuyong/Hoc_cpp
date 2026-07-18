#include <iostream>

using namespace std;

int main()
{
    // deklarace ukazatele
    int *cislo;
    double *prumer;
    char *znak;

    // operator adresy &
    char c = 65;
    char *p; // tao con tro
    p = &c;  // chi con tro vao dia chi cua bien c

    // Operátor dereference (*)
    char a = 88;
    char* t; // khai bao
    t = &a;
    // cteni hodnoty
    char x = *t; // truy cap
    cout << "gia tri cua p: " << *p << endl;
    cout << "gia tri cua x: " << x;

    // nullovy ukazatel (nullptr)
    int *pData = nullptr; // de cho con tro khong chi vao dau ca
    /*if (pData != nullptr){
        // Pracuj s daty
    }
    else{
        std::cout << "Ukazatel je neplatný." << std::endl;
    }*/
}