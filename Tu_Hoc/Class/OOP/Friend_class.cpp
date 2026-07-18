#include <iostream>
#include<string>
#include <time.h>

/*ham ban -  friend function

trong class SinhVien - co cac cai ham no deu la cac cai menber cua lop SinhVien,
nen no co the truy cap cac thuoc tinh cua class SinhVien

- co nhung cai ham khong phai cua class SinhVIen, 
nhung no van muon truy cap vao cac thuoc tinh cua class SinhVien
- Friend function - khong phai member cua class SinhVIen nay, 
nhung van co the truy cap duoc cac thuoc tinh cua ham sinh vien nay
*/

class SinhVien{
    private:
        std::string ten;
        std::string ID;
        int tuoi;
        double GPA;
        static int dem;

    public: 
        SinhVien();
        ~SinhVien();
        void nhap();
        void in();
        // void tangdem();
        // int getdem();

        //khai bao friend function
        friend void inthongtin(const SinhVien&);

};

// int SinhVien::dem =0;

int main(){
    srand(time(0));
    SinhVien sv1;
    sv1.nhap();
    inthongtin(sv1) ;
}

void inthongtin ( const SinhVien& a ){
    std::cout<<"_________________________________________"<<std::endl;
    std::cout<<"truy cap vao thuoc tinh cua class SinhVien thong qua friend function"<<std::endl;
    std::cout<<"["<<a.ID<<"] {"<<a.ten<<"} GPA["<<a.GPA<<"]."<<std::endl;
}

// void SinhVien:: tangdem(){
//     dem++;
// }

// int SinhVien:: getdem(){
//     return this->dem;
// }

void SinhVien:: nhap(){
    //tangdem();
    std::cout<<"ten: ";
    getline(std::cin >> std::ws, this->ten);
    std::cout<<"tuoi: ";
    std::cin >> this->tuoi;
    this->GPA = (rand()%31+10)/10.0;
    std::cin.ignore();
    std::cout<<"ID: ";
    getline(std::cin >> std::ws, this->ID);
    //this-> ID = "SV"+std::string(3-std::to_string(dem).length(),'0');

}

void SinhVien:: in(){
    std::cout<<"["<<ID<<"] {"<<ten<<"} GPA["<<GPA<<"]."<<std::endl;
}

SinhVien:: ~SinhVien(){
    std::cout<<"SV: "<<ten<<" da bi xoa."<<std::endl;
}

SinhVien::SinhVien(){
    this->ten = "";
    this->tuoi = 0;
    this->GPA = 0.0;
    this->ID = "";
}