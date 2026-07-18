#pragma oncew

#include <iostream>

class Zasilka
{
private:
    std::string id;
    double* vaha;

    public:

    Zasilka(std::string id, double vaha) : id (id), vaha(&vaha) {}

    virtual ~Zasilka();
    virtual void vypiss() const = 0;
    virtual double spoctiCenu() const;
};
