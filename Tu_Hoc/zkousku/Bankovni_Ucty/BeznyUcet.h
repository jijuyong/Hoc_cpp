#include <iostream>
#include <string>
#include <vector>
#include "Ucet.h"

class BeznyUcet : public Ucet{
    private:
    double poplatek;

    public:
    BeznyUcet(std::string cisloUctu, double poplatek);
    void vypisInfo()const override;
    void analyzujUcet()const override;

    // bool operator==(const BeznyUcet& druhy)const;
    bool operator==(const Ucet& druhy) const override;
    BeznyUcet& operator+=(double novoutransakci);
    friend std::ostream& operator<<(std::ostream& op, const BeznyUcet& ucet);
};