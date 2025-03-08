#include<stdio.h>
#include<stdint.h>

// typedef struct Data2 {
//     uint8_t a;   // 0x01 0x02 0x03 0x04: a dùng 1 ô 0x01
//     uint16_t b;  // 0x01 0x02 0x03 0x04: b dùng 2 ô 0x01 0x02
//     uint32_t c; // Cấp vùng nhớ cho kiểu dữ liệu lớn nhất, ở đây là 4 bytes, c dùng 4 ô
// }Data2; 


typedef union Data 
{
    uint8_t a;
    uint16_t b;
    uint32_t c;
}Data;


// void display(uint8_t arr[], int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         printf("arr[%d]: %d\n",i, arr[i]);
//     }
//     printf("----------\n");
// }


// void display_address(uint8_t arr[], int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         printf("address of arr[%d]: %p\n",i, &arr[i]);
//     }
//     printf("----------\n");
// }

int main()
{
    // data.a = 5;
    // data.b = 6;
    Data data;
    data.c = 4294967290;  // 11111111111111111111111111111010
    

    printf("a = %d\n", data.a);
    printf("b = %d\n", data.b);
    printf("c = %u\n", data.c);




    // printf("Size of Data: %ld\n", sizeof(Data));
    // Data data_test;

    // data_test.arr1[0] = 11;
    // data_test.arr1[1] = 12;
    // data_test.arr1[2] = 13;
    // data_test.arr1[3] = 14;
    // data_test.arr1[4] = 15;
    // display(data_test.arr1,5);

    // data_test.arr2[0] = 21;
    // data_test.arr2[1] = 22;
    // data_test.arr2[2] = 23;
    // display(data_test.arr2,3);
    // display(data_test.arr1,5);

    // data_test.arr3[0] = 31;
    // data_test.arr3[1] = 32;
    // data_test.arr3[2] = 33;
    // data_test.arr3[3] = 34;
    // data_test.arr3[4] = 35;
    // data_test.arr3[5] = 36;
    // display(data_test.arr3,6);

    // display_address(data_test.arr1,5);
    // display_address(data_test.arr2,3);
    // display_address(data_test.arr3,6);

    // printf("%d", sizeof(Data2));
}
