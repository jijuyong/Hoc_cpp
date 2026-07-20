#pragma once

#include <iostream>

class Zamestnanec
{
protected:
    std::string jmeno;
    double *zakladniMzda;

public:
Zamestnanec (std::string jmeno, double Mzda);
virtual ~ Zamestnanec();
virtual void vypis()const = 0;
virtual double spoctiMzda()const;
bool operator==(const Zamestnanec& druhy)const;
// (porovná zaměstnance podle jména `jmeno`)

};