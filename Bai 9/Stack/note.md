# 1. Cấu trúc dữ liệu

- Là cách tổ chức, và lưu trữ dữ liệu.
- cấu trúc dữ liệu tuyến tính: mảng, stack (ngăn xếp), hàng đợi (queue), danh sách liên kết (linked list).
- CTDL phi tuyến tính: đồ thị (Graphs), cây (Trees).
Tuyến tính là theo thứ tự có quy tắc nào đó.

# 2. Stack
### Là 1 CTDL tuân theo nguyên tắc LIFO.

### 2.1. Các thao tác cơ bản trên stack bao gồm

- push để thêm 1 phần tử vào đỉnh của stack.  // push -> top++
- pop để xóa một phần tử ở đỉnh của stack     // pop  -> top--
- peek/top để lấy một giá trị ở đỉnh của stack.
- Kiểm tra stack đầy.  // top = size -1 -> FULL
- Kiểm tra stack trống. // top = -1 -> EMPTY

### 2.2: Đặc điểm
- Lưu trữ một số lượng có hạn và phải quy định ngay từ đầu.

