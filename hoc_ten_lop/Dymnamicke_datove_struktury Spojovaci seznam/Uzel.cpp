#include <iostream>

using namespace std;

//V C++ se uzel typicky implementuje jako struct nebo class:
struct Uzel{// hoac co the goi la Node
    int data;//Đây là những gì toa tàu chở, nó chở một số nguyên
    Uzel* dalsi;// luu dia chi cua 1 Node tiep theo trong danh sach
    //Móc nối: Đây là cái móc ở phía sau toa tàu để nối với toa tiếp theo.

    //konstruktor pro snadne vytvareni uzlu
    Uzel (int hodnota) : data(hodnota), dalsi(nullptr) {}
    /*Đây là một Constructor giúp bạn tạo ra một nút mới một cách nhanh chóng và an toàn.
    - Tham số int hodnota: Khi bạn tạo một nút, bạn truyền vào giá trị muốn lưu trữ.
    - Danh sách khởi tạo (: data(hodnota), dalsi(nullptr)):
    - Gán giá trị hodnota cho biến data.
    - Mặc định gán dalsi là nullptr (con trỏ rỗng), vì khi mới tạo một nút riêng lẻ, nó chưa trỏ đến đâu cả.
    - Cặp ngoặc {}: Thân hàm trống vì việc gán giá trị đã thực hiện xong ở phần danh sách khởi tạo.*/

};

int main(){
    //tao 1 Node
    Uzel* uzel1 = new Uzel(10); // tạo một nút mới với giá trị 10
    Uzel* uzel2 = new Uzel(20); // tạo một nút mới với giá trị 20
    Uzel* uzel3 = new Uzel(30);
    //ket noi Node1 voi node2
    uzel1->dalsi = uzel2; // uzel1 giờ trỏ (Móc toa) đến uzel2
    uzel2->dalsi = uzel3;// uzel2 giờ trỏ (Móc toa) đến uzel3
    //uzel3->dalsi se tu dong bang nullptr
    //một đoàn tàu chở các số: 10 -> 20->30

}