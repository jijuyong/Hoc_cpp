#pragma once

#include <iostream>
#include <string>
#include <vector>

class Ucet{
    protected:
    std::string cisloUctu;
    std::vector <double> historieTransakci;
    //kladna vklady, zaporna vybery
    public:
    Ucet(std::string cisloUctu);
    static int getInt();
    void pridejTransakci(double hodnota);
    void pridejTransakci(const std::vector<double>& hodnoty);
    //zařadí transakce na konec historie.
    const std::vector <double>& getter()const;
    virtual ~Ucet();
    virtual void analyzujUcet()const =0;
    virtual void vypisInfo()const =0;
    friend std::ostream& operator<<(std::ostream& op, const Ucet& ucet);
    virtual bool operator==(const Ucet& druhy) const = 0;
};

static int citac = 0;
