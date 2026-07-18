#include <iostream>

using namespace std;

class Obdelnik{
    private:
        int delka;
        int sirka;
    public: 
        Obdelnik(int delka, int sirka){
            //delka trong class obdelnik = tham so delka cua ham Obdelnik
            this->delka = delka;
            this->sirka = sirka;        
        }

    int Obsah (int delka, int sirka){
        return delka*sirka;
    }
};


int main(){
    Obdelnik obdelnik1(5,10);
    cout<<"Dien tich hinh chu nhat la: "<<obdelnik1.Obsah(5,10)<<endl;
}