#include <iostream>
#include <iomanip>

class Person{
    protected:
        std::string ten;
        std::string dia_chia;

    public :
        Person(std::string name, std::string adress);
        std::string getTen();
        std::string getDiaChi();
        void setTen(std::string ten);
        void setDia_chi(std::string dia_chi);
        void in();//overring - phuong thuc ghi de
        //định nghĩa lại một phương thức đã có sẵn ở lớp cha
};


class Student : public Person{
    private:
        double GPA;

    public:
        Student (std::string name, std::string adress, double GPA) : Person(name,adress){
            this->GPA = GPA;
        }
        void setGPA(double GPA);
        double getGPA();
        //hai ham overriding
        void in(); 
};


int main(){
    srand(time(0));

    std::string ten, dia_chi;

    Student s1 ("Hana","Hai Phong",3.5);
    s1.in();
    

    return 0;


}

std::string Person:: getTen(){
    return this->ten;
}
std::string Person :: getDiaChi(){
    return this->dia_chia;
}
void Person :: setTen(std::string name){
    this->ten = name;
}
void Person :: setDia_chi(std::string dia_chi){
    this->dia_chia = dia_chi;
}
void Person:: in(){
    std::cout<<ten<<" "<<dia_chia<<" ";
}
Person:: Person (std::string name, std::string adress){
    this->ten = name;
    this->dia_chia = adress;
}



void Student :: in(){
    Person::in();
    std::cout<<std::fixed<<std::setprecision(2)<<GPA<<std::endl;
}
double Student:: getGPA(){
    return this->GPA;
}
void Student :: setGPA(double GPA){
    this->GPA = GPA;
}

