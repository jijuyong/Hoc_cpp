#include <iostream>

class A {
    public:
        A(){
            std::cout<<"konctructor cua lop A"<<std::endl;// goi cua A roi den B roi den C
        }

        ~A (){
            std::cout<<"Dekonstructor cua lop A"<<std::endl;
        }
        void xinchao(){ std:: cout<<"xin chao A"<<std::endl;}
};

class B : public A{
    public:
        B(){
            std::cout<<"konctructor cua lop B"<<std::endl;
        }

        ~B (){
            std::cout<<"Dekonstructor cua lop B"<<std::endl;
        }
        void xinchao(){ std:: cout<<"xin chao B"<<std::endl;}
        
};
class C : public B{
    public:
        C(){
            std::cout<<"konctructor cua lop C"<<std::endl;
        }

        ~C (){
            std::cout<<"Dekonstructor cua lop C"<<std::endl;//xoa c trc roi B roi A
        }
        void xinchao(){ std:: cout<<"xin chao C"<<std::endl;}
};

int main(){
    C obj;
    obj.xinchao();
    //neu class C co ham xinchao thi se in ra la chao C, neu khong co thi tim thang cha B roi 
    //in chao B, neu thang B khong co thi lai xin chao A
}