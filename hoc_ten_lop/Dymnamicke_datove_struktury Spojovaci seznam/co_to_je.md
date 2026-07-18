1. Spojovaci seznamy(Linked List)
Nó giống như một Đoàn tàu hỏa rời:
- Mỗi toa tàu là một Uzel (Nút).
- Trong toa tàu có chở Kẹo (Data).
- Mỗi toa tàu có một cái Móc xích (Ukazatel - Chỉ số) để nối với toa ngay sau nó.
- Đặc biệt: Toa cuối cùng không nối với ai cả, móc xích của nó để trống (nullptr). Con chỉ cần nắm dây kéo của Toa đầu tiên (Head) là con kéo được cả đoàn tàu!

2. Tại sao dùng Đoàn tàu này thích hơn? (Ưu điểm)
- Muốn dài bao nhiêu cũng được (Dynamická velikost): Nếu con có thêm kẹo, con chỉ cần lấy thêm một toa mới rồi móc vào đuôi tàu. Không cần phải mua một cái hộp mới to hơn.

- Thêm/Bớt siêu nhanh (Vkládání/Mazání): * Hãy tưởng tượng con muốn thêm một toa màu Xanh vào giữa toa số 1 và toa số 2.
     ~ Con chỉ cần: Tháo xích giữa toa 1 và 2 -> Móc toa 1 vào toa Xanh -> Móc toa Xanh vào toa 2. Xong! Con không cần phải nhấc tất cả các toa khác ra chỗ khác.

3. (Nhược điểm)
- Tìm đồ rất lâu (Pomalý přístup): Nếu con muốn biết toa số 100 có kẹo gì, con không thể nhảy vèo tới đó được. Con phải bắt đầu từ Toa đầu tiên, đi qua toa 2, toa 3... đếm đến 100 mới thấy. Rất mệt đúng không?
- Tốn chỗ hơn (Větší paměť): Vì mỗi toa tàu ngoài chỗ đựng kẹo, còn phải tốn thêm chỗ để gắn cái Móc xích nữa.
- Phải dọn dẹp cẩn thận (Správa paměti): Khi con chơi xong, con phải tự tay tháo từng toa và cất đi (delete). Nếu con cứ vứt bừa bãi ra sàn, mẹ sẽ mắng vì "rác" đầy nhà đấy!

4. Cách chúng ta chơi (Operace)
- Tạo tàu mới: Con cầm một cái dây kéo nhưng chưa móc vào toa nào cả (head = nullptr).
- Thêm toa vào đầu: Con lấy một toa mới, móc xích của nó vào toa mà con đang cầm trên tay, rồi giờ con coi toa mới này là "đầu đàn".
- Điểm danh: Con nhìn toa đầu tiên, xong nhìn theo cái xích để sang toa tiếp theo, rồi lại nhìn xích để sang toa tiếp... cho đến khi thấy cái xích cuối cùng nằm im trên sàn (nullptr) thì dừng lại.

Tóm lại cho bé dễ nhớ:
1. Uzel (Nút): Toa tàu (đựng kẹo + móc xích).
2. Data: Kẹo trong toa.
3. Next: Cái móc xích nối toa sau.
4. Head: Cái dây kéo để con cầm đoàn tàu.
5. nullptr: Hết tàu rồi, không còn toa nào nữa!

[ Head ] ---> [ Uzel 1 | Data: 10 | Next ] ---> [ Uzel 2 | Data: 20 | Next ] ---> [ Uzel 3 | Data: 30 | Next: nullptr ]


