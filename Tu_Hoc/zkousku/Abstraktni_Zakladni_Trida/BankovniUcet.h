#pragma  once

#include <iostream>
class BankonvniUcet{
    protected:
    std::string majitel;
    double* zustatek;

    public:
    BankonvniUcet (std::string majitel, double zustatek);
    virtual ~ BankonvniUcet();
    virtual void VypisInfo() const =0;
    virtual double spoctiUroku() const;
    bool operator==(const BankonvniUcet& DruheUctu)const;
    std::string getMajitel();

};