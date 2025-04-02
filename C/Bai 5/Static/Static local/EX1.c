#include<stdio.h>

int *ptr = NULL;

void count()
{
    static int a = 0;  // Biến static giữ nguyên giá trị trước đó
    /*
    Tại sao làm được vậy?
    Biến static nằm trong phân vùng data/bss, tức không thay đổi địa chỉ của biến static
    Địa chỉ của biến a không thay đổi suốt chương trình
    */
    ptr = &a;
    printf("a = %d\n", ++a);
   
}

int main()
{
    count(); // a = 1 0x02: 1
    count(); // a = 2 0x02: 2
    count(); // a = 3 0x03: 3

    *ptr = 99;

    count();
    count();
    return 0;
}