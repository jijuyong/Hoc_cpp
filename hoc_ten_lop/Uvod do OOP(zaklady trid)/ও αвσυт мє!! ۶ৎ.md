# 05 - Giới thiệu về Lập trình Hướng đối tượng (OOP)

Lập trình hướng đối tượng (**Object-Oriented Programming - OOP**) là một phương pháp lập trình giúp tổ chức mã nguồn thành các đối tượng có ý nghĩa.

Thay vì chỉ làm việc với **biến** và **hàm**, chúng ta xây dựng các **đối tượng (Objects)** có:

- 📦 **Thuộc tính (Attributes)** – dữ liệu của đối tượng.
- ⚙️ **Phương thức (Methods)** – hành động hoặc chức năng của đối tượng.

Trong C++, nền tảng của OOP là **Class (Lớp)**.

---

# Class (Lớp)

Class giống như **một bản thiết kế** hoặc **khuôn mẫu** để tạo ra các đối tượng.

Nó định nghĩa:

- Đối tượng sẽ lưu những dữ liệu gì.
- Đối tượng có thể thực hiện những chức năng gì.

Khai báo một Class bằng từ khóa:

```cpp
class
```

Ví dụ

```cpp
class Person
{
public:
    std::string name;
    int age;

    void sayHello()
    {
        std::cout << "Xin chao, toi la " << name << std::endl;
    }
};
```

Ở đây:

- `Person` là Class.
- `name`, `age` là thuộc tính.
- `sayHello()` là phương thức.

---

# Thuộc tính (Attributes)

Thuộc tính là các biến dùng để lưu thông tin của đối tượng.

Ví dụ

```cpp
class Person
{
public:
    std::string name;
    int age;
};
```

Một đối tượng có thể có:

```
name = "Jan"

age = 30
```

Các giá trị này chính là **trạng thái (State)** của đối tượng.

---

# Phương thức (Methods)

Phương thức là các hàm được định nghĩa bên trong Class.

Chúng mô tả hành vi của đối tượng.

Ví dụ

```cpp
void sayHello()
{
    std::cout << "Hello";
}
```

Khi gọi

```cpp
person.sayHello();
```

đối tượng sẽ thực hiện hành động đó.

---

# Object (Đối tượng)

Object là **một thể hiện (Instance)** được tạo từ Class.

Ví dụ

```cpp
Person person1;
```

Lúc này

```
Person
```

là bản thiết kế.

Còn

```
person1
```

là một đối tượng thật.

Có thể gán giá trị:

```cpp
person1.name = "Jan";
person1.age = 30;
```

Gọi phương thức:

```cpp
person1.sayHello();
```

Kết quả

```
Xin chao, toi la Jan
```

---

# Quan hệ giữa Class và Object

Có thể tưởng tượng:

```
Class

      ↓

Bản thiết kế ngôi nhà

      ↓

Object

      ↓

Ngôi nhà đã được xây
```

Hoặc

```
Class

↓

Khuôn làm bánh

↓

Object

↓

Chiếc bánh được làm từ khuôn
```

Một Class có thể tạo ra rất nhiều Object.

Ví dụ

```cpp
Person p1;
Person p2;
Person p3;
```

Mỗi Object có dữ liệu riêng.

```
p1

name = Jan

age = 30
```

```
p2

name = Anna

age = 25
```

---

# Con trỏ `this`

Bên trong mọi **phương thức không phải static**, C++ luôn cung cấp một con trỏ đặc biệt:

```cpp
this
```

Con trỏ này trỏ đến **chính đối tượng đang gọi phương thức**.

Ví dụ

```cpp
class Rectangle
{
private:
    int width;
    int height;

public:
    Rectangle(int width,int height)
    {
        this->width = width;
        this->height = height;
    }
};
```

Ở đây có hai biến cùng tên:

```cpp
width
```

- Một là tham số của hàm.
- Một là thuộc tính của Class.

Để phân biệt, dùng

```cpp
this->width
```

nghĩa là:

```
Thuộc tính width của đối tượng hiện tại.
```

---

# Encapsulation (Đóng gói)

Đóng gói là một trong những nguyên lý quan trọng nhất của OOP.

