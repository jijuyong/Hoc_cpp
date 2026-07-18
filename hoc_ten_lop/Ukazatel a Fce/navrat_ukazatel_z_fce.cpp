#include <iostream>

using namespace std;

int* vytvorDzmnamickePole(int velikosti){
    if (velikosti<=0){
        return nullptr;
    }
    // Cấp phát vùng nhớ trên Heap (hộp lưu trữ dài hạn)
    int* pole = new int [velikosti];
    for(int i=0;i<velikosti;i++){
        pole[i]=0;
    }

    return pole;// Trả về địa chỉ của vùng nhớ đó
    
}
/*Vùng nhớ Heap (Hộp lưu trữ dài hạn): Khi bạn dùng từ khóa new, 
dữ liệu không nằm trong hàm đó mà nằm ở một vùng nhớ riêng biệt gọi là Heap. 
Vùng nhớ này sẽ tồn tại mãi mãi cho đến khi bạn chủ động xóa nó đi.
Cơ chế: Hàm trả về địa chỉ khởi đầu của mảng.
Khi hàm kết thúc, biến cục bộ pPole bị xóa, nhưng vùng nhớ mà nó trỏ tới vẫn còn đó.*/

int main(){
    int* pPole = vytvorDzmnamickePole(5);

    if(pPole!=nullptr){
        pPole[0] = 100;
        cout<<"Prvek na index [0] je: "<<pPole[0]<<endl;

        delete[] pPole;//uvolnime pamet po pouziti
        pPole= nullptr;
    }else{
        cout<<"Neplatna velikost pole!"<<endl;
    }

    return 0;


}

/*int* spatnaFunkce() {
    int lokalniCislo = 50; // Biến này nằm trên Stack (Ngăn xếp)
    return &lokalniCislo; // Trả về địa chỉ của một thứ sắp biến mất
}
Tại sao cách này lại sai?
Vùng nhớ Stack (Ngăn xếp tạm thời): Biến lokalniCislo là biến cục bộ.
Nó chỉ sống bên trong cặp dấu ngoặc nhọn {} của hàm spatnaFunkce.

Hiện tượng "Hồn lìa khỏi xác": Ngay khi hàm return xong, 
hệ thống sẽ thu hồi vùng nhớ của lokalniCislo để cấp cho việc khác.
Con trỏ bạn nhận được ở main bây giờ trỏ vào một vùng nhớ "vô chủ" hoặc đã chứa dữ liệu của hàm khác.

Hệ quả: Nếu bạn cố truy cập vào *pSpatny, chương trình có thể chạy sai kết quả 
(ra một con số rác) hoặc bị dừng đột ngột (Segmentation Fault).   
*/