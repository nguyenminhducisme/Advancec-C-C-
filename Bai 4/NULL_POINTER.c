#include<stdio.h>

int main()
{
    int a = 3;
    int *ptr = NULL; // Khi chưa sử dụng con trỏ thì khai báo là NULL, Địa chỉ là 0x00: Không trỏ tới vùng nhớ nào
    ptr = &a;
    ++a;
    
    if(ptr == NULL)
    printf("Null pointer");
    else
    printf("Not a NULL pointer");


   return 0;
}