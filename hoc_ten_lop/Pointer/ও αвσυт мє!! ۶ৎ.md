# 01 - Giới thiệu về Con trỏ (Pointers)

Con trỏ (**Pointer**) là một trong những khái niệm mạnh mẽ nhưng cũng khó hiểu nhất trong C++. Thay vì lưu trực tiếp giá trị (như `int`, `double`, `char`...), con trỏ lưu **địa chỉ trong bộ nhớ** của một biến khác.

Có thể tưởng tượng con trỏ giống như **địa chỉ của một ngôi nhà**. Thay vì mang theo cả ngôi nhà, bạn chỉ cần mang theo tờ giấy ghi địa chỉ của nó.

---

## Tại sao phải dùng con trỏ?

Con trỏ được sử dụng rất nhiều trong C++ vì những lý do sau:

### 1. Cấp phát bộ nhớ động (Dynamic Memory Allocation)

Cho phép tạo biến hoặc mảng trong lúc chương trình đang chạy bằng `new` và giải phóng bằng `delete`.

---

### 2. Truyền dữ liệu hiệu quả cho hàm

Thay vì sao chép cả một đối tượng lớn (rất tốn thời gian), ta chỉ cần truyền **địa chỉ** của đối tượng đó.

---

### 3. Làm việc với mảng

Trong C++, con trỏ và mảng có mối quan hệ rất chặt chẽ.

Tên của mảng thực chất là địa chỉ của phần tử đầu tiên.

---

### 4. Đa hình (Polymorphism)

Con trỏ đóng vai trò quan trọng trong lập trình hướng đối tượng (OOP), đặc biệt là **đa hình (Polymorphism)**.

---

# Các thao tác cơ bản

Để làm việc với con trỏ, cần biết ba toán tử quan trọng sau.

---

## 1. Khai báo con trỏ (`*`)

Dùng dấu `*` giữa kiểu dữ liệu và tên biến.

Điều này có nghĩa:

> Biến này không lưu giá trị, mà lưu **địa chỉ** của một biến có kiểu tương ứng.

```cpp
int* pSo;
double* pTrungBinh;
char* pKyTu;
```

Trong đó:

- `pSo` lưu địa chỉ của một biến `int`
- `pTrungBinh` lưu địa chỉ của một biến `double`
- `pKyTu` lưu địa chỉ của một biến `char`

> **Lưu ý:** Nếu chưa khởi tạo, con trỏ sẽ chứa một địa chỉ ngẫu nhiên, rất nguy hiểm.

---

## 2. Toán tử lấy địa chỉ (`&`)

Toán tử `&` dùng để lấy địa chỉ của một biến.

```cpp
char c = 'A';

char* p;

p = &c;
```

Bây giờ:

```
c = 'A'

p -----> c
```

Hay nói cách khác:

```
p chứa địa chỉ của c
```

---

## 3. Toán tử giải tham chiếu (Dereference - `*`)

Nếu toán tử `&` lấy địa chỉ,

thì toán tử `*` dùng để **đi đến địa chỉ đó và đọc hoặc ghi dữ liệu**.

Ví dụ:

```cpp
char c = 'X';

char* p = &c;
```

### Đọc dữ liệu

```cpp
char x = *p;

std::cout << x;
```

Kết quả:

```
X
```

---

### Ghi dữ liệu

```cpp
*p = 'Y';
```

Sau đó

```cpp
std::cout << c;
```

Kết quả

```
Y
```

Mặc dù ta không thay đổi `c` trực tiếp, nhưng giá trị của nó vẫn đổi vì ta thay đổi thông qua con trỏ.

---

# Con trỏ rỗng (`nullptr`)

Nếu muốn một con trỏ **không trỏ đến đâu cả**, hãy gán nó bằng `nullptr`.

```cpp
int* pData = nullptr;
```

Có thể kiểm tra:

```cpp
if (pData != nullptr)
{
    // Có thể sử dụng
}
else
{
    std::cout << "Con trỏ chưa hợp lệ";
}
```

Trong C++ hiện đại luôn ưu tiên dùng:

```cpp
nullptr
```

thay vì

```cpp
NULL
```

---

# Con trỏ và mảng

Trong C++, tên của mảng chính là địa chỉ của phần tử đầu tiên.

```cpp
int numbers[5] = {10,20,30,40,50};

int* pArray = numbers;
```

Không cần viết

```cpp
&numbers
```

vì

```cpp
numbers
```

đã chính là địa chỉ của phần tử đầu tiên.

