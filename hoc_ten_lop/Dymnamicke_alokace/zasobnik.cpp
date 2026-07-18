#include <iostream>

using namespace std;

int main(){
    srand(time(0));
    //allokace pameti
    int *pInt = new int; //alokace jednoho intu
    *pInt = 10;//ulozeni hodnoty do alokovaneho intu

    //alokace jednoho cisla s inicializaci
    double *pDouble = new double(3.14);

    //alokace pole
    int velkisti = 10;
    int* pole = new int[velkisti]; //alokace pole 50 intu
    pole[0]= 1;// bien pole dang luu dia chi cua phan tu dau tien [0]
    cout << "in phan tu dau tien thong qua *pole: " << *pole << endl;
    cout<<"dia chi cua phan tu dau tien la: "<< pole << endl;
    pole[49]= 100;
    // *(a+i) = a[i]
    cout << "in phan tu cuoi cung thong qua *(pole + 49):  " << *(pole + 49) << endl;//phan tu thu 50

    for (int i = 0; i < velkisti; i++){
        pole[i]=rand() % 100;
    }
    for (int i = 0; i < velkisti; i++){
        cout<<"["<<*(pole + i)<<"] ";
    }
    cout << endl;

    //cap phat vung nho moi, truoc khi cap phat vng nho moi thi can phai giai phong
    //di vung nho cu
    delete []pole;
    pole = new int[20]; //alokace noveho pole 20 intu
    cout<< "sau khi bo nho duoc tang len: "<<endl;
    for (int i = 0; i < 20; i++){
        pole[i]=rand() % 100;
    }
    for (int i = 0; i < 20; i++){
        cout<<"["<<*(pole + i)<<"] ";
    }
    cout << endl;

    delete []pole;

    //alokace 2D pole
    //cach 1: tao ra 1 mang 2 chieu co so hang va cot da xac dinh   
    int hang = 3;
    int cot = 4;
    int** p2D = nullptr;
    // tao ra 1 mang con tro de moi con tro quan ly 1 hang
    // "Hãy tìm cho tôi một vùng trống trên Heap đủ để chứa 3 con trỏ
    /*pPole2D[0] là một con trỏ.
    pPole2D[1] là một con trỏ.
    pPole2D[2] là một con trỏ.*/
    p2D = new int*[hang];
    // dung vong lap for de cap phat tung hang mot
    for(int i = 0;i <hang; i++){
        p2D[i] = new int [cot];
    }

    //nyni muzeme s polem normalne pracovat pomoci [i][j]
    for (int i = 0; i < hang; i++){
        for (int j = 0; j< cot; j++){
            p2D[i][j] = rand() % 100;   
        }  
    }

    cout<< "mang 2 chieu duoc cap phat nho con tro bang cot va hang la: "<<endl;
    for (int i =0; i < hang; i++){
        for (int j = 0; j < cot; j++){
            cout<<"["<<p2D[i][j]<<"] ";
        }
        cout << endl;
    }
    // cout<<"dia chi cua cac vi tri index trong mang 2 chieu la: "<<endl;
    // for (int i =0; i < hang; i++){
    //     for (int j = 0; j < cot; j++){
    //         cout<<"["<<&p2D[i][j]<<"] ";
    //     }
    //     cout << endl;
    // }

    // giai phong vung nho
    // buoc 1 - xoa hang truoc khi xoa cot
    for (int i = 0; i < hang; i++){
        delete p2D[i];
        p2D[i] = nullptr;
    }
    delete []p2D;
    p2D = nullptr;

    //cach 2 - mang 1 chieu gia 2 chieu
    cout<<"cach 2 - mang 1 chieu gia 2 chieu: "<<endl;
    int hang1 = 3;
    int cot1 = 4;
    int* pPoleKont = new int [hang1 * cot1]; // tao ra 1 mang 1 chieu de luu tru du lieu
    // pristup k prvku pole[i][j]
    //pole[i * cot + j]
    //vd: pole[1*cot +2]  la pole[1][2]
    for (int i = 0; i < hang1; i++){
        for (int j = 0; j < cot1; j++){
            pPoleKont[i * cot1 + j] = rand() % 100;
        }
    }
    for (int i = 0; i < hang1; i++){
        for (int j = 0; j < cot1; j++){
            cout<<"["<<pPoleKont[i * cot1 + j]<<"] ";
        }
        cout << endl;
    }
    delete []pPoleKont;
    pPoleKont = nullptr;

    return 0;
}