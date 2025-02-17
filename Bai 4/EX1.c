#include<stdio.h>
#include<stdint.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){
    // int a=10, b=20;
    // swap(&a, &b);
    // printf("%d %d",a,b);

    // int arr[]={1, 2, 3}; // 0x01 0x02 0x03 0x04/ 0x05 ... 0x08/ ..
    // int *ptr = arr;
    // ptr; // truy cập tới vùng địa chỉ thứ 0
    // ptr + 1; // vùng địa chỉ thứ 1

    // for(int i=0;i<3;i++)
    // {
    //     printf("Phan tu thu %d - Dia chi %p Gia tri: %d \n",i, ptr+i, *(ptr+i));
    // }
    int x=5;
    int *ptr=&x;
    printf("%d\n",ptr);
    printf("%d\n",*ptr);


    return 0;
}