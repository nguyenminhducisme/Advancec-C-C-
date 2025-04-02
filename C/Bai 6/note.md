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

```c
#include<stdio.h>
#include<setjmp.h>
#include<string.h>

jmp_buf buf;

char error_code[50];

#define TRY   if((exception = setjmp(buf)) ==0)
#define CATCH(x) else if(exception == x)
#define THROW(x, str) \
if(x==1 || x==2)        \
strcpy( error_code, #str); \
longjmp(buf,x);   


typedef enum{
    NO_ERROR,
    NO_EXIST,
    DIVIDE_BYZERO
}ERROR_CODES;

int exception;

double divide(int a, int b)
{
    if(a==0 && b==0)
    {
        THROW(NO_EXIST, khong ton tai);
    }
    else if(b == 0 && a!=0)
    {
        THROW(DIVIDE_BYZERO, chia cho 0);
    }
    return (double)a/b;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    TRY
    {
       printf("Ket qua: %.3lf\n", divide(a,b));
    }
    CATCH(DIVIDE_BYZERO)
    {
       printf("%s\n", error_code);
    }
    CATCH(NO_EXIST)
    {
       printf("%s\n", error_code);
    }
    return 0;
}
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

