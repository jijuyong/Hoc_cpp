# 04 - Con trỏ và Hàm (Pointers and Functions)

Con trỏ đóng vai trò rất quan trọng khi làm việc với hàm trong C++. Chúng giúp truyền dữ liệu hiệu quả hơn và cho phép hàm thay đổi giá trị của biến bên ngoài hàm.

Trước tiên, hãy xem cách truyền tham số mặc định trong C++.

---

# Truyền tham trị (Pass by Value)

Đây là cách truyền tham số **mặc định** trong C++.

Khi truyền một biến vào hàm, chương trình sẽ **tạo một bản sao** của biến đó. Mọi thay đổi trong hàm chỉ ảnh hưởng đến bản sao, **không ảnh hưởng đến biến gốc**.

Ví dụ:

```cpp
void khongThayDoi(int a)
{
    a = 100;
}

int main()
{
    int x = 10;

    khongThayDoi(x);

    std::cout << x; // 10
}
```

### Giải thích

```
x = 10

        truyền giá trị

x --------> a

```

Sau khi:

```cpp
a = 100;
```

thì

```
x = 10
a = 100
```

Hai biến hoàn toàn độc lập.

---

# Truyền bằng con trỏ (Pass by Pointer)

Nếu muốn hàm thay đổi trực tiếp biến gốc, ta truyền **địa chỉ** của biến thay vì giá trị.

Ví dụ

```cpp
void thayDoi(int* pA)
{
    *pA = 100;
}

int main()
{
    int x = 10;

    thayDoi(&x);

    std::cout << x;
}
```

Kết quả

```
100
```

---

## Giải thích

```
x = 10

      &
      │
      ▼

+---------+
|    x    |
|   10    |
+---------+
      ▲
      │
     pA
```

Trong hàm

```cpp
*pA = 100;
```

thực chất là

```
x = 100;
```

---

# Ưu điểm của Pass by Pointer

## Có thể thay đổi biến gốc

Ví dụ

```cpp
void tang(int* x)
{
    (*x)++;
}
```

Sau khi gọi

```cpp
int number = 5;

tang(&number);
```

Kết quả

```
number = 6
```

---

## Hiệu quả hơn

Giả sử một đối tượng có kích thước rất lớn.

Nếu truyền theo giá trị

```
Sao chép toàn bộ đối tượng
```

→ Chậm.

Nếu truyền con trỏ

```
Chỉ truyền địa chỉ (4 hoặc 8 byte)
```

→ Nhanh hơn rất nhiều.

---

# Nhược điểm

Con trỏ có thể bằng

```cpp
nullptr
```

Nếu cố giải tham chiếu

```cpp
*p
```

khi

```cpp
p == nullptr
```

chương trình sẽ bị lỗi.

Ví dụ

```cpp
void print(int* p)
{
    if(p != nullptr)
    {
        std::cout << *p;
    }
}
```

Đây là cách kiểm tra an toàn trước khi sử dụng con trỏ.

---

# Truyền mảng vào hàm

Trong C++, khi truyền một mảng vào hàm, mảng sẽ **tự động chuyển thành con trỏ** trỏ đến phần tử đầu tiên.

Ví dụ

```cpp
int numbers[5] = {1,2,3,4,5};
```

Khi gọi

```cpp
printArray(numbers,5);
```

thì thực chất là

```cpp
printArray(&numbers[0],5);
```

---

## Vì sao phải truyền thêm kích thước?

Trong hàm

```cpp
void printArray(int* arr)
```

chỉ có địa chỉ của phần tử đầu tiên.

Hàm **không biết mảng có bao nhiêu phần tử**.

Vì vậy luôn phải truyền thêm:

```cpp
size
```

Ví dụ

```cpp
void printArray(int* arr,int size)
{
    for(int i=0;i<size;i++)
    {
        std::cout<<arr[i]<<" ";
    }
}
```

Sử dụng

```cpp
int numbers[]={1,2,3,4,5};

printArray(numbers,5);
```

Kết quả

```
1 2 3 4 5
```

---

## Có thể viết theo hai cách

Hai khai báo dưới đây hoàn toàn giống nhau.

```cpp
void printArray(int* arr,int size)
```

hoặc

```cpp
void printArray(int arr[],int size)
```

