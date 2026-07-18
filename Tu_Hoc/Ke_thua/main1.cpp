#include <iostream>
#include <iomanip>

class Person{
    protected:
        std::string ten;
        std::string dia_chia;

    public :
        std::string getTen();
        void nhap();
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
        void setGPA(double GPA);
        double getGPA();
        //hai ham overriding
        void in(); 
        void nhap();
};


int main(){
    srand(time(0));

    std::string ten, dia_chi;

    Student s1,s2,s3;
    std::cout<<"ten: ";
    getline(std::cin >> std::ws, ten);
    s1.setTen (ten);
    std::cout<<"dia chi: ";
    getline(std::cin >> std::ws, dia_chi);
    s1.setDia_chi (dia_chi);
    double diem = (rand()%31+10)/10.0;
    s1.setGPA(diem);
    s1.in();
    s2.nhap();
    s2.in();

    //neu khong muon goi ham cua student
    s3.Person::nhap();
    s3.Person::in(); // se chi input ten va dia chi

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
void Person::nhap(){
    std::cout<<"ten: ";
    getline(std::cin>> std::ws,ten);
    std::cout<<"dia chi: ";
    getline(std::cin>> std::ws,dia_chia);
}

void Student:: nhap(){
    Person::nhap();
    std::cout<<"GPA: ";
    std::cin>>GPA;
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

