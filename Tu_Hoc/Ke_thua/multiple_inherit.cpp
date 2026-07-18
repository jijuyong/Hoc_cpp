#include <iostream>

class Animal {
    protected:
        std::string loai;
    
    public:
        Animal(std::string loai){
            this->loai = loai;
        }
};

class dong_Vat_co_vu{
    public: 
        void co_vu(){
            std::cout<<"co vu, dang cho bu"<<std::endl;
        }
};

class Doi : public dong_Vat_co_vu , protected Animal{
    private:
        std::string trang_thai;
    public: 
        Doi (std::string trang_thai,std::string loai) : Animal(loai){
            dong_Vat_co_vu::co_vu();
            std::cout<<loai<<" "<<trang_thai<<std::endl;
        }
    

};

int main(){
    Doi d1("Dang ngu","Doi");

    return 0;
}