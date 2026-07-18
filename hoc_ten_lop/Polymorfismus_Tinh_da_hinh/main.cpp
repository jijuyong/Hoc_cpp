#include <iostream>
#include <vector>
#include <cmath>

class Utvar{
    public:
        virtual ~ Utvar(){
            std::cout<<"destruktor Utvaru"<<std::endl;
        }
        virtual double obsah() = 0;
};

class Ctverec : public Utvar{
    private: 
        double a;
    public:
        Ctverec (double strana) : a(strana) {}
        /*Ctverec(double strana){
            this->a = strana;
        }*/
        
        double obsah () override{
            return a*a;
        }

        ~Ctverec(){
            std::cout<<"Destruktor Ctverec"<<std::endl;
        }

};

class Kruh : public Utvar {
    private:
        double r;
    public :
        Kruh (double prumer) : r(prumer) {}

        double obsah() override{
            return M_PI*pow(r,2);
        }

        ~Kruh(){
            std::cout<<"Destruktor Kruhu"<<std::endl;
        }

};

int main(){
    std::vector <Utvar*> seznam;

    seznam.push_back(new Ctverec(4.0));
    seznam.push_back(new Kruh(3.0));

    std::cout << "--- Vypis obsahu utvaru (In dien tich) ---" << std::endl;
    for (Utvar* x : seznam){
        std::cout<<"obsah utvaru je: "<<x->obsah()<<std::endl;
    }
    std::cout << "--- Uvolneni pameti (Giai phong bo nho) ---" <<std::endl;
    for(Utvar* x : seznam){
        delete x;
    }
    seznam.clear();
    

}