Ví dụ:

```cpp
std::cout << *pArray;
```

Kết quả

```
10
```

---

# Phép toán với con trỏ (Pointer Arithmetic)

Có thể cộng hoặc trừ con trỏ.

Ví dụ

```cpp
int numbers[3]={10,20,30};

int* p=numbers;
```

Ban đầu

```cpp
*p
```

=

```
10
```

Sau đó

```cpp
p++;
```

thì con trỏ sẽ trỏ sang phần tử tiếp theo.

```cpp
std::cout<<*p;
```

Kết quả

```
20
```

Muốn xem phần tử tiếp theo mà không thay đổi con trỏ:

```cpp
std::cout<<*(p+1);
```

Kết quả

```
30
```

> **Lưu ý:** `p + 1` không tăng địa chỉ lên 1 byte, mà tăng theo kích thước của kiểu dữ liệu (`sizeof(int)`, `sizeof(double)`...).

---

## Truy cập mảng bằng con trỏ

Hai cách viết sau hoàn toàn giống nhau:

```cpp
array[i]
```

và

```cpp
*(array+i)
```

Ví dụ

```cpp
numbers[2]
```

tương đương

```cpp
*(numbers+2)
```

---

# Con trỏ và hàm

Thông thường C++ truyền tham số **theo giá trị (Pass by Value)**.

Nghĩa là hàm chỉ nhận **một bản sao** của biến.

Ví dụ

```cpp
void khongThayDoi(int x)
{
    x = 100;
}
```

```cpp
int number = 5;

khongThayDoi(number);
```

Sau khi gọi

```
number = 5
```

vẫn không thay đổi.

---

Nếu truyền địa chỉ:

```cpp
void thayDoi(int* p)
{
    *p = 100;
}
```

Gọi:

```cpp
int number = 5;

thayDoi(&number);
```

Sau đó

```
number = 100
```

vì hàm đã thay đổi giá trị thông qua địa chỉ.

---

# Con trỏ `void*`

`void*` là **con trỏ tổng quát**.

Nó có thể trỏ tới bất kỳ kiểu dữ liệu nào.

Ví dụ

```cpp
int value = 5;

void* pVoid = &value;
```

Tuy nhiên,

không thể làm:

```cpp
*pVoid;
```

vì trình biên dịch không biết dữ liệu bên trong là kiểu gì.

Muốn sử dụng phải ép kiểu trước.

```cpp
int* pInt = static_cast<int*>(pVoid);

std::cout << *pInt;
```

Kết quả

```
5
```

---

# Tóm tắt

| Toán tử | Ý nghĩa |
|----------|---------|
| `*` | Khai báo con trỏ hoặc giải tham chiếu |
| `&` | Lấy địa chỉ của biến |
| `nullptr` | Con trỏ không trỏ tới đâu |
| `new` | Cấp phát bộ nhớ động |
| `delete` | Giải phóng bộ nhớ |

---

# Ví dụ tổng hợp

```cpp
#include <iostream>

int main()
{
    int number = 10;

    int* p = &number;

    std::cout << number << std::endl;
    std::cout << &number << std::endl;
    std::cout << p << std::endl;
    std::cout << *p << std::endl;

    *p = 20;

    std::cout << number << std::endl;

    return 0;
}
```

Kết quả

```
10
0x61ff08
0x61ff08
10
20
```

---

# Bài tập

## Bài 1: Làm quen với con trỏ

1. Tạo biến:

```cpp
int number = 10;
```

2. Tạo con trỏ:

```cpp
int* pNumber;
```

3. Cho con trỏ trỏ tới `number`.

4. In ra:

- Giá trị của `number`
- Địa chỉ của `number`
- Địa chỉ lưu trong con trỏ
- Giá trị thông qua con trỏ (`*pNumber`)

---

## Bài 2: Thay đổi giá trị

Sử dụng con trỏ để thay đổi giá trị của:

```cpp
number
```

từ

```
10
```

thành

```
20
```

Sau đó in ra kết quả.

---

## Bài 3: Con trỏ và mảng

Tạo mảng:

```cpp
int numbers[] = {10,20,30};
```

- Tạo con trỏ trỏ tới phần tử đầu tiên.
- Sử dụng phép toán con trỏ (`p++`) để in lần lượt:
  - 10
  - 20
  - 30
- Thử truy cập phần tử thứ ba bằng:

```cpp
*(p+1)
```

và so sánh với:

```cpp
numbers[2]
```
