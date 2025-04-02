#include<stdio.h>

int val1 = 10;
int val2 = 3;
int *const ptr_const = &val1;
/*
The value the pointer points to can be changed.
The address the pointer holds cannot be changed
*/
/*
A constant pointer (int *const ptr) is a pointer that must always point to the same memory location.However, the value at that
memory location can be modified. This makes it useful in scenarios where the memory address must remain unchanged while still 
allowing data modification.
*/
int main()
{
    printf("%p\n", ptr_const);
    printf("%d\n", *ptr_const);

    // *ptr_const = 100;
    val1 = 100;
    printf("%d\n", *ptr_const); 
   
//    ptr_const = &val2; Nếu trỏ tới 1 địa chỉ khác sẽ báo lỗi ngay
   printf("%p\n", ptr_const);
}