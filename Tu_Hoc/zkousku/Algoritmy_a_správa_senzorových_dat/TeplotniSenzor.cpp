#include <iostream>
#include "TeplotniSenzor.h"

TeplotniSenzor ::TeplotniSenzor(std::string nazev, double *hodnoty, int pocet, double kriticka)
    : Senzor(nazev, hodnoty, pocet)
{
    this->kriticatTeplota = kriticka;
}

void TeplotniSenzor::vypis() const
{
    std::cout << "Teplotni Senzor [" << this->nazev
            << "] | Pocet mereni: " << this->pocetMereni
            << " | Max teplota: " << vypocetMaxima() << " C"
            << " | Kritickych stavu: " << spoctiKritickeStavy() << std::endl;
}

int TeplotniSenzor::spoctiKritickeStavy() const
{
    int pocet = 0;
    for (int i = 0; i < pocetMereni; i++)
    {
        if (namereneHodnoty[i] > kriticatTeplota)
        {
            pocet++;
        }
    }
    return pocet;
}

double TeplotniSenzor::spoctiPrumerBezExtremu() const
{
    if (pocetMereni <= 2)
    {
        if (pocetMereni == 0)
            return 0.0;
        double sum = 0;
        for (int i = 0; i < pocetMereni; i++)
            sum += namereneHodnoty[i];
        return sum / pocetMereni;
    }

    // Najdeme minimum a maximum
    double minVal = namereneHodnoty[0];
    double maxVal = namereneHodnoty[0];
    double celkovySucet = 0;

    for (int i = 0; i < pocetMereni; i++)
    {
        if (namereneHodnoty[i] < minVal)
            minVal = namereneHodnoty[i];
        if (namereneHodnoty[i] > maxVal)
            maxVal = namereneHodnoty[i];
        celkovySucet += namereneHodnoty[i];
    }

    // Odečteme jedno min a jedno max
    celkovySucet -= (minVal + maxVal);

    return celkovySucet / (pocetMereni - 2);
}