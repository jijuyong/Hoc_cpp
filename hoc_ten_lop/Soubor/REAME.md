# 07 - Làm việc với tệp (File Handling)

Cho đến nay, tất cả dữ liệu đầu vào đều được nhập từ bàn phím và kết quả của chương trình sẽ biến mất sau khi chương trình kết thúc.

Trong các ứng dụng thực tế, chúng ta cần **lưu trữ dữ liệu lâu dài** trên ổ đĩa. Việc làm việc với tệp (File) cho phép chương trình:

- 📖 Đọc dữ liệu từ các tệp có sẵn.
- 💾 Ghi dữ liệu ra tệp để sử dụng sau này.

Trong C++, thư viện dùng để làm việc với tệp là:

```cpp
#include <fstream>
```

---

# Đọc dữ liệu từ tệp (Input)

Để đọc dữ liệu từ một tệp, ta sử dụng lớp:

```cpp
std::ifstream
```

(`ifstream` = **Input File Stream**)

---

## Các bước cơ bản

### Bước 1. Thêm thư viện

```cpp
#include <fstream>
```

---

### Bước 2. Tạo đối tượng đọc tệp

```cpp
std::ifstream file("data.txt");
```

---

### Bước 3. Kiểm tra tệp có mở thành công hay không

Đây là bước rất quan trọng.

```cpp
if(file.is_open())
{
    // Đọc dữ liệu
}
```

Nếu không kiểm tra, chương trình có thể gặp lỗi khi tệp không tồn tại.

---

### Bước 4. Đọc dữ liệu

Có nhiều cách đọc khác nhau.

---

### Bước 5. Đóng tệp

```cpp
file.close();
```

Thực tế, khi đối tượng `ifstream` bị hủy thì tệp cũng sẽ tự động đóng.

Tuy nhiên, gọi:

```cpp
file.close();
```

vẫn là một thói quen tốt giúp chương trình rõ ràng hơn.

---

# Các cách đọc dữ liệu

## 1. Đọc từng dòng

Đây là cách phổ biến nhất khi xử lý tệp văn bản.

Sử dụng:

```cpp
std::getline()
```

Ví dụ

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream file("data.txt");

    std::string line;

    if(file.is_open())
    {
        while(std::getline(file, line))
        {
            std::cout << line << std::endl;
        }

        file.close();
    }

    return 0;
}
```

Ví dụ tệp

```
Apple
Banana
Orange
```

Kết quả

```
Apple
Banana
Orange
```

---

## 2. Đọc từng từ

Toán tử

```cpp
>>
```

sẽ đọc dữ liệu và tự động dừng khi gặp:

- khoảng trắng
- tab
- xuống dòng

Ví dụ

```cpp
std::ifstream file("data.txt");

std::string word;

if(file.is_open())
{
    while(file >> word)
    {
        std::cout << word << std::endl;
    }

    file.close();
}
```

Nếu tệp chứa

```
Hello World
C++
```

Kết quả

```
Hello
World
C++
```

---

# Ghi dữ liệu vào tệp (Output)

Để ghi dữ liệu vào tệp sử dụng:

```cpp
std::ofstream
```

(`ofstream` = **Output File Stream**)

---

## Tạo mới hoặc ghi đè tệp

Nếu tệp chưa tồn tại:

➡️ C++ sẽ tự tạo.

Nếu tệp đã tồn tại:

➡️ Nội dung cũ sẽ bị xóa và ghi lại từ đầu.

Ví dụ

```cpp
#include <fstream>

int main()
{
    std::ofstream file("output.txt");

    if(file.is_open())
    {
        file << "Dong thu nhat\n";
        file << "Dong thu hai\n";

        file.close();
    }

    return 0;
}
```

Sau khi chạy

```
output.txt

Dong thu nhat
Dong thu hai
```

---

# Ghi tiếp vào cuối tệp (Append)

Nếu không muốn xóa nội dung cũ, hãy mở tệp ở chế độ:

```cpp
std::ios::app
```

Ví dụ

```cpp
std::ofstream file("output.txt", std::ios::app);

if(file.is_open())
{
    file << "Dong moi\n";

    file.close();
}
```

Giả sử trước đó

```
Apple
Banana
```

Sau khi chạy

```
Apple
Banana
Dong moi
```

---

# Kiểm tra lỗi

Luôn luôn kiểm tra xem tệp có mở được hay không.

Ví dụ

```cpp
std::ifstream file("abc.txt");

if(!file.is_open())
{
    std::cout << "Khong mo duoc tep!" << std::endl;
}
```

Nếu tệp không tồn tại

```
Khong mo duoc tep!
```

---

# Tổng kết

| Lớp | Chức năng |
|------|-----------|
| `ifstream` | Đọc dữ liệu từ tệp |
| `ofstream` | Ghi dữ liệu vào tệp |
| `fstream` | Đọc và ghi trên cùng một tệp |

---

# Các hàm thường dùng

| Hàm | Ý nghĩa |
|------|----------|
| `is_open()` | Kiểm tra tệp có mở thành công hay không |
| `getline()` | Đọc một dòng |
| `close()` | Đóng tệp |
| `<<` | Ghi dữ liệu |
| `>>` | Đọc dữ liệu |

---

# Ví dụ tổng hợp

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ofstream out("hello.txt");

    out << "Hello C++\n";
    out << "File Handling";

    out.close();

    std::ifstream in("hello.txt");

    std::string line;

    while(std::getline(in, line))
    {
        std::cout << line << std::endl;
    }

    in.close();

    return 0;
}
```

Kết quả

```
Hello C++
File Handling
```

---

# Bài tập

## Bài 1. Nhật ký

Viết chương trình cho phép người dùng nhập các ghi chú.

Yêu cầu:

- Lưu mỗi dòng vào tệp:

```text
denicek.txt
```

- Khi người dùng nhập:

```text
KONEC
```

thì dừng chương trình.

Ví dụ

```
Nhap:
Hom nay troi dep
Hoc C++
KONEC
```

Tệp sẽ chứa

```
Hom nay troi dep
Hoc C++
```

---

## Bài 2. Đọc tệp

Viết chương trình mở tệp:

```text
denicek.txt
```

và in toàn bộ nội dung ra màn hình.

Yêu cầu:

- Đánh số từng dòng.

Ví dụ

```
1: Hom nay troi dep
2: Hoc C++
```

- Xử lý trường hợp tệp không tồn tại bằng cách hiển thị thông báo lỗi phù hợp.
