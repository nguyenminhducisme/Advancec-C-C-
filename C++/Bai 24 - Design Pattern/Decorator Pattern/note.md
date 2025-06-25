# DECORATOR PATTERN

- Thuộc nhomms __structural patterns__, cho phép thêm các chức năng hoặc hành vi mới cho một đối tượng mà không cần thay đổi cấu trúc của lớp đối tượng đó.

- Giúp mở rộng tính năng của các đối tượng bằng cách bao bọc chúng trong lớp decorator đặc biệt.

## Các thành phần chính

- __Component__: giao diện định nghĩa chức năng ban đầu hoặc bắt buộc phải có.

- __Concrete component__: các đói tượng chính cần thêm chức năng

- __Decorator__:
    - Lớp cơ sở trừu tượng cho tất cả các chức năng
    - Tham chiếu tới đối tượng cần thêm (_thường là con trỏ tới đối tượng_), gọi chức năng đã có và/hoặc mở rộng

- __Concrete decorator__: các lớp cụ thể kế thừa từ __Decorator__ để thêm chức năng mới cho Component


