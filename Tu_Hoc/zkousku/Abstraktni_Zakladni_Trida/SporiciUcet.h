#pragma once
#include "BankovniUcet.h"

class SporiciUcet : public BankonvniUcet
{
private:
    double bonusovaSazba;

public: 
    SporiciUcet(std::string majitel, double zustatek, double bonus);
    void VypisInfo()const override;
    double spoctiUroku()const override;

};