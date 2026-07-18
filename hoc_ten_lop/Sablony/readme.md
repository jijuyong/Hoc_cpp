# Šablony (Templates - Khuôn mẫu)

## 1. Triết lý cốt lõi: Đừng lặp lại chính mình (DRY - Don't Repeat Yourself)
- Trước khi có Templates, nếu bạn muốn viết một hàm tìm số lớn nhất giữa 2 số, bạn sẽ phải làm thế này:

int getMax(int a, int b) { return (a > b) ? a : b; }
double getMax(double a, double b) { return (a > b) ? a : b; }
string getMax(string a, string b) { return (a > b) ? a : b; }

- Vấn đề: Thuật toán giống hệt nhau 100%, nhưng bạn phải copy-paste ra 3 hàm khác nhau chỉ vì chúng khác kiểu dữ liệu. Điều này làm code bị phình to và rất khó bảo trì.
- 💡 Giải pháp từ Templates: Bạn chỉ viết `một khuôn mẫu duy nhất`. Kiểu dữ liệu sẽ được đại diện bằng một chữ cái thay thế (thường đặt là chữ `T` - viết tắt của `Type`). Bạn đưa khuôn mẫu này cho trình biên dịch và bảo: `"Khi nào tôi dùng kiểu gì, ông tự nhìn vào đây mà sinh code tương ứng nhé!"`

## Bản chất cơ chế chạy ngầm (Template Instantiation)
- Có một bí mật cực kỳ quan trọng: Bản thân `Template KHÔNG phải là code thực thi, nó chỉ là một BẢN THIẾT KẾ (Recipe).`
- Khi bạn viết xong hàm template ` <typename T> T getMax(T a, T b) `, trình biên dịch đọc qua và... chưa sinh ra bất kỳ mã máy nào trong file .exe cả. Bộ nhớ RAM vẫn bằng 0
- Quá trình sinh code thực sự chỉ xảy ra ở hàm `main()` khi bạn gọi hàm:
    - Khi bạn gọi `getMax(5, 10)`: Trình biên dịch nhìn vào số 5 và 10  ->  `"À, đây là kiểu int". `Nó lập tức lấy bản thiết kế sao chép ra một hàm đời thực:` int getMax(int a, int b)` và biên dịch hàm đó.
    - Khi bạn gọi `getMax(3.14, 2.71)`: Nó lại `sinh tiếp một hàm đời thực khác: double getMax(double a, double b)`.Quá trình tự động sinh code này được gọi là Template Instantiation (Khởi tạo khuôn mẫu).

## Phân tích chi tiết hai loại Templates

### Šablony funkcí (Khuôn mẫu hàm)
```cpp
std::cout << getMax<double>(5, 10.5) << std::endl;
```
- Tại sao phải viết <double> ở giữa? Số 5 là int, số 10.5 là double. Trình biên dịch sẽ bị bối rối không biết nên chọn T là int hay double và sẽ báo lỗi (Template argument deduction failed).

- Giải pháp: Việc thêm <double> được gọi là Explicit Specification (Chỉ định hiển thị). Bạn `ép trình biên dịch phải coi T là double`. Lúc này số 5 (int) sẽ tự động được ép kiểu lên thành 5.0 (double) để `khớp với khuôn mẫu`.

### Šablony tříd (Khuôn mẫu lớp)
- Khuôn mẫu lớp mở rộng khái niệm này cho toàn bộ cấu trúc dữ liệu. Ví dụ của bạn về lớp `Box<T>` chính là cách mà thư viện chuẩn C++ tạo ra `std::vector<int> hay std::vector<std::string>.`

- Khi khai báo lớp, bắt buộc bạn phải chỉ định kiểu dữ liệu trong dấu ngoặc nhọn: `Box<int> intBox(123)`; vì trình biên dịch cần biết chính xác kích thước của biến item trong bộ nhớ ngay từ khi tạo đối tượng.

## Cái bẫy "ngầm" của Templates: Đọc lỗi và Biên dịch chậm
Dù Templates rất tuyệt vời nhưng nó có 2 điểm trừ kinh điển mà bạn cần biết:

1. Code Bloat (Phình to bộ nhớ): Nếu bạn dùng Box cho 20 kiểu dữ liệu khác nhau, trình biên dịch sẽ bí mật sinh ra 20 class khác nhau trong file chạy cuối cùng. File .exe của bạn sẽ nặng hơn.

2. Lỗi Biên dịch "Kinh dị": Vì đây là bản thiết kế lỏng lẻo, nếu bạn truyền vào một kiểu dữ liệu không hỗ trợ toán tử so sánh > (ví dụ bạn tự tạo ra một Class NhanVien nhưng chưa quá tải toán tử >), trình biên dịch sẽ quăng ra một tràng lỗi dài hàng trăm dòng, rất khó đọc.

3. Không thể tách file .h và .cpp thông thường: Do trình biên dịch cần toàn bộ "bản thiết kế" để sinh code lúc gọi hàm, nên toàn bộ mã nguồn của Template (cả thân hàm) bắt buộc phải được viết hoàn toàn trong file .h. Bạn không thể giấu phần triển khai sang file .cpp như các hàm bình thường được.