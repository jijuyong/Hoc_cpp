#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>

/*class: lop
thuoc tinh - ten, tuoi
phuong thuc - hanh dong
object: doi tuong - thuc the - 1 cai nguoi cu the nao do
dong goi: public va private, protected
thuoc tinh se de private, con phuong thuc se de public

- tao constructor - tao ra muoi khi them 1 objekt
= destructor: ham huy, khong co kieu tra ve, ten trung voi class 

-  do la neu ham ko phai la phuong thuc trong class, thi se ko truy duoc cac thuoc tinh cua obkjekt,
chung ta co the dung getter vaa setter - nhung phai xay dung 1 ham tra ve trong class,
roi chung ta co the dung ham day cho vao ham ngoai class

khi gan sv1 = sv2; thi sv1 se co tat ca cac thuoc tinh cua sinh vien 2 */

class SinhVien{
    //thuoc tinh va phuong thuc
    private:
        std::string ten;
        int tuoi;
        double gpa;

    public:
    //phuong thuc
        SinhVien();
        SinhVien(std::string ten, int tuoi, double gpa);
        void xinchao();
        void dihoc();
        void nhap();
        void in();
        double getGPA() const;
        std::string getTen() const;
        void setGPA(double);
        ~SinhVien();

};

bool cpm(const SinhVien& a, const SinhVien& b){
    // xep theo giam dan 
    return a.getGPA() > b.getGPA();    
    //xep theo tang dan
    //return a.getGPA() < b.getGPA();

}


int main(){  
    srand(time(0));
    std::cout<<"_________________________________"<<std::endl;
    std::cout<<"Sv1"<<std::endl;
    SinhVien sv1; // ham construtor khong co tham so se auto goi
    sv1.dihoc();
    sv1.xinchao();
    {
        std::cout<<"_________________________________"<<std::endl;
        std::cout<<"Sv2"<<std::endl;
        SinhVien sv2("Nguyen Nam Anh",21,5.6);
        //std::cout<<sv1.gpa<<std::endl; // je private takze ERROR
        sv2.xinchao();
        sv2.dihoc();
        //trong truong hop nay sv2 se bi xoa ngay lap tuc
    }
    std::cout<<"_________________________________"<<std::endl;
    std::cout<<"Sv3"<<std::endl;
    {SinhVien sv3("Nhat minh thu",18,9.3);} // sv3 trong scope, sau } thi se tu dong huy
    std::cout<<"_________________________________"<<std::endl;
    //sv3 se la nguoi bi huy dau tien
    //sv2 va sv1 sau khi kthuc main ms bi huy
    std::cout<<"Sv4"<<std::endl;
    SinhVien sv4;
    sv4.nhap();
    sv4.in();
    std::cout<<"_________________________________"<<std::endl;
    std::cout<<"Danh sach cach sinh vien."<<std::endl;
    int n;
    std::cout<<"Nhao vao so luong sinh vien trong danh sach ma ban muon tao: ";
    std::cin>>n;
    SinhVien danh_sach[n];
    for (int i = 0; i <n; i++){
        std::cout<<"Moi nhap du lieu cho sv["<<i+1<<"]."<<std::endl;
        danh_sach[i].nhap();
    }
    std::cout<<"========================================="<<std::endl;
    std::cout<<"danh sach sv cua ban la: "<<std::endl;
    for (int i = 0; i <n; i++){
        std::cout<<"sinh vien ["<<i+1<<"]: ";
        danh_sach[i].in();
    }
    std::cout<<"========================================="<<std::endl;
    std::sort(danh_sach,danh_sach+n,cpm);//(con tro dau tien trong mang,dia chi phan tu cuoi cung )
    std::cout<<"danh sach xep theo thu tu "<<std::endl;
    for (int i = 0; i <n; i++){
        std::cout<<"sinh vien ["<<i+1<<"]: ";
        danh_sach[i].in();
    }
    std::cout<<"_________________________________"<<std::endl;
    std::cout<<"set diem cho sinh vien"<<std::endl;
    for (int i = 0; i < n; i++){
        double random = (rand()%31+10)/10.0;
        danh_sach[i].setGPA(random);
        std::cout<<"GPA moi cua {"<<danh_sach[i].getTen()<<"} la ["<<danh_sach[i].getGPA()<<"]. "<<std::endl;
    }
        std::cout<<"========================================="<<std::endl;

    std::cout<<"Bang xep hang moi"<<std::endl;
    std::sort(danh_sach,danh_sach+n,cpm);
    for (int i = 0; i < n; i++){
        std::cout<<i+1<<". ";
        danh_sach[i].in();
    }
    return 0;

}

//scope kieu ham
void abc(){
    SinhVien x;// khi goi ham se duoc tao ra roi tu dong huy sau khi kthuc ham
}


SinhVien::~SinhVien(){
    std::cout<<"Sinh vien {"<<ten<<"} bi xoa."<<std::endl;
}

void SinhVien::xinchao(){
    std::cout<<"Minh ten la: "<<ten<<", minh "<<tuoi<<", diem GPA cua minh la: "<<gpa<<std::endl;
    //se in ra space va hai so 0
}

void SinhVien::dihoc (){
    std::cout<<"minh dang o trong lop"<<std::endl;
}

SinhVien::SinhVien(){
    //std::cout<<"Sinh vien mac dinh duoc tao o day"<<std::endl;
    ten = " ";
    tuoi=0;
    gpa=0.0;
    // nhung ham khong co tham so thuong dung so gan gia tri mac dinh nhu rong rong hoac so 0
}

SinhVien::SinhVien(std::string ten, int tuoi, double gpa){
   // std::cout<<"ham khoi tao co tham so"<<std::endl;
    this->tuoi=tuoi;
    this->ten = ten;
    this->gpa=gpa;
}

void SinhVien::nhap(){
    std::cout<<"moi nhap vao ten cua sinh vien: ";
    std::getline(std::cin>>std::ws,this->ten);
    std::cout<<"moi nhap vao tuoi cua sv: ";
    std::cin>>this->tuoi;
    this->gpa = (rand()%31+10) /10.0;
    // tu 0->100, 100 chia cho 10.0 = 10.0, 85/10.0 = 8.5
}

void SinhVien::in(){
    std::cout<<"Ban {"<<ten<<"}, diem GPA cua ban la ["<<this->gpa<<"]."<<std::endl;
}

double SinhVien:: getGPA() const {
    return this->gpa;
}

std::string SinhVien:: getTen () const{
    return this->ten;
}

void SinhVien:: setGPA(double gpa){
    this->gpa = gpa; // doi gpa cua shinh vien sang tham so gpa cua ham , tham so se do minh dien vao
}