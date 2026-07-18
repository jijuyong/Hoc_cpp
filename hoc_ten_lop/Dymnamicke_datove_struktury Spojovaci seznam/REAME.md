# Linked List (Spojovací seznam)

## 1. Linked List là gì?

Linked List (Danh sách liên kết) có thể tưởng tượng như **một đoàn tàu hỏa**.

- 🚂 Mỗi toa tàu là một **Node (Uzel)**.
- 🍬 Trong mỗi toa có chứa **Data**.
- 🔗 Mỗi toa có một **Next Pointer (Ukazatel)** để nối với toa phía sau.
- 🚩 Toa đầu tiên được giữ bởi một con trỏ gọi là **Head**.
- 🛑 Toa cuối cùng không nối với ai, nên `Next = nullptr`.

```
Head
  │
  ▼
+---------+      +---------+      +---------+
| Data:10 | ---> | Data:20 | ---> | Data:30 | ---> nullptr
+---------+      +---------+      +---------+
```

---

# 2. Ưu điểm của Linked List

## Kích thước động (Dynamic Size)

Không giống mảng (Array), Linked List có thể mở rộng bất cứ lúc nào.

Nếu cần thêm dữ liệu, chỉ cần tạo một Node mới và nối vào danh sách.

Không cần tạo lại toàn bộ cấu trúc.

---

## Thêm/Xóa rất nhanh

Ví dụ muốn thêm một Node vào giữa hai Node.

Ban đầu:

```
10 ---> 20
```

Sau khi thêm Node có giá trị 15:

```
10 ---> 15 ---> 20
```

Ta chỉ cần thay đổi các con trỏ (`Next`), không phải di chuyển toàn bộ dữ liệu như Array.

---

# 3. Nhược điểm

## Truy cập chậm

Muốn lấy Node thứ 100, ta **không thể truy cập trực tiếp** như Array.

Bắt buộc phải đi lần lượt:

```
Head
 ↓
1 → 2 → 3 → ... → 100
```

Độ phức tạp:

```
O(n)
```

Trong khi Array:

```
O(1)
```

---

## Tốn bộ nhớ hơn

Mỗi Node ngoài dữ liệu còn phải lưu thêm một con trỏ `Next`.

Ví dụ:

```
+------------+
| Data | Next|
+------------+
```

Do đó Linked List tốn nhiều bộ nhớ hơn Array.

---

## Phải tự quản lý bộ nhớ

Node được cấp phát bằng `new`.

Sau khi sử dụng xong phải `delete`.

Nếu quên sẽ gây:

> **Memory Leak**

---

# 4. Các thao tác cơ bản

## Tạo danh sách rỗng

```cpp
Node* head = nullptr;
```

Danh sách chưa có Node nào.

---

## Thêm Node vào đầu

Ý tưởng:

1. Tạo Node mới.
2. Cho Node mới trỏ tới Node đầu hiện tại.
3. Cập nhật `head`.

Ví dụ:

Trước:

```
Head
 │
 ▼
10 → 20 → nullptr
```

Sau khi thêm 5:

```
Head
 │
 ▼
5 → 10 → 20 → nullptr
```

---

## Duyệt danh sách (Traversal)

Bắt đầu từ `head`.

Đi theo `Next` cho đến khi gặp `nullptr`.

```cpp
Node* temp = head;

while (temp != nullptr)
{
    std::cout << temp->data << " ";

    temp = temp->next;
}
```

---

# 5. Các thành phần cần nhớ

## Node (Uzel)

Một Node gồm hai phần:

- Data
- Next

Ví dụ:

```cpp
struct Node
{
    int data;
    Node* next;
};
```

---

## Data

Là giá trị được lưu trong Node.

Ví dụ:

```
10
20
30
```

---

## Next

Là con trỏ chỉ sang Node tiếp theo.

Ví dụ:

```
10 --> 20 --> 30
```

---

## Head

Là con trỏ giữ Node đầu tiên.

Nếu mất `head`, ta sẽ mất đường dẫn đến toàn bộ danh sách.

---

## nullptr

Đánh dấu Node cuối cùng.

```
10 → 20 → 30 → nullptr
```

Điều này có nghĩa:

> Không còn Node nào phía sau nữa.

---

# Minh họa

```
Head
 │
 ▼
+------------------+
| Data = 10        |
| Next ------------|----------------+
+------------------+                |
                                    ▼
                           +------------------+
                           | Data = 20        |
                           | Next ------------|------------+
                           +------------------+            |
                                                          ▼
                                                 +------------------+
                                                 | Data = 30        |
                                                 | Next = nullptr   |
                                                 +------------------+
```

---

# So sánh Array và Linked List

| Array | Linked List |
|--------|-------------|
| Kích thước cố định | Kích thước động |
| Truy cập rất nhanh (`O(1)`) | Truy cập chậm (`O(n)`) |
| Thêm/Xóa chậm | Thêm/Xóa nhanh |
| Ít tốn bộ nhớ | Tốn thêm bộ nhớ cho con trỏ |
| Không cần `new/delete` | Phải tự quản lý bộ nhớ |

---

# Ghi nhớ

- 🚂 **Node (Uzel):** Một toa tàu.
- 🍬 **Data:** Dữ liệu bên trong Node.
- 🔗 **Next:** Con trỏ nối đến Node kế tiếp.
- 🚩 **Head:** Con trỏ đầu danh sách.
- 🛑 **nullptr:** Kết thúc danh sách.
