#include <vector>
#include <string>
#include "Student.h"
#include "Magistersky.h"

std::ostream &operator<<(std::ostream &os, const Student &student){
    student.vypis();
    return os;
}

void prijdejBonus (double& aktualniStipendium, double bonusovaCastka){
    aktualniStipendium+=bonusovaCastka;
}

int main(){
    static int z1[] = {1,2,1};
    static int z2[] = {2,2,3};
    static int z3[] = {3,2,1};

    std::vector <Student*> seznam;

    seznam.push_back(new MagisterskyStudent("Vu Thi Lan Huong",z1,3,true));
    seznam.push_back(new MagisterskyStudent("Stepan Schacherl",z2,3,false));
    seznam.push_back(new MagisterskyStudent("Sara Schacherlova",z3,3,true));

    for(const Student* s : seznam){
        std::cout<<*s<<std::endl;
    }

    for(Student* s : seznam){
        delete s;
    }

    seznam.clear();
}