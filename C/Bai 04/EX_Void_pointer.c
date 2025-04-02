#include<stdio.h>
#include<stdint.h>



int main()
{
    void *ptr_void; // Khai báo con trỏ void trỏ đến các kiểu dữ liệu khác nhau
    int var_int = 10; // Gán địa chỉ biến int cho con trỏ void
    ptr_void = &var_int;
    printf("Dia chi: %p, int: %d\n", ptr_void, *(int *)ptr_void);
    printf("\n");
    
    double var_double = 3.14;
    ptr_void = &var_double;
    printf("%p    %.2lf\n", ptr_void, *(double *)ptr_void);

    char arr[] = "hello"; // thực tế là có 6 kí tự, kí tự cuối là kí tự '\0'
    ptr_void = arr;
    for(int i=0; i<(sizeof(arr)/sizeof(arr[0])); i++)
    {
        printf("%c\n",*(char*)(ptr_void+i));
    }


    void *ptr[] = {&var_int, &var_double}; // khai báo mảng con trỏ void chưa các địa chỉ của các biến
    

    return 0;
}