#include <iostream>
#include "Zasilka.h"
#include "Expresni.h"
#include <vector>
#include <string>

// 1. Přetížení operátoru << (Globální funkce)
// Přijímá konstantní referenci na základní třídu Zasilka, což umožňuje polymorfismus
std::ostream &operator<<(std::ostream &os, const Zasilka &zasilka)
{
    zasilka.vypis();
    return os;
}

// 2. Pomocná funkce s referencí
// Změní ID řetězce přes referenci, změna se projeví i vně funkce
void ZmenID(std::string &puvodniId, const std::string &novyID)
{
    puvodniId = novyID;
}

int main()
{
    // 3. Úvod do STL: Vytvoření vektoru ukazatelů na základní třídu
    std::vector<Zasilka *> sklad;

    // 4. Dynamická alokace paměti: Vytvoření objektů pomocí 'new' na haldě (Heap)
    // Třída ExpresniZasilka dědí z Zasilka, proto můžeme ukazatel uložit do vektoru Zasilka*
    sklad.push_back(new expresni("CZ001", 12.5, 150));
    sklad.push_back(new expresni("SK002", 5.0, 80));
    sklad.push_back(new expresni("PL003", 20.0, 250));

    std::cout << "--- VYPIS ZASILEK A CENY (Polymorfismus v praxi) ---\n"<< std::endl;

    for (const Zasilka *z : sklad){
        // Použití přetíženého operátoru << (automaticky zavolá správný vypis())
        std::cout << *z << std::endl;

        // Polymorfní volání metody spoctiCenu()
        std::cout << "Cena dopravy: " << z->spoctiCenu() << " Kc" << std::endl;
        std::cout << "------------------------------------------" << std::endl;

        // Ukázka použití funkce s referencí a přetíženého operátoru ==
        std::cout << "\n--- TEST POROVNANI A REFERENCE ---" << std::endl;
        if (*sklad[0] == *sklad[1]){
            std::cout << "Zasilky maji stejne ID." << std::endl;
        }else{
            std::cout << "Zasilky maji ruzna ID." << std::endl;
        }
    }

    // 6. Uvolnění paměti (Destruktory)
    // Protože jsme použili 'new', musíme na každý prvek zavolat 'delete'
    // Díky 'virtual ~Zasilka()' se správně zavolá destruktor potomka i rodiče
    for( Zasilka* z : sklad){
        delete z;
    }
    // Vyčištění samotného vektoru (odstraní smazané ukazatele)
    sklad.clear();

    return 0;


}