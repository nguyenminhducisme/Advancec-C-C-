#include<stdio.h>

// <return_type> (*func_pointer)(data_type1, data_type2);

void tong(int a, int b)
{
    printf("%d\n", a+b);
}

void hieu(int a, int b)
{
    printf("%d\n",a-b);
}

void tich(int a, int b)
{
    printf("%d\n",a*b);
}

void tinhtoan (void(*pheptoan)(int, int), int a, int b)
{
    pheptoan(a, b);
}


int main()
{
    int a=10, b=20;
    tong(a, b);
    hieu(a, b);

    /* Cách gọi 1: Sử dụng con trỏ hàm để gọi các phép toán */
    void(*ptr)(int, int);
    ptr=tong;
    ptr(a,b);

    ptr=tich;
    ptr(a,b);

    /* Cách 2:  */
    tinhtoan(tong,a ,b);
    tinhtoan(tich,a , b);

    /* Cách 3: Sử dụng mảng con trỏ để gọi các phép toán*/
    void (*caculate[])(int, int)={&tong, &hieu, &tich};
    for(int i=0; i<3;i++){
         caculate[i](a, b);
    }
    return 0;
    
}