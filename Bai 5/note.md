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