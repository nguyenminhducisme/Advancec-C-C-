# BIT MASK

## 1. Vấn đề về bộ nhớ

Nếu khai báo biến theo cách thông thường:

```c
int gender;   // Nam = 0, Nữ = 1
int status;   // 0/1
int option1;  // 0/1   
int option2;  // 0/1
int option3;  // 0/1
int option4;  // 0/1
```

Tổng cộng, chúng ta tốn **24 bytes** bộ nhớ. Trong khi đó:

- `int` có thể lưu giá trị từ `0 -> 2^32 - 1`, nhưng ta chỉ cần hai giá trị `0` và `1`.

### Cách tối ưu bộ nhớ

Chúng ta có thể sử dụng các kiểu dữ liệu nhỏ hơn:

```c
int8_t, uint8_t, ...
uint8_t status;   // 0/1
uint8_t option1;  // 0/1   
uint8_t option2;  // 0/1
uint8_t option3;  // 0/1
uint8_t option4;  // 0/1
```

Sau khi tối ưu bằng `uint8_t`, tổng bộ nhớ còn **6 bytes**.

## 2. Tối ưu hơn với Bit Mask

Chúng ta có thể sử dụng **Bit Masking** để lưu trữ tất cả trạng thái chỉ trong **1 byte**:

```c
uint8_t options = 0b00000000; // Ban đầu tất cả đều là 0
```

- Đặt bit: `options |= (1 << bit_position);`
- Xóa bit: `options &= ~(1 << bit_position);`
- Kiểm tra bit: `(options & (1 << bit_position))`

Ví dụ:

```c
options |= (1 << 0); // Bật option1
options |= (1 << 3); // Bật option4
options &= ~(1 << 0); // Tắt option1
if (options & (1 << 3)) {  // Kiểm tra option4
    // Option 4 đang bật
}
```

## 3. Định nghĩa Bitmask

**Bitmask** là kỹ thuật sử dụng các bit để lưu trữ và thao tác với các flags hoặc trạng thái.

Bitmask giúp:

- **Tiết kiệm bộ nhớ**, thay vì dùng nhiều biến riêng lẻ.
- **Thực hiện các phép toán nhanh hơn** nhờ toán tử bitwise.
- **Dễ dàng quản lý nhiều trạng thái** trong một biến duy nhất.

## 4. Toán tử Bitwise

| Toán tử     | Ký hiệu | Ý nghĩa            |                 |
| ----------- | ------- | ------------------ | --------------- |
| NOT         | `~`     | Đảo bit            |                 |
| AND         | `&`     | Phép AND bitwise   |                 |
| OR          | \`      | \`                 | Phép OR bitwise |
| XOR         | `^`     | Phép XOR bitwise   |                 |
| Shift Left  | `<<`    | Dịch bit sang trái |                 |
| Shift Right | `>>`    | Dịch bit sang phải |                 |

Ví dụ:

```c
uint8_t user1 = 0b00001110;
uint8_t user2 = 0b10101001;

user1 = ~user1;  // 0b11110001
user2 = ~user2;  // 0b01010110

user1 & user2;   // 0b00001000
user1 | user2;   // 0b10101110
user1 ^ user2;   // 0b10100111

user1 >> 1;  // 0b00000111
user1 >> 5;  // 0b00000000
user1 << 6;  // 0b10000000
```

---

Với Bitmask, chúng ta có thể tối ưu bộ nhớ đáng kể khi làm việc với nhiều trạng thái hoặc flags.

