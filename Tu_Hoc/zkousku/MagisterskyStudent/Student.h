#pragma once

#include <iostream>

class Student{
protected:
    std::string jmeno;
    int* znamka;
    int pocetZnamek;

public:
    Student(std::string jmeno, int* poleZnamek, int pocet);
    virtual ~ Student();
    virtual void vypis()const = 0;
    virtual double prumer()const;
    bool operator==(const Student& druhy)const;

};