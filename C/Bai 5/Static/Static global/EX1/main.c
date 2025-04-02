#include<stdio.h>
#include "File1.h"

extern int a;
extern void display();
extern void test();

int main()
{
    printf("%d\n", a);
    display();
    test();
}