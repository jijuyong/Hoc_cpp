#pragma once 

#include <iostream>

class Pokoj{
    protected:
    int cisloPokoje;
    double* cenaZaNoc; 
    public:
    Pokoj (int cisloPokoje, double cenaZaNoc);
    virtual ~ Pokoj();
    virtual void vypis() const = 0;
    virtual double spoctiCenu(int pocetNoci)const;
    bool operator==(const Pokoj &druhy)const; // podle cislo pokoje
};