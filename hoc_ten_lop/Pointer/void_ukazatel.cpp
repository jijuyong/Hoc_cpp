#include <iostream>

using namespace std;

//void* trong C++
int main(){
    /*void* là một kiểu con trỏ đặc biệt, gọi là con trỏ chung (generic pointer).
Nó có thể trỏ tới bất kỳ loại dữ liệu nào mà không cần biết kiểu cụ thể.
Ví dụ: con trỏ void* có thể trỏ đến int, char, struct, hay bất kỳ kiểu nào khác.*/

/*Vì không biết kiểu dữ liệu cụ thể mà void* trỏ tới, ta không thể trực tiếp dereferenc (lấy giá trị) bằng *pVoid.
Ta cũng không thể làm phép toán con trỏ (pointer arithmetic) như pVoid++ trên void* được, vì không biết kích thước 
dữ liệu mà nó trỏ đến (cần kích thước kiểu để tính địa chỉ tiếp theo).*/

void* pvoid;
int a=10;
pvoid = &a;
// Ép kiểu về int* mới có thể truy cập giá trị
int* pInt = static_cast<int*>(pvoid);
cout<<*pInt << endl;
//hoac truy cap truc tiep
cout<< *(static_cast<int*>(pvoid)) << endl;
}