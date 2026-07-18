#pragma once

#include <iostream>
#include "Zasilka.h"

class expresni : public Zasilka
{
private:
    int priplatek;

public:
    expresni(std::string id,double vaha,int priplatek);
    void vypis() const  override;
    double spoctiCenu () const override;
};