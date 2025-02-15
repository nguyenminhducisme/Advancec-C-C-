#include<stdio.h>
#include<assert.h>
#include<locale.h>
#include<windows.h>

// or we can define assert function
#define LOG(condition, notification) assert(condition && notification);

int main()
{
    SetConsoleOutputCP(65001);
    int x=10;
    LOG(x==5, "x phải bằng 5");
    printf("%d",x);
    return 0;
}