#include <iostream>
#include <string>

/*1. Šablona funkce
Vytvořte šablonu funkce vymen(T& a, T& b), 
která prohodí hodnoty dvou proměnných libovolného typu. 
Vyzkoušejte pro int, double a string.*/

template <typename T>
void prohod (T& a,T& b){
    T temp = a;
    a =b;
    b = temp;
}

/*2. Šablona třídy
Napište šablonovou třídu Schranka<T>, která bude uchovávat jednu hodnotu typu T.
Metodu vloz(T data)
Metodu T vyzvedni() Vyzkoušejte pro různá data.*/
template <typename T>
class Schranka{
    private:
        T ulozenaData;
    public:
        void vloz (T data){
            this->ulozenaData = data;
        }
        T vyzvedni(){
            return ulozenaData;
        }
        
};


int main(){
    std::cout << "--- Testovani pro INT ---" <<std::endl;
    int a,b;
    std::cout<<"a: "; std::cin>>a;
    std::cout<<"b: "; std::cin>>b;
    prohod(a,b);
    std::cout<<"sau khi hoan doi: a = "<<a<<" b = "<<b<<std::endl;
    std::cout << "--- Testovani pro double---" <<std::endl;
    double c,d;
    std::cout<<"c: "; std::cin>>c;
    std::cout<<"d: "; std::cin>>d;
    prohod(c,d);
    std::cout<<"sau khi hoan doi: c = "<<c<<" d = "<<d<<std::endl;
    std::cout << "--- Testovani pro string---" <<std::endl;
    std::string e,f;
    std::cout<<"e: "; getline(std::cin>>std::ws,e);
    std::cout<<"f: "; getline(std::cin>>std::ws,f);
    prohod(e,f);
    std::cout<<"sau khi hoan doi: e = "<<e<<" f = "<<f<<std::endl;

    std::cout<<"--------------------------"<<std::endl;
    Schranka <int> ciselnaSchranka;
    int ciselnaData; std::cout<<"ciselna data: "; std::cin >>ciselnaData;
    ciselnaSchranka.vloz(ciselnaData);
    std::cout<<"Cislo ze schranky: "<< ciselnaSchranka.vyzvedni()<<std::endl;
    std::cout<<"--------------------------"<<std::endl;
    Schranka <double> doubleSchranka;
    double doubleData; std::cout<<"double data: "; std::cin >>doubleData;
    doubleSchranka.vloz(doubleData);
    std::cout<<"Double Cislo ze schranky: "<< doubleSchranka.vyzvedni()<<std::endl;

    std::cout<<"--------------------------"<<std::endl;
    Schranka <std::string> StringSchranka;
    std::string stringData; std::cout<<"string data: "; getline(std::cin>>std::ws, stringData);
    StringSchranka.vloz(stringData);
    std::cout<<"String ze schranky: "<< StringSchranka.vyzvedni()<<std::endl;






    return 0;
}

