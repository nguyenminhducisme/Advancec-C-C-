# STDARG Library

- Cung cấp các phương thức để làm việc với các hàm có số lượng input parameter không cố định.
- Các hàm như printf hay scanf là ví dụ điển hình

__+ va_list:__ là 1 kiểu dữ liệu để đại diện cho danh sách các đối số biến đổi, mang con trỏ kiểu char.
__+ va_start:__ Bắt đầu 1 danh sách đối số biến đổi, hiểu đơn giản là nó bắt đầu từ đâu.
__+ va_arg:__ truy cập các đối số trong danh sách, va_arg(va_list ap, data_type).
__+ va_copy:__ trỏ vào địa chỉ của các đối số trong biến danh sách
__+ va_end:__ kết thúc việc sử dụng danh sách đối số biến đổi. Nó cần gọi trước khi kết thúc hàm.


