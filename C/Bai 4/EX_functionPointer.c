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

    /* Cách gọi 1: Sử dụng con trỏ hàm để gọi các phép toán */
    void(*ptr)(int, int);
    // ptr=tong;
    // ptr(10, 20);

    // ptr=tich;
    // ptr(10, 20);

    /* Cách 2:  */
    // tinhtoan(tong,10, 20);
    // tinhtoan(tich,10, 20);

    /* Cách 3: Sử dụng mảng con trỏ để gọi các phép toán*/
    void (*caculate[])(int, int)={&tong, &hieu, &tich};
    for(int i=0; i<3;i++){
         caculate[i](10, 20);
    }
    return 0;
    
}