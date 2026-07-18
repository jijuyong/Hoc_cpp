#include <iostream>
#include <string>
#include <ctime>

//tu dong gan gia tri cho objekt
class SinhVien {
    private:
        std::string ten;
        double GPA;
        int tuoi;
        std::string ID;
        static int dem;//bien chung cho toan bo object

    public:
        SinhVien();
        //SinhVien(std::string,int,int,double);
        void nhap ();
        void in();
        ~ SinhVien();
        void tangDem();
        int getDem(); 


};

//khai bao static
int SinhVien:: dem = 0;

void SinhVien::tangDem (){
    dem++;
}

int SinhVien:: getDem(){
    return this->dem;
}


int main(){
    srand(time(0));
    // SinhVien sv;
    // //sv.nhap();
    // //sv.in();
    // sv.tangDem();
    // sv.tangDem(); 
    // SinhVien sv2;
    // std::cout<<"sv2: "<<sv2.getDem()<<std::endl; //mọi object đều cùng giá trị đó.
    // sv2.tangDem();
    // SinhVien sv3;
    // std::cout<<sv.getDem()<<sv2.getDem()<<sv3.getDem()<<std::endl;

    std::cout<<"__________________________________________"<<std::endl;
    SinhVien x;
    x.nhap();
    x.in();

    return 0;

}

/*SinhVien::SinhVien(std::string ten, int tuoi, int ID, double GPA){
    this->ten = ten;
    this->tuoi=tuoi;
    this->GPA = GPA;
    this->ID = ID;
}nhung cai nay dung khi muon co cai nay
SinhVien sv("Anna", 20, 123, 3.8);*/

void SinhVien:: nhap(){
    tangDem();
    this->ID = "SV"+ std::string(3 - std::to_string(dem).length(),'0') + std::to_string(dem);
    // dem = 1;                  3 - do dai cua bien dem, roi them vao tung day so 0 + them bien dem
    std::cout<<"ten: ";
    getline(std::cin >> std::ws, this->ten);
    std::cout<<"tuoi: ";
    std::cin>> this->tuoi;
    std::cin.ignore();
    this->GPA = (rand()%31+10)/10.0;
    

}

void SinhVien:: in(){
    std::cout<<"Sinh vien {"<<ten<<"} ID["<<ID<<"] GPA["<<GPA<<"]."<<std::endl;
}

SinhVien::~SinhVien(){
    std::cout<<"sv {"<<ten<<"} da bi xoa"<<std::endl;
}

SinhVien::SinhVien(){
    ten = " ";
    tuoi = 0;
    GPA = 0.0;
    ID = "";
}