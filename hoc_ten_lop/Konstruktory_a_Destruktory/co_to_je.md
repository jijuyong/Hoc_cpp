1. Konstruktor (Hàm khởi tạo) – "Giây phút món đồ ra đời"
Hãy tưởng tượng bạn đặt mua một con robot đồ chơi. Ngay khi con robot được nhấc ra khỏi hộp (đối tượng được tạo ra), bạn muốn nó phải có sẵn pin và tên của bạn dán trên đó. Konstruktor chính là người làm việc đó.

  - Đặc điểm:
    ~ Tự động: Bạn không cần gọi nó, nó tự chạy ngay khi bạn viết Person osoba1(...).
    ~ Tên: Phải trùng khít với tên của Lớp (Class).
    ~ Không có kiểu trả về: Không có int, không có void.
  - Phân loại:
    ~ Výchozí konstruktor (Mặc định): Giống như robot xuất xưởng đồng loạt, con nào cũng có 5 cái cửa (pocetDveri = 5) hoặc chưa có tên.
    ~ Konstruktor có tham số: Giống như robot đặt làm riêng. Bạn đưa tên "Jan" vào, nó sẽ dán tên "Jan" lên người robot ngay lập tức.

2. Destruktor (Hàm hủy) – "Giây phút món đồ bị bỏ đi"
Khi con robot bị hỏng hoặc bạn không chơi nữa (đối tượng kết thúc vòng đời), bạn cần tháo pin ra để pin không bị chảy nước làm hỏng môi trường. Destruktor là người "dọn dẹp" cuối cùng.

 - Đặc điểm:
    ~ Tên: Giống tên Class nhưng có dấu ngã (~) phía trước (Ví dụ: ~Person()).
    ~ Không tham số: Bạn không thể bảo nó "hủy một nửa" hay "hủy kiểu này kiểu kia". Nó chỉ đơn giản là xóa sạch.
 - Tự động gọi khi:
    ~ Hàm kết thúc (biến cục bộ biến mất).
    ~ Bạn dùng lệnh delete cho một con trỏ đối tượng.

3. Tại sao chúng cực kỳ quan trọng? (Quản lý bộ nhớ)
Đây là lý do chính mà lập trình viên C++ cần chúng: Dynamická alokace paměti (Cấp phát bộ nhớ động).

- Trong Konstruktor: Bạn dùng new để thuê một mảnh đất trong bộ nhớ máy tính.
- Trong Destruktor: Bạn dùng delete để trả lại mảnh đất đó.

Nếu bạn quên Destruktor: Máy tính sẽ bị "rò rỉ bộ nhớ" (Memory Leak). Giống như việc bạn thuê khách sạn nhưng lúc đi không trả phòng, cứ để đó và người khác không vào ở được, cuối cùng khách sạn hết chỗ.