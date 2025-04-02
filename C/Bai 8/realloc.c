#include<stdio.h>
#include<stdlib.h> // Thư viện để dùng các hàm cấp phát động
#include<stdint.h>

int a = 5; // data

int *ptr = &a; // bss
    
int main()
{
    int size = 5; // 5*4 = 20 bytes
 

    uint16_t *ptr = (uint16_t *) malloc(size * sizeof(uint16_t)); // con trỏ trỏ tới phần tử đầu tiên , cấp phát 10 bytes = 5*2

    if(ptr == NULL);

    ptr[0] = 5;

    for(int i = 0; i<size; i++)
    {
        printf("dia chi: %d: %p -Value: %d\n", i, ptr+i, *(ptr+i));
    }
    printf("\n");

    size = 10;
  ptr = (uint16_t *) realloc(ptr, size * sizeof(uint16_t)); // quản lí vùng nhớ mới

    
    for(int i = 0; i<size; i++)
    {
        printf("dia chi: %d: %p -Value: %d\n", i, ptr+i, *(ptr+i));
    }

    free(ptr); // Nếu không thu hồi vùng nhớ sẽ xảy ra memory leak
    ptr = NULL;
    return 0;
}