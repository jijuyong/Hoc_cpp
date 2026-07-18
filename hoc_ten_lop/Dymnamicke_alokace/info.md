1. Stack (Ngăn xếp): Tủ hồ sơ ngăn nắp
Cách hoạt động: Giống như một chồng đĩa. Bạn đặt cái mới lên trên cùng (Push) và khi lấy ra cũng phải lấy cái trên cùng trước (Pop - LIFO).
~ Đặc điểm: * Cực kỳ nhanh vì máy tính chỉ cần dịch chuyển "con trỏ đỉnh" để lấy dữ liệu.
~ Tự động: Khi hàm chạy xong, mọi biến cục bộ bên trong hàm đó tự động bị "vứt đi" mà bạn không cần làm gì cả.
~ Nhược điểm: Dung lượng rất nhỏ. Nếu bạn cố nhồi nhét một mảng khổng lồ (ví dụ int arr[1000000]), chương trình sẽ bị "Stack Overflow" (tràn bộ nhớ đệm) và sập ngay lập tức.

void mojeFunkce() {
    int x = 10;          // 'x' je na zásobníku
    char buffer[100];    // 'buffer' je na zásobníku
} // Na konci funkce se paměť pro 'x' a 'buffer' automaticky uvolní

2. Heap (Đống): Kho bãi tự do
~ Cách hoạt động: Giống như một kho bãi rộng lớn nhưng lộn xộn. Bạn muốn thuê một mảnh đất ở đó? Bạn phải gửi yêu cầu, thủ kho tìm chỗ trống rồi đưa cho bạn một cái "địa chỉ" (con trỏ).
Đặc điểm:
- Rất rộng lớn (phụ thuộc vào RAM của bạn).
- Thủ công: Bạn phải tự xin (new) và tự trả (delete).
- Nhược điểm: Chậm hơn Stack vì hệ thống tốn thời gian tìm kiếm chỗ trống và quản lý danh sách các vùng nhớ.

int* pDynamickeCislo = new int; // Alokuje místo pro int na haldě
// ... práce s *pDynamickeCislo ...
delete pDynamickeCislo;         // Manuální uvolnění paměti



3. Cặp bài trùng: new và delete
Trong C++, khi bạn dùng từ khóa new, bạn đang nói với hệ điều hành: "Cho tôi xin một vùng nhớ trên Heap, tôi sẽ tự quản lý nó thông qua một con trỏ".
- Quy tắc vàng (Không được quên):
Một new = Một delete: Nếu thiếu delete, bộ nhớ sẽ bị chiếm dụng mãi mãi (gọi là Memory Leak).
- Một new[] = Một delete[]: Nếu bạn xin một mảng, khi trả phải dùng ngoặc vuông. Dùng sai (ví dụ delete cho mảng) sẽ gây lỗi bộ nhớ nghiêm trọng.
- Xóa xong hãy gán nullptr: Sau khi delete p;, biến p vẫn còn giữ địa chỉ cũ (gọi là Dangling Pointer - con trỏ lơ lửng). Gán p = nullptr; để tránh vô tình sử dụng lại con trỏ đã chết.

// Alokace jednoho celého čísla na haldě
int* pInt = new int;
*pInt = 10; // Uložíme hodnotu do alokované paměti

// Alokace jednoho čísla s inicializací
double* pDouble = new double(3.14);

// Alokace pole 50 celých čísel na haldě
int velikost = 50;
int* pPole = new int[velikost];
pPole[0] = 1; // Práce s dynamickým polem je stejná jako se statickým
pPole[49] = 100;

4. Dynamická alokace 2D polí
- Cấp phát mảng 2 chiều động thực chất là tạo ra "một mảng các con trỏ", và mỗi con trỏ đó lại trỏ đến "một mảng các giá trị".

- Cách 1: Mảng của các mảng (Mô hình bậc thang)
Bước 1: Tạo một cột dọc chứa các con trỏ (int p).
Bước 2: Với mỗi con trỏ trong cột đó, cấp cho nó một hàng ngang.

Tại sao phải xóa ngược? Hãy tưởng tượng bạn có 5 cái hộp, mỗi hộp chứa một chìa khóa mở một căn phòng. Nếu bạn vứt 5 cái hộp đi trước, bạn sẽ không bao giờ biết chìa khóa ở đâu để vào phòng mà dọn dẹp. Vì vậy, phải dọn phòng (xóa hàng) trước, rồi mới vứt hộp (xóa cột con trỏ).

// 1. Uvolníme paměť pro každý řádek
for (int i = 0; i < radky; ++i) {
    delete[] pPole2D[i];
    pPole2D[i] = nullptr; // Dobrá praxe
}

// 2. Uvolníme paměť pro pole ukazatelů
delete[] pPole2D;
pPole2D = nullptr; // Dobrá praxe

- Cách 2: Trải phẳng (Mảng 1 chiều giả 2 chiều)
Alternativa: Souvislý (kontinuální) blok

Đây là cách các lập trình viên giàu kinh nghiệm thường dùng. Thay vì cấp phát lắt nhắt nhiều lần, ta xin một dải bộ nhớ duy nhất dài bằng Rộng * Cao.
Ưu điểm: Nhanh hơn vì dữ liệu nằm sát nhau trong RAM (Cache friendly), dễ xóa (chỉ cần 1 lệnh delete[]).
Công thức truy cập: mảng[hàng * số_cột + cột]
int radky = 3;
int sloupce = 4;
int** pPole2D = nullptr;

// 1. Alokujeme pole ukazatelů (jeden ukazatel pro každý řádek)
// pPole2D bude typu 'ukazatel na (ukazatel na int)'
pPole2D = new int*[radky]; 

// 2. V cyklu alokujeme každý jednotlivý řádek
for (int i = 0; i < radky; ++i) {
    // pPole2D[i] je typu 'ukazatel na int'
    pPole2D[i] = new int[sloupce];
}

// Nyní můžeme s polem normálně pracovat pomocí [i][j]
pPole2D[1][2] = 42; 

4. Hiểm họa: Memory Leak (Rò rỉ bộ nhớ)
Hãy coi Memory Leak như một vòi nước bị rò. Ban đầu không sao, nhưng nếu chương trình của bạn chạy liên tục (như Server game hoặc ứng dụng Facebook), nó sẽ từ từ ăn hết RAM của máy tính.

Ví dụ điển hình:
void nguyHiem() {
    int* p = new int[100]; 
    // Quên delete p;
} 
// Khi hàm kết thúc, biến 'p' (con trỏ) biến mất, 
// nhưng 100 số nguyên kia vẫn nằm lì trên Heap. 
// Không ai có thể tìm thấy chúng để xóa nữa!
