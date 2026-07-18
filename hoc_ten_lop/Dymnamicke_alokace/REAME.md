# Stack, Heap và Dynamic Memory trong C++

## 1. Stack (Ngăn xếp) – Tủ hồ sơ ngăn nắp

### Cách hoạt động

Stack hoạt động giống như **một chồng đĩa**.

- Thêm phần tử mới lên trên cùng (**Push**).
- Lấy phần tử cũng từ trên cùng (**Pop**).
- Tuân theo nguyên tắc **LIFO (Last In, First Out)**.

### Đặc điểm

- ⚡ Rất nhanh vì CPU chỉ cần di chuyển **stack pointer**.
- 🧹 Bộ nhớ được giải phóng **tự động** khi hàm kết thúc.
- 📏 Dung lượng nhỏ.

### Nhược điểm

Nếu khai báo một mảng quá lớn trên Stack, chương trình sẽ gặp lỗi:

> **Stack Overflow**

Ví dụ:

```cpp
void mojeFunkce() {
    int x = 10;          // x nằm trên Stack
    char buffer[100];    // buffer cũng nằm trên Stack
}
// Khi hàm kết thúc,
// bộ nhớ của x và buffer được giải phóng tự động.
```

---

# 2. Heap (Đống) – Kho bãi tự do

## Cách hoạt động

Heap giống như **một kho bãi rất lớn**.

Muốn sử dụng một vùng nhớ:

1. Gửi yêu cầu (`new`).
2. Hệ điều hành tìm vùng nhớ trống.
3. Trả về địa chỉ của vùng nhớ (con trỏ).

## Đặc điểm

- 📦 Rất lớn (phụ thuộc RAM).
- ✋ Người lập trình phải tự quản lý.
- 🐢 Chậm hơn Stack vì cần tìm vùng nhớ trống.

Ví dụ:

```cpp
int* pDynamickeCislo = new int;

// sử dụng

delete pDynamickeCislo;
```

---

# 3. Cặp bài trùng: `new` và `delete`

Khi dùng từ khóa `new`, bạn đang yêu cầu hệ điều hành:

> "Hãy cấp cho tôi một vùng nhớ trên Heap."

Sau khi dùng xong, bắt buộc phải trả lại bằng `delete`.

## Quy tắc vàng

### Một `new` → Một `delete`

Sai:

```cpp
int* p = new int;
// quên delete
```

➡️ Gây **Memory Leak**.

---

### Một `new[]` → Một `delete[]`

Đúng:

```cpp
int* arr = new int[50];

delete[] arr;
```

Sai:

```cpp
delete arr;
```

➡️ Có thể gây lỗi bộ nhớ.

---

### Sau khi `delete`, gán `nullptr`

```cpp
delete p;
p = nullptr;
```

Điều này tránh xảy ra **Dangling Pointer** (con trỏ lơ lửng).

---

## Ví dụ

### Cấp phát một biến

```cpp
int* pInt = new int;
*pInt = 10;
```

### Khởi tạo ngay khi cấp phát

```cpp
double* pDouble = new double(3.14);
```

### Cấp phát mảng

```cpp
int size = 50;

int* pArray = new int[size];

pArray[0] = 1;
pArray[49] = 100;
```

Giải phóng:

```cpp
delete[] pArray;
pArray = nullptr;
```

---

# 4. Dynamic Allocation của mảng 2 chiều

Có hai cách phổ biến.

---

## Cách 1: Mảng các con trỏ (Array of Arrays)

Ý tưởng:

- Tạo một mảng chứa các con trỏ.
- Mỗi con trỏ trỏ tới một hàng.

### Cấp phát

```cpp
int rows = 3;
int cols = 4;

int** pPole2D = new int*[rows];

for (int i = 0; i < rows; i++) {
    pPole2D[i] = new int[cols];
}

pPole2D[1][2] = 42;
```

### Giải phóng

Luôn xóa **từng hàng trước**, sau đó mới xóa mảng con trỏ.

```cpp
for (int i = 0; i < rows; i++) {
    delete[] pPole2D[i];
    pPole2D[i] = nullptr;
}

delete[] pPole2D;
pPole2D = nullptr;
```

### Vì sao phải xóa theo thứ tự này?

Hãy tưởng tượng:

- Mỗi hàng là một căn phòng.
- Mảng con trỏ là chìa khóa mở các phòng.

Nếu bạn vứt chìa khóa trước, bạn sẽ không thể vào các phòng để dọn dẹp nữa.

---

## Cách 2: Khối nhớ liên tục (Contiguous Block)

Đây là cách được nhiều lập trình viên chuyên nghiệp sử dụng.

Thay vì cấp phát nhiều lần, ta cấp phát **một khối nhớ duy nhất**.

```cpp
int rows = 3;
int cols = 4;

int* matrix = new int[rows * cols];
```

### Truy cập

```cpp
matrix[row * cols + col]
```

Ví dụ:

```cpp
matrix[1 * cols + 2] = 42;
```

### Giải phóng

```cpp
delete[] matrix;
matrix = nullptr;
```

### Ưu điểm

- Nhanh hơn.
- Dữ liệu liên tục trong RAM (Cache Friendly).
- Chỉ cần một lần `delete[]`.

---

# 5. Memory Leak (Rò rỉ bộ nhớ)

Memory Leak giống như **một vòi nước bị rò**.

Ban đầu không đáng kể, nhưng nếu chương trình chạy nhiều giờ hoặc nhiều ngày (server, game, Facebook...), RAM sẽ bị chiếm ngày càng nhiều.

Ví dụ:

```cpp
void nguyHiem() {
    int* p = new int[100];

    // Quên delete[]
}
```

Sau khi hàm kết thúc:

- Biến `p` biến mất.
- Nhưng 100 phần tử trên Heap vẫn tồn tại.
- Không còn cách nào truy cập để giải phóng.

➡️ Đây chính là **Memory Leak**.

---

# Tổng kết

| Stack | Heap |
|--------|------|
| Nhanh | Chậm hơn |
| Quản lý tự động | Quản lý thủ công |
| Dung lượng nhỏ | Dung lượng lớn |
| Không cần `delete` | Bắt buộc `delete` |
| Dễ bị Stack Overflow | Dễ bị Memory Leak |

## Ghi nhớ

- ✅ `new` → `delete`
- ✅ `new[]` → `delete[]`
- ✅ Sau `delete` → gán `nullptr`
- ✅ Không quên giải phóng bộ nhớ để tránh **Memory Leak**
