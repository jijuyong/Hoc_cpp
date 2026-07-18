#include <iostream>

using namespace std;

struct Uzel{
    int data;
    Uzel* dalsi;

    //constructor de tao 1 toa tau moi
    Uzel (int hodnota) : data(hodnota), dalsi(nullptr) {};
};

/*1. Vytvoření seznamu (Khởi tạo đoàn tàu)
Lúc này bạn chưa có toa tàu nào cả. 
Bạn chỉ có một tấm biển ghi chữ "Đầu tàu" (head) nhưng nó chưa chỉ vào đâu cả.
*/

void vlozeniNaZacetek(Uzel* &head, int hodnota){
    Uzel* toa1 = new Uzel(hodnota);
    if(head==nullptr){
        head = toa1;
        return;
    }
}

void vlozeniNakonec (Uzel* &head, int hodnota ){
    Uzel* toa_moi = new Uzel(hodnota);
    if(head==nullptr){
        head = toa_moi;
        return;
    }

    Uzel* temp = head;
    while(temp->dalsi!=nullptr){//di bo de tim toa cuoi
        temp = temp->dalsi;
    }

    temp->dalsi = toa_moi;// noi toa moi vao duoi

}
/*Uzel* &head: Tôi dùng dấu & (tham chiếu) vì khi thêm/xóa ở đầu, địa chỉ của head sẽ bị thay đổi. 
Nếu không có &, thay đổi đó sẽ không được lưu lại sau khi thoát hàm.*/
void vypisSeznam(Uzel* head){
    Uzel* temp = head;
    cout<<"doan tau hien tai la: "<<endl;
    while(temp!=nullptr){
        /*Đây là cách chúng ta "đi bộ" dọc đoàn tàu. Khi temp bằng nullptr, 
        nghĩa là chúng ta đã đi quá toa cuối cùng và rơi xuống đường ray.*/
        cout<<"["<<temp->data<<"] -> ";
        temp = temp->dalsi;// chuyen sang toa tiep theo
    }
    cout<<"NULL"<<endl;
}

void smazSeznam(Uzel* &head){
    while(head!=nullptr){
        Uzel* temp =head;// Giữ toa hiện tại
        head = temp->dalsi;// Nhảy sang toa tiếp theo trước khi xóa
        delete temp;// Phá dỡ toa cũ
    }
    cout<<"da pha doan tau!"<<endl;
}


int main (){
    Uzel* head = nullptr; // Đầu tàu chưa trỏ đến đâu cả, tức là đoàn tàu chưa có toa nào.

    vlozeniNaZacetek(head,10); // Thêm toa đầu tiên với giá trị 10
    vlozeniNakonec(head,20); // Thêm toa thứ hai với giá trị 20
    vlozeniNakonec(head,30); // Thêm toa thứ ba với giá trị 30
    //toa tau tiep theo se tu dong bang null
    vypisSeznam(head); // In ra đoàn tàu hiện tại: [10] -> [20] -> [30] -> NULL
    smazSeznam(head); // Phá dỡ toàn bộ đoàn tàu, giải phóng bộ nhớ
    return 0;



}