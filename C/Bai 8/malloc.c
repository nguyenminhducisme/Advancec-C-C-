#include<stdio.h>
#include<stdlib.h> // Thư viện để dùng các hàm cấp phát động
#include<stdint.h>

    
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
  free(ptr);

}