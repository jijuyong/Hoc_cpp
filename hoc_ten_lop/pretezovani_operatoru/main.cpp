#include <iostream>

/*1. Komplexní čísla
Vytvořte třídu KomplexniCislo (reálná a imaginární část).
Přetěžte operátor + tak, abyste mohli sečíst dvě komplexní čísla (sečtou se reálné části a imaginární části zvlášť).
Přetěžte operátor << pro hezký výpis ve formátu "a + bi".*/

class KomplexniCislo{
    private:
        double realna_cast;
        double imaginarni_cast;

    public:
        KomplexniCislo (double real, double ima) : realna_cast(real), imaginarni_cast(ima) {};

        KomplexniCislo operator+(const KomplexniCislo &other){
            return KomplexniCislo(this->realna_cast + other.realna_cast,this->imaginarni_cast + other.imaginarni_cast);
        }

        friend std::ostream& operator<<(std::ostream &os, const KomplexniCislo &kc);

        bool operator==(const KomplexniCislo &other) const {
            return (this->realna_cast == other.realna_cast) && (this->imaginarni_cast == other.imaginarni_cast);
        } 
        
    };

std:: ostream& operator<<(std::ostream &os, const KomplexniCislo &kc){
    os << kc.realna_cast << " + " << kc.imaginarni_cast << "i";
    return os;
}
/*2. Porovnání
Přetěžte operátor ==, který vrátí true, pokud jsou dvě komplexní čísla shodná (mají stejnou reálnou i imaginární část).*/



int main() {
    KomplexniCislo kc1(1.0, 2.0);
    std::cout << kc1 << std::endl;
    KomplexniCislo kc2(3.0, 4.0);
    std::cout << kc2 << std::endl;
    KomplexniCislo kc3 = kc1 + kc2;
    std::cout << kc3 << std::endl;

    if (kc1 == kc2) {
        std::cout << "kc1 a kc2 jsou shodná komplexní čísla." << std::endl;
    } else {
        std::cout << "kc1 a kc2 nejsou shodná komplexní čísla." << std::endl;
    }

    return 0;

}