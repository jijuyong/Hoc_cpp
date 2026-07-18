# **10 - Hlavičkové soubory (`.h`) a Implementační soubory (`.cpp`)**

- Trong các ngôn ngữ hiện đại như C#, Java hay Python, bạn chỉ có 1 file duy nhất cho mỗi lớp, vừa khai báo vừa viết code xử lý luôn. Nhưng C++ ra đời từ sớm và nó chọn một lối đi riêng dựa trên triết lý tách biệt:

*File .h (Header - Tiêu đề)*: Đóng vai trò là Bản quảng cáo / Menu nhà hàng. Nó chỉ nói cho thế giới biết: "Tôi có món ăn này (tên hàm), giá bao nhiêu (tham số và kiểu trả về)". Nó không nấu ăn.

*File .cpp (Source - Nguồn)*: Đóng vai trò là Căn bếp. Đây là nơi đầu bếp thực sự làm việc, chứa công thức và các bước nấu ăn chi tiết (thân hàm { ... }).


## **Proč kód rozdělovat?Tại sao lại phải khổ sở chia làm 2 file?**
- Máy tính không thông minh như bạn nghĩ. Khi bạn dùng lệnh #include *"Matematika.h*", trình tiền xử lý (Preprocessor) của C++ chỉ làm một việc cực kỳ "ngây thơ": Nó *sao chép toàn bộ nội dung của file .h* đó và dán thẳng vào vị trí dòng chữ #include.

- Hãy tưởng tượng nếu bạn viết toàn bộ code (thân hàm) vào file .h, rồi file main.cpp gọi nó, file User.cpp `cũng gọi nó`. Khi biên dịch, cả main.cpp và User.cpp `đều chứa một đoạn code giống hệt nhau. Khi đem đi ghép nối (Link), trình liên kết (Linker) sẽ hét lên: "Ơ! Tôi thấy có 2 hàm secti() giống hệt nhau, tôi biết lấy cái nào bây giờ?"` -> Đây chính là lỗi Vị phạm quy tắc một định nghĩa (ODR violation).
- Giải pháp: Bằng cách chỉ để "khai báo sơ sài" ở file .h và dán nó khắp nơi, bạn không vi phạm luật. Còn "thân hàm thực sự" thì chỉ nằm duy nhất ở một file .cpp, đảm bảo hàm đó chỉ được dịch ra mã máy đúng 1 lần.

## Tệp tiêu đề (.h hoặc .hpp)
Tệp tiêu đề (header) định nghĩa giao diện (những gì mô-đun có thể làm).
Những gì thuộc về tệp này:
- Khai báo các hàm (nguyên mẫu hàm - prototypes).
- Định nghĩa các lớp (class) và cấu trúc (struct).
- Khai báo các biến toàn cục extern (mặc dù tốt nhất là nên tránh sử dụng biến toàn cục).
- Định nghĩa các hằng số (const, constexpr).
- Định nghĩa các hàm inline.

## Cơ chế chống chèn nhiều lần (Include Guards)
Nếu tệp A.h include B.h, đồng thời tệp C.h cũng include B.h, và tệp main.cpp của bạn lại include cả A.h lẫn C.h, thì tệp B.h sẽ bị chèn hai lần vào main.cpp. Điều này dẫn đến lỗi "trùng lặp định nghĩa".

Để ngăn chặn điều này, người ta sử dụng các bộ bảo vệ gọi là "include guards".

**Cách hiện đại**(được khuyến khích): Viết dòng này vào ngay hàng đầu tiên của tệp tiêu đề:
```cpp
#pragma once
```
**Cách truyền thống (hoạt động trên mọi trình biên dịch):**

```cpp
#ifndef NAZEV_SOUBORU_H  
#define NAZEV_SOUBORU_H

// ... celý obsah .h souboru ...

#endif // NAZEV_SOUBORU_H
```
- Cả hai cách tiếp cận đều đảm bảo rằng nội dung của tệp sẽ chỉ được chèn một lần duy nhất vào một đơn vị dịch (một tệp .cpp).

## Tệp thực thi (.cpp)
Tệp thực thi (source) chứa định nghĩa (thân hàm) của các hàm và phương thức đã được khai báo trong tệp tiêu đề tương ứng.
Những gì thuộc về tệp này:
- `#include tệp .h` tương ứng (đặt lên đầu tiên để kiểm tra tính nhất quán).
- `#include các thư viện khác` chỉ cần thiết cho phần triển khai thực tế (ví dụ: <iostream> để in dữ liệu).
- Định nghĩa (thân hàm) của các hàm và phương thức.
- Định nghĩa các biến tĩnh private (private static variables).

### Sự khác biệt giữa #include <...> và #include "..."

**#include <knihovna>**: Yêu cầu trình biên dịch tìm kiếm tệp trong các thư mục hệ thống chuẩn (nơi cài đặt các thư viện sẵn có như iostream, string, vector, v.v.).

**#include "soubor.h"**: Yêu cầu trình biên dịch tìm kiếm tệp trước tiên ở thư mục hiện tại (hoặc trong các thư mục được chỉ định cụ thể trong dự án), sau đó mới tìm kiếm trong các thư mục hệ thống. Thường dùng cho các tệp tiêu đề nội bộ tự tạo của dự án.

## Cơ chế hoạt động khi biên dịch?
Quá trình biên dịch bao gồm hai giai đoạn chính:
- Biên dịch (Compilation): * Trình biên dịch lấy `main.cpp` và chèn nội dung của `Matematika.h` vào đó. Quá trình này tạo nên một `"đơn vị dịch"` (translation unit). Nó sẽ kiểm tra xem bạn gọi hàm secti có đúng cách không (dựa theo khai báo trong .h). Sau đó, nó tạo ra tệp `main.o` (tệp đối tượng), chứa mã máy từ `main.cpp` kèm theo một ghi chú rằng nó đang thiếu phần định nghĩa thực sự của hàm secti.
      Trình biên dịch lấy `Matematika.cpp` và chèn nội dung của `Matematika.h` vào. Nó tạo nên một `"đơn vị dịch"`. Tại đây, nó biên dịch phần thân của hàm secti và tạo ra tệp Matematika.o, chứa mã máy đã biên dịch của hàm secti.
- Liên kết (Linking): * Trình liên kết (Linker) thu gom hai tệp `main.o` và `Matematika.o.`
    Nó nhận thấy tệp main.o cần dùng hàm secti.
    Nó tìm thấy hàm secti nằm trong tệp Matematika.o.
    Trình liên kết nối chúng lại với nhau để tạo ra tệp thực thi cuối cùng (ví dụ: program.exe).