Trình biên dịch đều hiểu là

```
int*
```

---

# Mảng có thể bị thay đổi

Vì hàm nhận địa chỉ của mảng nên có thể thay đổi dữ liệu bên trong.

Ví dụ

```cpp
void multiplyByTwo(int* arr,int size)
{
    for(int i=0;i<size;i++)
    {
        arr[i] *= 2;
    }
}
```

Sau khi gọi

```cpp
int numbers[]={1,2,3};

multiplyByTwo(numbers,3);
```

Kết quả

```
2 4 6
```

---

# Hàm trả về con trỏ

Một hàm cũng có thể trả về một con trỏ.

Điều này thường được dùng khi cấp phát bộ nhớ động.

Ví dụ

```cpp
int* createArray(int size)
{
    if(size<=0)
        return nullptr;

    int* arr=new int[size];

    for(int i=0;i<size;i++)
        arr[i]=0;

    return arr;
}
```

Sử dụng

```cpp
int* numbers=createArray(10);

numbers[0]=100;
```

Sau khi dùng xong

```cpp
delete[] numbers;

numbers=nullptr;
```

---

# Trách nhiệm giải phóng bộ nhớ

Nếu hàm dùng

```cpp
new
```

thì nơi gọi hàm phải dùng

```cpp
delete
```

Ví dụ

```cpp
int* arr=createArray(100);

// sử dụng

delete[] arr;
arr=nullptr;
```

Nếu quên

```cpp
delete[]
```

sẽ xảy ra

> **Memory Leak**

---

# Sai lầm nguy hiểm

## Không bao giờ trả về địa chỉ của biến cục bộ

Ví dụ sai

```cpp
int* badFunction()
{
    int number = 50;

    return &number;
}
```

Sau khi hàm kết thúc

```
number
```

đã bị hủy.

Con trỏ trả về sẽ trỏ tới vùng nhớ không còn hợp lệ.

Ví dụ

```cpp
int* p = badFunction();

std::cout << *p;
```

Đây là **Undefined Behavior**, chương trình có thể:

- Chạy sai.
- In giá trị rác.
- Bị Crash.

---

# Ví dụ đúng

```cpp
int* goodFunction()
{
    int* p = new int(50);

    return p;
}
```

Sử dụng

```cpp
int* value = goodFunction();

std::cout << *value;

delete value;
value = nullptr;
```

---

# Tổng kết

| Cách truyền | Có thay đổi biến gốc không? | Có sao chép dữ liệu không? |
|-------------|-----------------------------|----------------------------|
| Pass by Value | ❌ Không | ✅ Có |
| Pass by Pointer | ✅ Có | ❌ Không |

---

# Những điều cần nhớ

- 📌 Truyền theo giá trị → Hàm chỉ làm việc với bản sao.
- 📌 Truyền con trỏ → Hàm có thể thay đổi biến gốc.
- 📌 Mảng truyền vào hàm sẽ tự động trở thành con trỏ.
- 📌 Luôn truyền thêm kích thước của mảng.
- 📌 Nếu hàm trả về vùng nhớ được cấp phát bằng `new`, nơi gọi phải `delete`.
- 📌 Không bao giờ trả về địa chỉ của biến cục bộ.

---

# Bài tập

## Bài 1. Hoán đổi hai số (Swap)

Viết hàm:

```cpp
void swap(int* a, int* b);
```

Yêu cầu:

- Tạo hai số trong `main`.
- In giá trị trước khi đổi.
- Gọi hàm `swap()`.
- In lại kết quả sau khi đổi.

---

## Bài 2. Tạo mảng động

Viết hàm:

```cpp
int* createArray(int size);
```

Yêu cầu:

- Nhận kích thước mảng.
- Cấp phát động bằng `new`.
- Khởi tạo tất cả phần tử bằng `0`.
- Trả về con trỏ của mảng.
- Trong `main`, nhớ giải phóng bộ nhớ bằng `delete[]`.

---

## Bài 3. Thay đổi mảng

Viết hàm:

```cpp
void multiplyByTwo(int* arr, int size);
```

Yêu cầu:

- Nhận mảng và kích thước.
- Nhân đôi tất cả các phần tử trong mảng.
- In kết quả sau khi thay đổi.
