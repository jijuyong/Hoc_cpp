#include <iostream>
#include "Student.h"

class MagisterskyStudent : public Student{
    private:
    bool cervenyDiplom;
    public:
    MagisterskyStudent(std::string jmeno, int* poleZnamek, int pocet, bool diplom);
    void vypis()const override;
    double spoctiStidendia() const;
};