# Pointer

- Là 1 biến chứa địa chỉ bộ nhớ của một đối tượng khác (biến, mảng, hàm). Việc sử dụng con trỏ giúp chúng ta thao tác trên bộ nhớ một cách linh hoạt hơn.
+ int test = 0;  | Address: 0x01 , lấy địa chỉ trên RAM để cấp phát địa chỉ
                 | Value  : 0
+ int *ptr = &test;  | Address: 0xf1
                     | Value  : 0x01
Dấu *: 
1. Khi khai báo con trỏ: một biến con trỏ sẽ chứa địa chỉ của một biến khác
VD: 
```bash
   int a=10;
   int *ptr = &a; => ptr lưu địa chỉ của biến a
```
2. Khi truy xuất giá trị thông qua con trỏ (dereference), dấu * được sử dụng để truy xuất giá trị của biến mà con trỏ đang trỏ đến
```bash
   int a=10;
   int *ptr = &a; ptr lưu địa chỉ của biến a
   printf("%d\n", *ptr);  // In ra giá trị của a (tức là 10)
```

Dấu &: lấy địa chỉ tại nơi khai báo con trỏ
```bash
   int a=10;
   int *ptr = &a; ptr lưu địa chỉ của biến a và gán vào con trỏ ptr
```

- Đặc tả: %p
- Trỏ tới địa chỉ đầu tiên trong vùng nhớ. Nếu ptr + 1 (1 ở đây là 1*sizeof(data_type)) thì sẽ nhảy tới vùng nhớ tiếp theo

# SIZE OF POINTER
- Phụ thuộc vào kiến trúc máy tính, compiler và ktruc vi xử lí
- Vdu: lập trình trên stm8 thì sizeof pointer là 1 bytes, còn trên stm32, esp32 là 4 bytes
* Kiểu dữ liệu ảnh hưởng tới việc đọc giá trị 

# VOID POINTER
- Dùng để trỏ tới bất kỳ địa chỉ nào mà không cần biết data type của nó.