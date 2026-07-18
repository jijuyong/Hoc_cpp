#ifndef ZASILKA_H
#define ZASILKA_H


#include <iostream>

class Zasilka
{
protected:
    std::string id;
    double* vaha;

    public:

    Zasilka(std::string id, double vaha);

    virtual ~Zasilka();
    virtual void vypis() const = 0;
    virtual double spoctiCenu() const;

    //Přetížení operátoru == pro porovnání podle ID
    bool operator==(const Zasilka& druha) const;
};

#endif
