# 02 - Reference và Con trỏ (Reference vs Pointer)

Trong C++, **Reference (tham chiếu)** và **Pointer (con trỏ)** đều cho phép truy cập gián tiếp đến dữ liệu trong bộ nhớ. Tuy nhiên, chúng hoạt động theo những cách khác nhau và được sử dụng trong những trường hợp khác nhau.

---

# Con trỏ (Pointer)

Con trỏ là một biến dùng để **lưu địa chỉ của một biến khác**.

Ví dụ:

```cpp
int value = 10;

int* ptr = &value;
```

Ở đây:

- `value` lưu giá trị `10`.
- `ptr` lưu địa chỉ của `value`.

```
value
+-------+
|  10   |
+-------+
    ▲
    │
   ptr
```

---

## Đặc điểm của Pointer

- Có thể bằng `nullptr`.
- Có thể thay đổi để trỏ sang vùng nhớ khác.
- Muốn đọc hoặc thay đổi dữ liệu phải dùng toán tử `*`.

Ví dụ

```cpp
int a = 10;
int b = 20;

int* p = &a;

*p = 100;
```

Kết quả

```
a = 100
```

Sau đó có thể đổi sang

```cpp
p = &b;
```

Lúc này

```
p
```

không còn trỏ tới `a` nữa mà trỏ tới `b`.

---

# Reference (Tham chiếu)

Reference là **một tên khác (alias)** của một biến đã tồn tại.

Nó **không tạo ra vùng nhớ mới**.

Ví dụ

```cpp
int value = 10;

int& ref = value;
```

Lúc này

```
ref
```

và

```
value
```

là **cùng một biến**.

```
      value
         │
         ▼
     +-------+
     |  10   |
     +-------+
         ▲
         │
        ref
```

---

## Đặc điểm của Reference

- Phải được khởi tạo ngay khi khai báo.
- Không thể bằng `nullptr`.
- Không thể đổi sang tham chiếu tới biến khác.
- Sử dụng giống hệt biến bình thường, không cần `*`.

Ví dụ

```cpp
int number = 10;

int& ref = number;

ref = 50;
```

Kết quả

```
number = 50
```

---

# So sánh Pointer và Reference

| Pointer | Reference |
|----------|-----------|
| Lưu địa chỉ của biến | Là bí danh (alias) của biến |
| Có thể bằng `nullptr` | Không thể bằng `nullptr` |
| Có thể đổi sang trỏ biến khác | Không thể đổi sang biến khác |
| Cần `*` để truy cập giá trị | Sử dụng như biến bình thường |
| Có thể cấp phát động (`new`) | Không dùng cho cấp phát động |

---

# Ví dụ so sánh

## Pointer

```cpp
int a = 10;
int b = 20;

int* p = &a;

p = &b;
```

Sau cùng

```
p
```

trỏ tới

```
b
```

---

## Reference

```cpp
int a = 10;
int b = 20;

int& ref = a;
```

Không thể làm

```cpp
ref = &b;
```

Reference không thể đổi sang tham chiếu tới biến khác.

Nếu viết

```cpp
ref = b;
```

điều đó **không đổi Reference**, mà chỉ sao chép giá trị của `b` vào `a`.

Kết quả

```
a = 20
b = 20
```

Reference vẫn tham chiếu đến `a`.

---

# Khi nào dùng Reference?

Reference thường được dùng khi:

- Truyền tham số vào hàm (**Pass by Reference**).
- Muốn thay đổi trực tiếp biến gốc.
- Tránh sao chép các đối tượng lớn.
- Làm cho mã nguồn dễ đọc hơn.

Ví dụ

```cpp
void increase(int& x)
{
    x++;
}

int number = 5;

increase(number);
```

Kết quả

```
number = 6
```

Không cần truyền địa chỉ hay dùng `*`.

---

# Khi nào dùng Pointer?

Pointer phù hợp khi:

- Có thể không trỏ tới dữ liệu nào (`nullptr`).
- Cần thay đổi đối tượng mà con trỏ trỏ tới.
- Làm việc với `new` và `delete`.
- Xây dựng các cấu trúc dữ liệu động như:
  - Linked List
  - Tree
  - Graph

Ví dụ

```cpp
int* p = nullptr;
```

Sau đó

```cpp
p = new int(10);
```

và cuối cùng

```cpp
delete p;
```

---

# Ví dụ Pass by Reference

```cpp
void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}
```

Sử dụng

```cpp
int a = 5;
int b = 9;

swap(a,b);
```

Kết quả

```
a = 9

b = 5
```

Không cần dùng Pointer.

---

# Ví dụ Pass by Pointer

```cpp
void swap(int* x,int* y)
{
    int temp = *x;

    *x = *y;

    *y = temp;
}
```

Gọi hàm

```cpp
swap(&a,&b);
```

Kết quả cũng giống như Reference.

---

# Tổng kết

| Đặc điểm | Pointer | Reference |
|----------|----------|-----------|
| Có thể là `nullptr` | ✅ | ❌ |
| Có thể đổi sang biến khác | ✅ | ❌ |
| Cần toán tử `*` | ✅ | ❌ |
| Dễ sử dụng | ❌ | ✅ |
| Dùng với `new/delete` | ✅ | ❌ |
| Thường dùng để truyền tham số | Có | Rất phổ biến |

---

# Những điều cần nhớ

- 📌 **Pointer** lưu địa chỉ của biến.
- 📌 **Reference** là bí danh của biến.
- 📌 Pointer có thể bằng `nullptr`.
- 📌 Reference phải được khởi tạo ngay khi tạo.
- 📌 Pointer có thể đổi sang vùng nhớ khác.
- 📌 Reference luôn gắn với một biến duy nhất trong suốt vòng đời của nó.
- 📌 Reference thường được dùng để truyền tham số vào hàm.

---

# Bài tập

## Bài 1. Tạo Reference

1. Tạo biến:

```cpp
double temperature = 36.6;
```

2. Tạo Reference:

```cpp
double& refTemperature = temperature;
```

3. Thay đổi giá trị thông qua Reference:

```cpp
refTemperature = 37.2;
```

4. In ra biến `temperature` để kiểm tra kết quả.

---

## Bài 2. Hiểu về Reference

Tạo hai biến:

```cpp
int a = 10;
int b = 20;
```

Tạo Reference:

```cpp
int& ref = a;
```

Sau đó thực hiện:

```cpp
ref = b;
```

In ra:

```cpp
a
b
```

Quan sát kết quả và giải thích vì sao:

```
a = 20

b = 20
```

Reference vẫn tham chiếu đến `a`, chỉ có giá trị của `b` được gán cho `a`.

---

## Bài 3. Hoán đổi bằng Reference

Viết hàm:

```cpp
void swap(int& x, int& y);
```

Trong `main`:

```cpp
int c = 5;
int d = 9;
```

Gọi:

```cpp
swap(c,d);
```

In kết quả để kiểm tra:

```
c = 9

d = 5
```
