# Queue

- First in, first out (FIFO)

# Các thao tác cơ bản trên hàng đợi
- enqueue: thêm phần tử vào cuối hàng đợi
- dequeue: xóa phần tử từ đầu hàng đợi.
- front: lấy giá trị của phần tử đứng đầu hàng đợi.
- rear: lấy giá trị của phần tử đứng cuối hàng đợi.
- Kiểm tra hàng đợi đầy / rỗng.

# Các loại queue
- Linear
- Circular
- Priority

1. Linear queue
- front = rear = -1
- enqueue: 3 ==> front = 0, rear = 0
- enqueue: 4 ==> front = 0, rear = 1
- ... ==> rear+..., front = 0

Nếu rear = size -1 --> Queue full

- dequeue = 3 ==> front = 1, rear = size -1
- dequeue =... ==> frot ++ ==> front = rear

Nếu front == -1 hoặc front > rear --> Queue empty

## Nhược điểm:
- Khi những ô trống, nhưng k thể tận dụng lại được, ko thể ghi thêm giá trị mới vào.
- Muốn ghi lại vào, phải xóa hết phần tử ở những ô còn lại, vì rear phụ thuộc vào front để quay về 0
- 