#include <iostream>

struct Node{
    int data; // Hàng hóa xếp trên toa
    Node *next; // Móc xích nối với toa TIẾP THEO phía sau
    Node *prev;// Móc xích nối với toa PHÍA TRƯỚC nó
};


/*ÚKOL 1: Přidání prvku na ZAČÁTEK seznamu
Všimněte si 'Node*& head' - je to reference na pointer! Můžeme tak změnit samotný head.*/
//Thêm toa vào ĐẦU đoàn tàu
void them_dang_truoc(Node *&head, int value){
    Node *toa_moi = new Node; // 1. Đóng một toa tàu mới tinh
    toa_moi->data = value; //    Xếp hàng hóa (value) lên toa này
    toa_moi -> next = head;// 2. Lấy móc xích 'next' của toa mới móc vào toa đầu tiên hiện tại
    toa_moi ->prev = nullptr; //    Vì nó sẽ đứng đầu, nên phía trước nó không có ai (nullptr)

    if (head!=nullptr){// 3. Nếu trước đó đoàn tàu ĐÃ CÓ toa khác:
        head->prev = toa_moi;  //    Toa đầu cũ phải quay lại, móc xích 'prev' vào toa mới này.
    }

    head = toa_moi;  // 4. Bây giờ, Đầu tàu (head) chính thức chuyển sang quản lý toa mới này.
    
}

/*Ví dụ thực tế khi chạy hàm main:
- Ban đầu: Tàu rỗng (head = nullptr).
- them_dang_truoc(head, 10): Tạo toa [10]. Lúc này: head -> [10] -> nullptr.
- them_dang_truoc(head, 20): Tạo toa [20]. Móc toa [20] vào trước toa [10].
- Lúc này: head -> [20] <-> [10] -> nullptr.*/

//Kiểm tra và Đếm toa tàu (printList)
void printList(Node *head) {
  // Projděte seznam od 'head' až do konce (dokud nenarazíte na nullptr)
  // a vypisujte hodnoty.

  // Váš kód zde:
    while (head != nullptr) {
        std::cout << " Toa truoc: " << head->prev << " dia chia cua no: " << head << " hang hoa: " << head->data
        << "-> toa tiep: " << head->next << " ->\n";
        head = head->next;
    }
    std::cout << "tao dau tien dang bi trong nullptr\n";
}

//huy doan tau
void deleteList(Node *&head){
    while(head!=nullptr){
        Node* next = head->next; // 1. Cầm sẵn sợi xích nối tới toa TIẾP THEO (cất vào túi tạm 'next')
        delete head; // 2. Đập bỏ (giải phóng) toa tàu hiện tại
        head = next;// 3. Bước sang toa tiếp theo mà ta đã nhớ ở bước 1
    }

    head = nullptr;
}

int main(){
    Node *dau_tau = nullptr;// dau tau trong vao luc dau

    std::cout<<"Vypis seznamu: "<<std::endl;
    printList(dau_tau);
    them_dang_truoc(dau_tau,10);
    std::cout<<"Vypis seznamu sau khi them vao dau tau lan thu nhat: "<<std::endl;
    printList(dau_tau);
    them_dang_truoc(dau_tau,20);
    std::cout<<"Vypis seznamu sau khi them vao dau tau lan thu 2: "<<std::endl;
    printList(dau_tau);
    them_dang_truoc(dau_tau,30);
    std::cout<<"Vypis seznamu sau khi them vao dau tau lan thu 3: "<<std::endl;
    printList(dau_tau);

    deleteList(dau_tau);

    std::cout<<"sau khi xoa tau: ";
    printList(dau_tau);

    return 0;
}


