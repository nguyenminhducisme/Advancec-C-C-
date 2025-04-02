# EXTERN
- Dùng để thông báo rằng một biến hoặc hàm đã được khai báo ở 1 nơi khác trong chương trình hoặc trong 1 file.
- Giúp chương trình hiểu hàm đã được khai báo và ta đang muốn sử dụng lại.
- Chỉ được khai báo (sử dụng lại), không có quyền thay đổi nó.
- Dùng để thiết kế thư viện là chủ yếu.
- Chỉ sử dụng cho biến toàn cục, không thể sử dụng cho biến cục bộ vì phạm vi của nó bị giới hạn trong hàm.

# STATIC

## STATIC LOCAL
- Giữ giá trị của biến qua các lần gọi hàm và giữ phạm vi của biến chỉ trong hàm đó.
Các đặc điểm của local static variables:
+ Địa chỉ được cấp phát 1 lần duy nhât, giữ nguyên xuyên suốt chương trình.
+ Giữ nguyên phạm vi local của biến.
+ Giữ giá trị của biến qua các lần gọi hàm.

## STATIC GLOBAL
- Khi static được sử dụng với biến global, nó hạn chế phạm vị của biến đó chỉ trong file nguồn hiện tại. Tức nếu gọi biến này hoặc hàm này ở ngoài bằng extern thì không thể.
```bash
warning: 'display' used but never defined
    5 | extern void display();
      |             ^~~~~~~
 undefined reference to `display'
```
- Ứng dụng: Dùng để thiết kế các file thư viện.

# VOLATILE
- Dùng để báo hiệu cho tình biên dịch rằng 1 biến có thể thay đổi ngẫu nhiên, ngoài sự kiểm soát của chương trình. Việc này ngăn chặn trình biên dịch tối ưu hóa hoặc xóa bỏ các thao tác trên biến đó, giữ cho các thao tác trên biến được thực hiện như đã định nghĩa. 
- Giả dụ có 1 biến sau nhiều lần chạy mà mình không động tới nó thì trình biên dịch sẽ tự động xóa đi, kể cả mình có cập nhật lại bằng cách gán giá trị cho nó hay bất kì cách gì thì cũng không có tác dụng.

# REGISTER
- Chỉ ra ý muốn rằng muốn lưu biến ở trong thanh ghi của CPU chứ không phải trong bộ nhớ RAM. Việc này nhằm tăng tốc độ truy cập và xử lí. 
- Chỉ sử dụng cho biến cục bộ, không thể khai báo biến register global vì nó sẽ bị chiếm dụng xuyên suốt chương trình, nên nhà sx đã ngăn chặn việc này bằng cách không cho phép khai báo như vậy.
------------------------------------------------------------------------------------
|   ALU                    2        Register        1                RAM            |
|Arithmetic Logic        <===      R1 = 6        <===               int i = 5;      |
|    Unit                ===>      R2 = +1       ===>                 ++i;          |
|                          3          ...          4                 i = 6;         |
|                                                                                   |
------------------------------------------------------------------------------------

# So sánh các từ khóa

<p align = "center">
<img src = "https://github.com/user-attachments/assets/e86cb852-f651-4850-ad37-20508a36e83d" width = "1200" height = "230">