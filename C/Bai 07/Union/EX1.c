#include<stdio.h>
#include<stdint.h>

typedef union 
{
    uint8_t a;
    uint16_t b; 
    uint32_t c;
}Data;

int main()
{
    printf("Size of union data: %d\n", sizeof(Data));
    Data data;
   data.c = 4294967290; // 11111111111111111111111111111010

   // 0x01                                             0x02
   // 11111010                                       11111111 
    printf("a = %d\n", data.a); // 0b11111010  = 250
    printf("b = %d\n", data.b); //0b1111101011111111 = 65530
    printf("c = %u\n", data.c);

}
