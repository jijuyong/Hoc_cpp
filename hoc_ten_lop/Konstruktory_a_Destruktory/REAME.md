# Constructor và Destructor trong C++

## 1. Constructor (Konstruktor)

Constructor là **hàm đặc biệt** được gọi **tự động khi một đối tượng được tạo ra**.

Có thể tưởng tượng giống như lúc bạn mua một con robot đồ chơi.

Ngay khi mở hộp:

- 🤖 Robot đã có pin.
- 🏷️ Robot đã được dán tên.
- ⚙️ Robot đã sẵn sàng hoạt động.

Constructor chính là người thực hiện việc khởi tạo đó.

---

## Đặc điểm

- ✅ Được gọi **tự động** khi tạo đối tượng.
- ✅ Tên **phải trùng với tên của Class**.
- ✅ **Không có kiểu trả về** (`void`, `int`... đều không được).

Ví dụ:

```cpp
class Person
{
public:
    Person()
    {
        std::cout << "Constructor\n";
    }
};

int main()
{
    Person p;
}
```

Kết quả:

```
Constructor
```

---

# 2. Các loại Constructor

## Constructor mặc định (Default Constructor)

Không có tham số.

Ví dụ:

```cpp
class Car
{
public:
    int doors;

    Car()
    {
        doors = 5;
    }
};
```

Khi tạo:

```cpp
Car c;
```

Giá trị:

```
doors = 5
```

---

## Constructor có tham số (Parameterized Constructor)

Cho phép truyền dữ liệu ngay khi tạo đối tượng.

```cpp
class Person
{
public:
    std::string name;

    Person(std::string n)
    {
        name = n;
    }
};
```

Sử dụng:

```cpp
Person p("Jan");
```

Sau khi tạo:

```
name = "Jan"
```

---

# 3. Destructor (Destruktor)

Destructor là hàm được gọi **tự động khi đối tượng kết thúc vòng đời**.

Có thể tưởng tượng như:

Sau khi chơi xong robot:

- Tháo pin.
- Cất đồ.
- Dọn dẹp.

Destructor chính là người làm công việc cuối cùng.

---

## Đặc điểm

- Có dấu `~` trước tên Class.
- Không có tham số.
- Không có kiểu trả về.
- Chỉ có **một Destructor** trong mỗi Class.

Ví dụ:

```cpp
class Person
{
public:
    ~Person()
    {
        std::cout << "Destructor\n";
    }
};
```

---

# 4. Khi nào Destructor được gọi?

## Biến cục bộ kết thúc

```cpp
void test()
{
    Person p;
}
```

Khi hàm `test()` kết thúc:

```
Destructor
```

được gọi tự động.

---

## Dùng delete

```cpp
Person* p = new Person();

delete p;
```

Ngay sau `delete`:

```
Destructor
```

được gọi.

---

# 5. Constructor và Dynamic Memory

Đây là ứng dụng quan trọng nhất của Constructor và Destructor.

## Constructor

Dùng `new` để cấp phát bộ nhớ.

```cpp
class Array
{
private:
    int* data;

public:
    Array()
    {
        data = new int[100];
    }
};
```

Khi đối tượng được tạo:

```
Heap
+----------------------+
| int[100]             |
+----------------------+
        ▲
        |
      data
```

---

## Destructor

Giải phóng bộ nhớ bằng `delete`.

```cpp
class Array
{
private:
    int* data;

public:
    Array()
    {
        data = new int[100];
    }

    ~Array()
    {
        delete[] data;
        data = nullptr;
    }
};
```

Sau khi Destructor chạy:

```
Heap

(bộ nhớ đã được giải phóng)
```

---

# 6. Vì sao Constructor và Destructor quan trọng?

Nếu Constructor dùng `new` mà Destructor **không dùng `delete`**, chương trình sẽ bị:

> **Memory Leak**

Ví dụ:

```cpp
class BadClass
{
private:
    int* data;

public:
    BadClass()
    {
        data = new int[100];
    }

    // Không có Destructor
};
```

Mỗi lần tạo đối tượng:

```
new int[100]
```

RAM sẽ bị chiếm thêm.

Khi đối tượng bị hủy:

```
data biến mất
```

nhưng vùng nhớ trên Heap vẫn còn.

Sau nhiều lần:

```
RAM
██████████████████████████
```

➡️ Chương trình ngày càng chiếm nhiều bộ nhớ.

---

# 7. Ví dụ hoàn chỉnh

```cpp
#include <iostream>

class Person
{
private:
    std::string name;

public:
    Person(std::string n)
    {
        name = n;
        std::cout << "Constructor\n";
    }

    ~Person()
    {
        std::cout << "Destructor\n";
    }
};

int main()
{
    Person p("Jan");
}
```

Kết quả:

```
Constructor
Destructor
```

---

# Constructor vs Destructor

| Constructor | Destructor |
|-------------|------------|
| Được gọi khi tạo đối tượng | Được gọi khi đối tượng bị hủy |
| Khởi tạo dữ liệu | Giải phóng tài nguyên |
| Tên giống Class | Tên giống Class nhưng có `~` |
| Có thể có tham số | Không có tham số |
| Có thể có nhiều Constructor (Overloading) | Chỉ có một Destructor |

---

# Ghi nhớ

- 🏗️ **Constructor** → Khởi tạo đối tượng.
- 🧹 **Destructor** → Dọn dẹp và giải phóng tài nguyên.
- 💾 Nếu dùng `new` trong Constructor thì nên dùng `delete` trong Destructor.
- ⚠️ Quên `delete` sẽ gây **Memory Leak**.
