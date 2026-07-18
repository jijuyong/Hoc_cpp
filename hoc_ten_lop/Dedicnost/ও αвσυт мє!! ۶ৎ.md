## Bản chất của Kế thừa là gì?

Hãy tưởng tượng bạn có một bản thiết kế Điện thoại cơ bản (Person): có tính năng nghe, gọi, nhắn tin.
Sau đó, bạn muốn làm một bản thiết kế Điện thoại thông minh (Student). Thay vì ngồi vẽ lại từ đầu tính năng nghe, gọi, nhắn tin, bạn chỉ cần **kế thừa lại bản thiết kế cũ** và vẽ thêm tính năng: lướt web, chụp ảnh.

* **Základní (Base) třída:**: lớp Bố Mẹ(parent , superclass) - bố để lại ở dạng public hoặc protected thì con đều được thừa kế hết mà không cần phải tự mình làm lại từ đầu.
* **Odvozená (Derived) třída:**: Lớp Con - Thằng con sinh ra, tự động kế thừa (dědí) toàn bộ gen di truyền và tài sản từ bố. hoac Tự phát triển thêm cái mới (Mở rộng): Thằng con lớn lên trong thời đại mới, nó đi học thêm và có những thứ mà bố nó ngày xưa không có.

Quan hệ **"IS-A"** (Là một): Student kế thừa Person vì bản chất Sinh viên *LÀ* MỘT Con người. Sinh viên có đầy đủ đặc tính của một con người (tên, tuổi, chiều cao) nhưng có thêm đặc tính riêng (mã số sinh viên, trường học).

```c++
// Základní třída
class Person {
    // ...
};

// Odvozená třída 'Student' dědí z 'Person'
class Student : public Person {
    // ...
};
```


### Bí mật của các Modifikátory přístupu (Từ khóa truy cập)
Đây là chỗ rất nhiều người hay bị lẫn lộn. Hãy tưởng tượng một ngôi nhà (Tập thể gia đình) để hiểu 3 từ khóa này:

*public* (Công cộng): Như cái biển số nhà treo ngoài cửa. Ai đi qua đường (main()) cũng nhìn thấy, người trong nhà (Student) đương nhiên thấy.

*private* (Riêng tư): Như nhật ký bí mật của bố mẹ (Person). Con cái (Student) ở chung nhà cũng không được phép đọc trực tiếp. Người ngoài (main()) càng không.

*protected* (Bảo vệ - Bí mật gia đình): Đây là món quà dành riêng cho Kế thừa. Nó giống như két sắt gia đình. Người ngoài (main()) không được sờ vào, nhưng con cái (Student) thì được quyền mở ra lấy dùng.

| Přístup v `Person`    |       Přístup z `main()`   | Přístup ze `Student`       |
-----------------------------------------------------------------------------------
| `public` jmeno;       |      `person.jmeno` (OK)   |  `this->jmeno` (OK)        |
| `protected` vek;      |     `person.vek` (CHYBA)   |   `this->vek` (OK)         |
| `private` rodneCislo; | `person.rodneCislo` (CHYBA)| `this->rodneCislo` (CHYBA) |

### Cơ chế Khởi tạo và Hủy diệt (Konstruktory a Destruktory)

Quy trình xây dựng (Constructor):
Khi bạn tạo ra một (`Student`), máy tính sẽ tự động làm theo thứ tự:

1. Xây phần Cốt lõi con người trước: Gọi Person() trước.
2. Xây phần Đắp thêm của sinh viên sau: Gọi Student() sau.

Phân tích đoạn code khởi tạo khó hiểu này:

```c++
class Person {
protected:
    string jmeno;
public:
    Person(string jmeno) { // Konstruktor základní třídy
        this->jmeno = jmeno;
    }
};

class Student : public Person {
private:
    string skola;
public:
    // 'Person(jmeno)' je volání konstruktoru základní třídy
    Student(string jmeno, string skola) : Person(jmeno) {
        Dấu hai chấm : chính là Initializer list (Danh sách khởi tạo).
        this->skola = skola;
    }
};
```

Thằng con `Student` khi nhận được 2 tham số là jmeno và skola, nó sẽ lập tức "gửi" chiếc tên `jmeno` này ngược lên cho bố nó xử lý qua lệnh `Person(jmeno)`. Sau khi bố nạp xong tên vào người, thằng con mới thong thả `tự nạp nốt skola cho mình`.

#### Quy trình phá hủy (Destructor):
**Ngược hoàn toàn** với lúc xây. Khi một đối tượng Student chết đi:
1. Nó phải lột bỏ lớp áo sinh viên trước: Gọi `~Student()` trước để xóa trường học, sách vở...
2. Sau đó mới giải thể đến phần con người: Tự động gọi `~Person()`.               

## Ghi đè và Gọi phương thức của Cha (Person::pozdrav())
Khi lớp cha có hàm pozdrav() (Chào kiểu bình thường), lớp con cũng có hàm pozdrav() (Chào kiểu sinh viên). Bản thân thằng con đã che mốc hàm của cha nó *(redefine/override)*.

Nhưng nếu thằng con muốn: "Tôi muốn chào lịch sự như cha tôi trước, rồi sau đó mới giới thiệu trường của tôi", nó sẽ làm thế này:

```c++
void Student::pozdrav() {
    // 1. Gọi đúng hàm pozdrav() của cha để thực hiện việc chào cơ bản.
    Person::pozdrav(); 
    // :: - "Hãy dùng hàm của lớp Cha".
    
    // 2. Viết thêm phần đặc trưng của sinh viên vào sau
    cout << " a studuji na " << this->skola << "." << endl;
}
```






