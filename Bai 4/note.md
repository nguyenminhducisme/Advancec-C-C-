# POINTER

## 1. Định nghĩa

Con trỏ là một biến chứa địa chỉ bộ nhớ của một đối tượng khác (biến, mảng, hàm). Việc sử dụng con trỏ giúp thao tác trên bộ nhớ linh hoạt hơn.

Ví dụ:
```c
int test = 0;  // Biến bình thường
int *ptr = &test;  // Con trỏ trỏ đến địa chỉ của test
```

- `test` có địa chỉ: `0x01`, giá trị: `0`
- `ptr` có địa chỉ: `0xf1`, giá trị: `0x01`

## 2. Toán tử `*` và `&`

- Dấu `*` (dereference): Truy xuất giá trị mà con trỏ trỏ đến.
- Dấu `&` (address-of): Lấy địa chỉ của biến.

Ví dụ:
```c
int a = 10;
int *ptr = &a;
printf("%d\n", *ptr);  // In ra 10
```

## 3. Kích thước của Con trỏ (Size of Pointer)

- Phụ thuộc vào kiến trúc máy tính và compiler.
- Ví dụ:
  - STM8: 1 byte
  - STM32, ESP32: 4 bytes

## 4. Con trỏ kiểu `void`

- `void *` có thể trỏ đến bất kỳ kiểu dữ liệu nào.
- Khi truy xuất phải ép kiểu.

Ví dụ:
```c
void *ptr;
int a = 10;
ptr = &a;
printf("%d\n", *(int*)ptr);
```

## 5. Con trỏ hàm (Function Pointer)

- Giữ địa chỉ của một hàm và gọi nó gián tiếp.
- Cú pháp:

```c
<return_type> (*func_pointer)(<param_type1>, <param_type2>, ...);
```

Ví dụ:
```c
int add(int a, int b) { return a + b; }
int (*ptr_func)(int, int) = &add;
printf("%d\n", ptr_func(2, 3)); // Output: 5
```

## 6. Con trỏ Hằng (Constant Pointer)

- `const data_type *ptr;` → Không thay đổi giá trị tại địa chỉ trỏ đến.
- `data_type *const ptr;` → Không thay đổi địa chỉ của con trỏ.
- `const data_type *const ptr;` → Cả giá trị lẫn địa chỉ đều không thay đổi.

Ví dụ:
```c
const int *ptr1;   // Không thể thay đổi giá trị nhưng có thể trỏ đến địa chỉ khác.
int *const ptr2;   // Không thể trỏ đến địa chỉ khác nhưng có thể thay đổi giá trị.
const int *const ptr3; // Cả hai đều không thể thay đổi.
```

## 7. Con trỏ NULL

```c
int *ptr = NULL;
```
- Tránh con trỏ trỏ đến vùng nhớ không xác định.
- `NULL` biểu thị con trỏ không trỏ đến bất kỳ địa chỉ nào.

## 8. Con trỏ trỏ đến con trỏ (Pointer to Pointer)

- Lưu địa chỉ của một con trỏ khác.

Ví dụ:
```c
int a = 10;
int *ptr = &a;
int **ptr2 = &ptr;
printf("%d\n", **ptr2);  // Output: 10
```

