#include<stdio.h>

void test_func( int a, int b)
{
    int *x = &a;
    int *y = &b;
    printf("%p %p\n", x, y);
}

void test1(int a, int b, int c, int d)
{
    int *x = &a;
    int *y = &b;
    int *z = &c;
    int *t = &d;
    printf("%p %p %p %p\n\n", x, y, z, t);
}

int main(){
    test_func(3,5);
    test1(10,15, 20, 25);
    return 0;
}