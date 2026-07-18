OOP (Lập trình hướng đối tượng)

1. Třída (Class) và Objekt (Object)
- Hãy hiểu Tên lớp (Class) là một bản thiết kế (blueprint). Nó không tồn tại trong bộ nhớ như một dữ liệu thực tế, nó chỉ mô tả: "Nếu bạn tạo ra một đối tượng từ tôi, nó sẽ có những biến này và hàm này".
- Đối tượng (Object) là một thể hiện (instance) cụ thể được xây dựng từ bản thiết kế đó.
- Ví dụ: Lớp Person là bản thiết kế về con người. Khi bạn khai báo Person anhA;, thì anhA là một con người thực sự, chiếm diện tích trong bộ nhớ, có tên và tuổi cụ thể.

2. Atributy (Thuộc tính) và Metody (Phương thức)
Đây là hai thành phần bên trong một Class:
- Atributy: Là các biến (dữ liệu) để lưu trữ trạng thái của đối tượng. (Ví dụ: int vek;)
- Metody: Là các hàm (hành động) để định nghĩa hành vi của đối tượng. (Ví dụ: void pozdrav();)

3. Ukazatel this (Con trỏ this)
Trong C++, this là một con trỏ đặc biệt trỏ thẳng đến địa chỉ của chính đối tượng đang thực thi hàm đó.

Obdelnik(int delka, int sirka) {
    this->delka = delka; 
}

Ở đây, tên tham số truyền vào là delka trùng tên với biến của lớp. this->delka giúp máy tính hiểu: "Hãy lấy giá trị của tham số delka gán vào biến delka của lớp này".

4. Zapouzdření (Tính đóng gói)
Đây là nguyên tắc "chia quyền truy cập" để bảo vệ dữ liệu. C++ dùng các từ khóa (Access Specifiers):

Từ khóa	                         Ý nghĩa
_______________________________________________________________________________________________________
public                          Mọi nơi đều có thể gọi hoặc sửa đổi (Thường dùng cho các phương thức).

private                         Chỉ các hàm bên trong lớp đó mới được chạm vào
                                (Thường dùng cho các thuộc tính/biến).

protected                       Giống private nhưng cho phép các lớp con (kế thừa) được sử dụng.

