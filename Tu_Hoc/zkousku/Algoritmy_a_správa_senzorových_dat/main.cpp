#include <iostream>
#include <vector>
#include "Senzor.h"
#include "TeplotniSenzor.h"

// Přetížení operátoru <<
std::ostream& operator<<(std::ostream& os, const Senzor& senzor) {
    senzor.vypis();
    return os;
}

// Globální algoritmus pro spočítání celkového počtu kritických událostí
int spolocneKritickeStavy(const std::vector<Senzor*>& seznam) {
    int celkemKritickych = 0;
    for (const Senzor* s : seznam) {
        // Pomocí dynamic_cast ověříme, zda se jedná o TeplotniSenzor
        const TeplotniSenzor* ts = dynamic_cast<const TeplotniSenzor*>(s);
        if (ts != nullptr) {
            celkemKritickych += ts->spoctiKritickeStavy();
        }
    }
    return celkemKritickych;
}

int main() {
    double m1[] = { 22.5, 45.1, 55.0, 12.3, 60.2 }; // Max: 60.2, Kritické (>50): 2
    double m2[] = { 10.0, 15.2, 12.1, 8.4 };       // Max: 15.2, Kritické (>50): 0

    std::vector<Senzor*> seznam;

    seznam.push_back(new TeplotniSenzor("SENZOR_A", m1, 5, 50.0));
    seznam.push_back(new TeplotniSenzor("SENZOR_B", m2, 4, 50.0));

    std::cout << "--- REPORTY SENZORU ---" << std::endl;
    for (const Senzor* s : seznam) {
        std::cout << *s; // Polymorfní výpis přes <<
        
        // Získání ořezaného průměru
        const TeplotniSenzor* ts = dynamic_cast<const TeplotniSenzor*>(s);
        if (ts) {
            std::cout << "Orezany prumer (bez min a max): " 
                    << ts->spoctiPrumerBezExtremu() << " C" << std::endl;
        }
        std::cout << "-----------------------------------" << std::endl;
    }

    std::cout << "\nCelkovy pocet kritickych udadlosti na vsech senzorech: " 
            << spolocneKritickeStavy(seznam) << std::endl;

    // Úklid paměti
    for (Senzor* s : seznam) {
        delete s; // Spustí ~TeplotniSenzor() a ten zavolá delete[] namereneHodnoty
    }
    seznam.clear();

    return 0;
}