Ý tưởng:

> Dữ liệu của đối tượng không nên cho phép truy cập trực tiếp từ bên ngoài.

Thay vào đó:

- Ẩn dữ liệu.
- Chỉ cho phép truy cập thông qua các phương thức.

Điều này giúp:

- Tránh sửa dữ liệu ngoài ý muốn.
- Dễ bảo trì chương trình.
- Tăng tính bảo mật.

---

# Các mức truy cập

## public

Các thành viên có thể được truy cập từ bất kỳ đâu.

Ví dụ

```cpp
class Person
{
public:
    std::string name;
};
```

Trong `main`

```cpp
Person p;

p.name = "Jan";
```

Hoàn toàn hợp lệ.

---

## private

Các thành viên chỉ được truy cập bên trong Class.

Ví dụ

```cpp
class Person
{
private:
    std::string name;
};
```

Trong `main`

```cpp
Person p;

p.name = "Jan";
```

Sẽ báo lỗi.

Muốn thay đổi giá trị phải thông qua phương thức.

Ví dụ

```cpp
class Person
{
private:
    std::string name;

public:
    void setName(std::string n)
    {
        name = n;
    }

    void print()
    {
        std::cout << name;
    }
};
```

Sử dụng

```cpp
Person p;

p.setName("Jan");

p.print();
```

---

## protected

`protected` gần giống `private`.

Điểm khác:

Các Class kế thừa (Derived Class) vẫn có thể truy cập.

Nội dung này sẽ được học ở phần **Kế thừa (Inheritance)**.

---

# Mặc định của Class

Trong C++

```cpp
class
```

mọi thành viên đều mặc định là

```cpp
private
```

Ví dụ

```cpp
class Test
{
    int x;
};
```

thực chất tương đương

```cpp
class Test
{
private:
    int x;
};
```

---

# Ví dụ hoàn chỉnh

```cpp
#include <iostream>
#include <string>

class Person
{
private:
    std::string name;
    int age;

public:
    void setData(std::string n, int a)
    {
        name = n;
        age = a;
    }

    void print()
    {
        std::cout << name << ", " << age << " tuoi" << std::endl;
    }
};

int main()
{
    Person p;

    p.setData("Jan",30);

    p.print();

    return 0;
}
```

Kết quả

```
Jan, 30 tuoi
```

---

# Tổng kết

| Khái niệm | Ý nghĩa |
|-----------|----------|
| Class | Bản thiết kế để tạo đối tượng |
| Object | Đối tượng được tạo từ Class |
| Attribute | Thuộc tính (biến) của đối tượng |
| Method | Hàm của đối tượng |
| `this` | Con trỏ trỏ đến chính đối tượng hiện tại |
| public | Có thể truy cập từ mọi nơi |
| private | Chỉ truy cập được bên trong Class |
| protected | Truy cập trong Class và Class kế thừa |

---

# Những điều cần nhớ

- 📦 **Class** là bản thiết kế.
- 👤 **Object** là đối tượng được tạo từ Class.
- 📄 **Attribute** lưu dữ liệu.
- ⚙️ **Method** định nghĩa hành vi.
- 👉 **this** luôn trỏ đến đối tượng hiện tại.
- 🔒 **private** giúp bảo vệ dữ liệu.
- 🌍 **public** cho phép truy cập từ bên ngoài.

---

# Bài tập

## Bài 1. Lớp `Car`

Tạo Class:

```cpp
Car
```

Yêu cầu:

Thuộc tính (**private**):

```cpp
std::string brand;
int year;
```

Phương thức (**public**):

```cpp
void setData(std::string b, int y);
```

```cpp
void printInfo();
```

Ví dụ kết quả

```
Toyota, year 2020
```

---

## Bài 2. Sử dụng Class

Trong `main`:

- Tạo một đối tượng `Car`.
- Gọi `setData()` để gán giá trị.
- Gọi `printInfo()` để hiển thị thông tin.

Sau đó thử truy cập trực tiếp:

```cpp
car.brand = "BMW";
```

Quan sát lỗi của trình biên dịch và giải thích vì sao không thể truy cập thuộc tính `brand` khi nó được khai báo là `private`.
