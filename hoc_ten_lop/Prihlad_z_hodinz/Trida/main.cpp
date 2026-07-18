#include <iostream>

class Auto
{
private:
    std::string znacka;
    int rokVyroby;

public:
    Auto();
    Auto(std::string znacka, int rokVyroby);
    void nastavHodnoty(std::string znacka, int rokVyroby);
    void vypisInfo()
    {
        std::cout << "Vozidlo se znackou: " << znacka << " a rokem vyroby: " << rokVyroby << std::endl;
    }
    ~Auto();
};

class Produkt
{
private:
    std::string nazev;
    double cena;

public:
    Produkt(std::string nazev, double cena);
    ~Produkt();
};

int main()
{

    Produkt produkt1("Telefon", 5999.99);//tao 1 doi tuong trong bo nho stack, ton tai cho den khi ham main kthuc
    {
        Produkt produkt2("Televize", 15999.99);
        //Bên trong ngoặc, produkt2 được tạo ra trên Stack (In dòng: Vytvoren produkt: Televize).
        //Ngay khi gặp dấu ngoặc đóng }, produkt2 bị giới hạn phạm vi nên lập tức bị hủy khỏi bộ nhớ 
        //(In dòng: Odstranen produkt: Televize).

    }
    Produkt *produkt3 = new Produkt("PC", 10999.99);
    //Đối tượng trên Heap sẽ không tự động biến mất cho đến khi bạn ra lệnh xóa nó.

    delete produkt3;

    // Auto auto1("Skoda", 2010);
    // {
    //     Auto auto2("Fiat", 2005);
    // }

    // auto1.vypisInfo();
    // auto1.nastavHodnoty("Ford", 2015);
    // auto1.vypisInfo();

    return 0;
}

Auto::Auto()// mac danh la "" va 0
{
    this->znacka = "";
    this->rokVyroby = 0;
}

Auto::Auto(std::string znacka, int rokVyroby)//luc nay gan gia tri cua nguoi dung truyen vao
{
    this->znacka = znacka;
    this->rokVyroby = rokVyroby;
}

void Auto::nastavHodnoty(std::string znacka, int rokVyroby)//cap nhap gia yti cho xe
{
    this->znacka = znacka;
    this->rokVyroby = rokVyroby;
}

Auto::~Auto()
{
    std::cout << znacka << " s rokem vyroby " << rokVyroby << " smazana" << std::endl;
    //Chi tiết hàm hủy của xe. Khi một chiếc xe biến mất, nó sẽ in ra thông báo xe đó đã bị xóa.
}

Produkt::Produkt(std::string nazev, double cena)
{
    std::cout << "Vytvoren produkt: " << nazev << std::endl;
    this->nazev = nazev;
    this->cena = cena;
}

Produkt::~Produkt()
{
    std::cout << "Odstranen produkt: " << nazev << std::endl;
}