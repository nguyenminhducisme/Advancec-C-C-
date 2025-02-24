# Pointer
```markdown
- Là 1 biến chứa địa chỉ bộ nhớ của một đối tượng khác (biến, mảng, hàm). Việc sử dụng con trỏ giúp chúng ta thao tác trên bộ nhớ một cách linh hoạt hơn.
+ int test = 0;      | Address: 0x01 , lấy địa chỉ trên RAM để cấp phát địa chỉ
                     | Value  : 0
+ int *ptr = &test;  | Address: 0xf1
                     | Value  : 0x01
```
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
   int *ptr = &a; // ptr lưu địa chỉ của biến a và gán vào con trỏ ptr
```

- Đặc tả: %p
- Trỏ tới địa chỉ đầu tiên trong vùng nhớ. Nếu ptr + 1 (1 ở đây là 1*sizeof(data_type)) thì sẽ nhảy tới vùng nhớ tiếp theo

# SIZE OF POINTER
```markdown
- Phụ thuộc vào kiến trúc máy tính, compiler
- Vdu: lập trình trên stm8 thì sizeof pointer là 1 bytes, còn trên stm32, esp32 là 4 bytes
* Kiểu dữ liệu ảnh hưởng tới việc đọc giá trị 
```
# VOID POINTER
```markdown
- Dùng để trỏ tới bất kỳ địa chỉ nào mà không cần biết data type của nó.
- Cú pháp: void *ptr_void

- Tác dụng:
Linh hoạt hơn khi sử dụng con trỏ, dùng 1 con trỏ có thể quản lý nhiều biến với nhiều kiểu dữ liệu khác nhau
Khi truy xuất phải ép kiểu để truy xuất đúng đủ dữ liệu

* Bản chất của mảng là các ô nhớ liền kề nhau
```
* Công thức tính độ dài của chuỗi:
```c
sizeof(arr)/sizeof(arr[0]);
```

# FUNCTION POINTER
- Là một biến mà giữ địa chỉ của hàm
- Cú pháp:
```bash
<return_type>(*func_pointer)(<data_type1>, <data_type2>, ...);
```
* Gọi qua con trỏ hàm khác gì gọi trực tiếp?
```bash
- Gọi 1 hàm trực tiếp sẽ diễn ra ở quá trình biên dịch, khi gọi hàm thông qua con trỏ thì hàm sẽ chạy trong runtime, tức phải đáp ứng 1 điều kiện j đó để gọi hàm.
- Gọi hàm trực tiếp sẽ nhanh hơn so với con trỏ hàm, do gọi hàm thông qua con trỏ phải thông qua nhiều bước.
```
# POINTER TO CONSTANT (CON TRỎ HẰNG)
- Là cách định nghĩa 1 con trỏ không thể thay đổi giá trị tại địa chỉ mà nó trỏ tới mà nó trỏ đến thông qua dereference nhưng giá trị tại địa chỉ đó có thể thay đổi.
```c
   data_type const* ptr_name;
   const data_type *ptr_name;
``` 
- Ứng dụng: Dùng để đọc dữ liệu tại địa chỉ trỏ tới và xử lí, thay vì thay đổi dữ liệu đó.
# CONSTANT POINTER (HẰNG CON TRỎ)
- Định nghĩa 1 con trỏ mà giá trị nó trỏ đến (địa chỉ ) không thể thay đổi. Tức là khi con trỏ này được khởi tạo thì nó sẽ không thể trỏ tới địa chỉ khác. Nhưng ở địa chỉ đó mình có thể đọc, ghi hay thay đổi giá trị thoải mái.
```c
int *const ptr = &val;
```
# CON TRỎ VỪA LÀ CON TRỎ HẰNG VỪA LÀ HẰNG CON TRỎ
- data_type const *const ptr_name; // cấu hình để không thay đổi bất kỳ giá trị hay địa chỉ nào, tránh users hay khách hàng thay đổi
nguyên gốc chương trình.
```c
int const *const ptr_const;
```

# NULL POINTER
data_type *ptr_name = NULL;
```markdown
* Tránh việc con trỏ trỏ tới các vùng địa chỉ khác, tạo ra những thay đổi không mong muốn.
* Tự động gán cho con trỏ địa chỉ 0x00: biểu thị cho việc không quản lý vùng nhớ nào.
```

# Pointer to Pointer
- Là một kiểu dữ liệu cho phép lưu địa chỉ của 1 con trỏ và thay đổi giá trị của con trỏ đó.
```c
int a = 5;
int *ptr = &a;
int **ptr_lev2 = &ptr;
printf("%d\n", **ptr_lev2);  // Output: 5
```
