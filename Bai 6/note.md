# GOTO (keyword)
- Có sẵn trong C/C++.
- Dùng để kiểm soát luồng chạy của chương trình.
- Có thể nhảy đến các vị trí mình mong muốn.
- Ứng dụng:
+ Dùng để thoát khỏi vòng lặp nhiều cấp độ, không giống như break (chỉ giúp ta thoát khỏi 1 vòng lặp), goto giúp ta thoát khỏi tất cả vòng lặp.


# SETJMP (library)
## Định nghĩa:
Đây là thư viện cung cấp các hàm như setjmp và longjmp để thực hiện nhảy giữa các hàm với mục đích là thiết kế những mã lỗi hay các thông báo mà ta muốn hiển thị tùy thuộc vào các điều kiện xử lý của chương trình. Khác với goto, setjmp có thể dùng để nhảy qua lại giữa nhiều hàm.

## Công dụng:
### Dùng để xử lí ngoại lệ:
+ phát hiện lỗi
+ xử lí lỗi:
```markdown:
- TRY  : Định nghĩa 1 khối lệnh có thể sinh ra lỗi.
- CATCH: Dùng để bắt những lỗi nằm trong TRY.
- THROW: Thông báo lỗi đó.
```


## jmp_buf;
```c
typedef struct
{
    unsigned long registers[30];
    void *pc;
    void *stack;
}jmp_buf;
```

## setjmp:
- Sử dụng để lưu lại trạng thái hiện tại của chương trình.
- Trả về 1 số nguyên, lần đầu trả về 0


## longjmp:
- Dùng để nhảy lại vị trí của setjmp và tiếp tục thực thi chương trình.

