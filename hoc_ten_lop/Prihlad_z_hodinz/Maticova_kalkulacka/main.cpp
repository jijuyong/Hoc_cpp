#include <iostream>
#include  <cstdlib>
#include <ctime>
#include <stdexcept>


class Matice {

    private: 
        int **matice;
        int radky, sloupec;

    public:  
        Matice (int radky,int sloupec,int inicializacni_hodnota = NULL);//Hàm khởi tạo
        Matice (const Matice &other);//Hàm khởi tạo sao chép
        /*Thực hiện sao chép sâu (Deep Copy) toàn bộ kích thước và dữ liệu từ ma trận other 
        sang ma trận mới để tránh lỗi xung đột vùng nhớ khi truyền tham trị hoặc gán đối tượng.*/
        ~Matice();
        void vypisMatici();
        Matice sectiMatice(const Matice &matice2);
        Matice nasob_matice(const Matice &matice2);
        Matice transponujMatici();
        Matice skalarniNasobeni(int scalar);
        int determinanty_matice();


};

int main(){
    srand(time(0));

    int radky1,sloupce1;
    std::cout<<"______________________________________"<<std::endl;
    std::cout<<"Matice 1"<<std::endl;
    std::cout<<"nhap vao size cua hang: ";
    std::cin >> radky1;

    std::cout<<"nhap vao size cua cot: ";
    std::cin >> sloupce1;

    Matice matice1 = Matice (radky1,sloupce1);

    int radky2,sloupce2;
    std::cout<<"______________________________________"<<std::endl;
    std::cout<<"Matice 2"<<std::endl;
    std::cout<<"nhap vao size cua hang: ";
    std::cin >> radky2;

    std::cout<<"nhap vao size cua cot: ";
    std::cin >> sloupce2;

    Matice matice2 = Matice(radky2,sloupce2);

    std::cout<<"______________________________________"<<std::endl;
    std::cout<<"Matice1 cua ban la."<<std::endl;
    matice1.vypisMatici();
    std::cout<<"Matice2 cua ban la."<<std::endl;
    matice2.vypisMatici();

    std::cout<<"______________________________________"<<std::endl;
    std::cout<<"Matice1 * Matice2: "<<std::endl;
    Matice nasobeni  = matice1.nasob_matice(matice2);
    nasobeni.vypisMatici();

    std::cout<<"______________________________________"<<std::endl;
    std::cout<<"Transponovane matice1 "<<std::endl;
    Matice Tmatice1 = matice1.transponujMatici();
    Tmatice1.vypisMatici();

    std::cout<<"______________________________________"<<std::endl;
    int so_skalar;
    std::cout<<"moi nhap vao so: ";
    std::cin>> so_skalar;
    std::cout<<"Matice1 x "<<so_skalar<<std::endl;
    Matice skalarni_soucin = matice1.skalarniNasobeni(so_skalar);
    skalarni_soucin.vypisMatici();

    std::cout<<"______________________________________"<<std::endl;
    std::cout<<"Determinant matice1 = "<<matice1.determinanty_matice()<<std::endl;
    std::cout<<"Determinant matice2 = "<<matice2.determinanty_matice()<<std::endl;





    



    return 0;
}
// khoi tao matici, neu = null thi plnit random, neu khong thi gan cho bang NULL
Matice::Matice(int radky, int sloupce, int inicializacni_hodnota){
    this->radky = radky;
    this->sloupec = sloupce;

    matice = new int *[radky];
    for (int i = 0; i < radky; ++i){
        matice[i] = new int[sloupce];
        for (int j = 0; j < sloupce; j++){
            if (inicializacni_hodnota == NULL){
                matice[i][j] = rand() % 10;
            }
            else{
                matice[i][j] = inicializacni_hodnota;
            }
        }
    }
}

//Nhiệm vụ chính của nó là tạo ra một bản sao hoàn toàn mới và độc lập từ một ma trận đã có sẵn.
Matice :: Matice (const Matice &other){
    this->radky = other.radky;
    this->sloupec = other.sloupec;
    this->matice = new int* [radky];
    for (int i = 0; i < radky; i++){
        this->matice[i] = new int[sloupec];
        for (int j = 0; j < sloupec; j++){
            this->matice[i][j] = other.matice[i][j];
        }
        
    }
    
}

void Matice:: vypisMatici(){

    if (matice==NULL){
        std::cout<<"matice je prazdna."<<std::endl;
        return;
    }
    
    for (int i = 0; i < radky; i++){
        for (int j = 0; j < sloupec; j++){
            std::cout<<"["<<matice[i][j]<<"] ";
        }std::cout<<std::endl;
    }   
}

Matice Matice:: sectiMatice(const Matice &matice2){
    if (radky!= matice2.radky || sloupec!=matice2.sloupec){
        throw std::runtime_error("Matice nejsou stejne velke");
    }
    Matice vysledek (radky,sloupec);
    for (int i = 0; i < radky; i++){
        for (int j = 0; j < sloupec; j++){
            vysledek.matice[i][j] = matice[i][j]+ matice2.matice[i][j];
        }
    }

    return vysledek;
}

Matice Matice:: nasob_matice(const Matice &matice2){
    if (radky!= matice2.radky || sloupec!=matice2.sloupec){
        throw std::runtime_error("Matice nejsou stejne velke");
    }

    Matice vysledek(radky,sloupec);
    for (int i = 0; i < radky; i++){
        for (int j = 0; j < sloupec; j++){
            for (int k = 0; k< sloupec; k++){
                vysledek.matice[i][j] += (matice[i][k]*matice2.matice[k][j]);
            }
            
        }
        
    }

    return vysledek;
    
}

Matice Matice:: transponujMatici(){
    Matice vysledek(radky,sloupec);
    for (int i = 0; i < radky; i++){
        for (int j = 0; j< sloupec; j++){
            vysledek.matice[i][j] = matice[j][i];
        } 
    }return vysledek;
}

Matice Matice:: skalarniNasobeni(int scalar){
    Matice vysledek = Matice(radky,sloupec);
    for (int i = 0; i < radky; i++){
        for (int j = 0; j< sloupec; j++){
            vysledek.matice[i][j] = matice[i][j]*scalar;
        }   
    }

    return vysledek;
}

int Matice :: determinanty_matice(){
    int vysledek = 0;
    for (int i = 0; i < radky; i++){
        for (int j = 0; j< sloupec; j++){
            vysledek+= matice[i][j];
        }
        
    }return vysledek;
    
}

Matice::~Matice(){
    for (int i = 0; i < radky; i++){
        delete[] matice[i];
        matice[i]  =nullptr;
    }
    delete[] matice;
    matice = nullptr;
}