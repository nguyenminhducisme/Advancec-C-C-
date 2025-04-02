# MEMORY LAYOUT (Phân vùng nhớ)

- Chương trình .exe hay .hex được lưu ở SSD (với .exe) hay FLASH (với .hex). Khi run code thì những chương trình này được copy vào RAM để thực thi.

## TEXT SEGMENT (CODE SEGMENT)
- Chứa:
- Mã máy: tập hợp các lệnh thực thi chương trình.
- Quyền truy cập: ĐỌC và THỰC THI, nhưng không có quyền GHI (TỨC KHÔNG CÓ QUYỀN THAY ĐỔI).
- Lưu hằng số toàn cục (const), chuỗi hằng - string literal đối với macOS, nhưng ở windows những biến này lưu ở data
```c
char *ptr = "Hello world\n"; // string literal: chuỗi hằng nhưng lại nằm ở data vì ta đang dùng windows - read only, chỉ đọc không thể ghi
```

## DATA SEGMENT (initialized data)
- Chứa các biến toàn cục được khởi tạo với giá trị khác 0
- Chưa các biến static (global +local) được khởi tạo với giá trị khác 0.
- Quyền truy cập là ĐỌC và GHI, tức là có thể ĐỌC và THAY ĐỔI GIÁ TRỊ của biến.
- Tất cả các biến sẽ được thu hồi sau khi chương trình kết thúc.
```c
const int a = 0; // vãn lưu ở vùng data - nhưng chỉ đọc không thể ghi, chứ không phải lưu ở text
```

## BSS SEGMENT (uninitialized data) - Dữ liệu chưa được khởi tạo
- Như data, nhưng sẽ chứa biến toàn cục với static khởi tạo với gtri = 0 hoặc không gán giá trị.

## STACK 
- Chứa các biến cục bộ (trừ static local), tham số truyền vào của 1 hàm.
- Hằng số cục bộ, có thể thay đổi thông qua con trỏ.
- Quyền truy cập, đọc và ghi, có thể đọc và thay đổi nó.
- Sau khi ra khỏi hàm thì tự động thu hồi vùng nhớ.
- Hoạt động theo nguyên tắc LIFO: Last In, First Out.

## HEAP
###  Cấp phát động:
- Heap được sử dụng để cấp phát bộ nhớ động trong quá trình thực thi của ctrinh.
- C: malloc(), calloc(), realloc() và free();
- C++: new, delete;
- Không tự động thu hồi vùng nhớ, phải thu hồi thủ công bằng hàm free(ptr);
```c

                        malloc(): kiểu void
                        realloc(): cũng kiểu void nhưng cấp phát thêm bộ nhớ hoặc giảm đi
                        calloc(): như malloc();


     int main()
{
   // char arr[20]; // cấp phát tĩnh, không thể thay đổi giá trị
    /*
    - Nhược: 
    Nếu nhập khoảng 25 kí tự thì lại không đủ vùng nhớ
    Nếu nhập 15 kí tự thì lại dư ô nhớ  ==> tốn bộ nhớ
    */

    int size = 5; // 5*4 = 20 bytes

    uint16_t *ptr = (uint16_t *) malloc(size * sizeof(uint16_t)); // con trỏ trỏ tới phần tử đầu tiên , cấp phát 10 bytes = 5*2

    ptr[0] = 5;

    for(int i = 0; i<size; i++)
    {
        printf("dia chi: %d: %p -Value: %d\n", i, ptr+i, *(ptr+i));
    }
  //  malloc(5); // 0x01 0x02 0x03 0x04 0x05 : Lấy ở Heap

}
```

| Hàm       | Chức năng | Cách sử dụng | Giá trị khởi tạo | Khi nào dùng? |
|-----------|----------|-------------|------------------|--------------|
| `malloc`  | Cấp phát bộ nhớ động với kích thước xác định. | `ptr = (int*) malloc(n * sizeof(int));` | Không khởi tạo (giá trị rác). | Khi cần cấp phát một vùng nhớ có kích thước cố định. |
| `calloc`  | Cấp phát bộ nhớ động và khởi tạo về 0. | `ptr = (int*) calloc(n, sizeof(int));` | Khởi tạo tất cả các ô nhớ về 0. | Khi cần cấp phát vùng nhớ mà các giá trị ban đầu phải bằng 0. |
| `realloc` | Thay đổi kích thước vùng nhớ đã cấp phát. | `ptr = (int*) realloc(ptr, new_size);` | Giữ lại dữ liệu cũ (nếu mở rộng thì phần mới có thể chứa giá trị rác). | Khi cần thay đổi kích thước bộ nhớ đã cấp phát trước đó. |
| `free`    | Giải phóng bộ nhớ đã cấp phát. | `free(ptr); ptr = NULL;` | Không ảnh hưởng đến nội dung của vùng nhớ trước đó (chỉ đánh dấu là trống). | Khi không cần dùng vùng nhớ nữa để tránh rò rỉ bộ nhớ. |
