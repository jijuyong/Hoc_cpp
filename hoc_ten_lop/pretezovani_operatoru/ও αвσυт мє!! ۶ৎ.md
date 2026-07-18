## "Syntaktický cukr" (Đường cú pháp) là gì?
- Điều này có nghĩa là việc viết các toán tử thực chất chỉ là một cách viết bóng bẩy, giúp code đẹp và dễ đọc hơn đối với con người, còn bản chất máy tính khi biên dịch vẫn coi nó là một lời gọi hàm.


Vektor2D v1, v2, v3;
v3 = v1 + v2;

- Trình biên dịch sẽ tự động dịch câu lệnh trên thành một trong hai dạng hàm tùy thuộc vào cách bạn code:
- Dạng Member function (Hàm thành viên): v3 = v1.operator+(v2);
- Dạng Free function (Hàm tự do): v3 = operator+(v1, v2);

```c++
class Vektor2D {
public:
    double x, y;

    // Přetížení operátoru '+' jako ČLENSKÉ funkce
    // 'this' je levý operand (a), 'other' je pravý operand (b)
    Vektor2D operator+(const Vektor2D& other) {
        return Vektor2D(this->x + other.x, this->y + other.y);
    }
};
````

## Hàm thành viên (Členská) vs. Hàm tự do (Volná)

**Cách 1: Member Function (Hàm thuộc về Class)**
- Khi toán tử là một hàm thành viên, đối tượng bên trái dấu toán tử chính là thực thể gọi hàm (đại diện bằng con trỏ this), còn đối tượng bên phải là tham số truyền vào (other).
- Ưu điểm: Viết gọn, tự động có quyền truy cập vào các thuộc tính private của Class mà không cần xin phép
- Nhược điểm lớn: Ép buộc đối tượng bên trái phải là kiểu của Class đó.
    ~ Ví dụ: Nếu bạn muốn nhân một số với Vektor: *v1 * 5 -> Dịch thành v1.operator * (5)* (Chạy tốt).
    ~ Nhưng nếu viết ngược lại:  *5 * v1 -> Dịch thành 5.operator * (v1)* (Lỗi ngay lập tức, vì số 5 là kiểu số nguyên int, nó không có hàm nào tên là operator* để nhận Vektor cả).

**Cách 2: Free Function (Hàm tự do đứng ngoài Class)**
- Để giải quyết nhược điểm trên, người ta đưa hàm toán tử ra đứng độc lập bên ngoài. Lúc này hàm sẽ nhận cả 2 vế làm tham số: operator*(int số, Vektor2D v).
- Từ khóa friend (Bạn bè): Vì hàm này đứng ngoài Class, nên nếu các thuộc tính của Vektor (như x, y) bị ẩn đi bằng private, hàm tự do này sẽ không chạm vào được. Để cấp quyền, ta phải khai báo dòng chữ friend bên trong Class, giống như việc đưa "chìa khóa nhà" cho người ngoài.

## Bản chất của việc Quá tải toán tử dịch bit << để in bằng cout
- tại sao toán tử << bắt buộc phải dùng Hàm tự do (Free function)?


```c++
#include <iostream>

class Vektor2D {
public:
    double x, y;
    // ... konstruktor ...

    // Deklarujeme, že tato volná funkce je "přítel"
    // a smí přistupovat k našim 'private' a 'protected' členům
    friend std::ostream& operator<<(std::ostream& os, const Vektor2D& v);
};

// Imple    mentace volné funkce
std::ostream& operator<<(std::ostream& os, const Vektor2D& v) {
    os << "Vektor(" << v.x << ", " << v.y << ")";
    return os; // Musíme vrátit stream, aby fungovalo řetězení
}

int main() {
    Vektor2D v(1, 2);
    std::cout << "Můj vektor: " << v << std::endl; // Funguje!
}
```

## Phân biệt Class vs. Struct trong C++
 
Đặc điểm                          class                                   struct
------------------------------------------------------------------------------------------------------
Khi không ghi gì cả         Mặc định là private                      Mặc định là public
Khi kế thừa (: Base)    Mặc định là kế thừa đóng (private)      Mặc định là kế thừa mở (public)

## Những toán tử nâng cao đáng chú ý

* **Aritmetické:** `-`, `*`, `/`, `%`, `++`, `--`, `+=`, `-=` atd.
* **Relační:** `!=`, `<`, `>`, `<=`, `>=` (pro porovnávání objektů).
* **Přiřazovací:** `=` (operátor přiřazení má specifická pravidla, zejména tzv. "Rule of Three/Five/Zero").
* **Indexovací:** `[]` (pro přístup k prvkům jako u pole).
* **Vstupní:** `>>` (pro načítání objektu z `std::cin` nebo souboru).
* **Funkční volání:** `()` (umožňuje "volat" objekt jako funkci).





