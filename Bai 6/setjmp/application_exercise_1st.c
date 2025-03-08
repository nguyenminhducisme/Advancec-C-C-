#include<stdio.h>
#include<setjmp.h>
#include<string.h>

jmp_buf buf;

char error_code[50];


#define TRY   if((exception = setjmp(buf)) ==0)
#define CATCH(x) else if(exception == x)
#define THROW(x, str) \
if(x==1 || x==2)        \
strcpy( error_code, #str); \
longjmp(buf,x);   


typedef enum{
    NO_ERROR,
    NO_EXIST,
    DIVIDE_BYZERO
}ERROR_CODES;

int exception;

double divide(int a, int b)
{
    if(a==0 && b==0)
    {
        THROW(NO_EXIST, khong ton tai);
    }
    else if(b == 0 && a!=0)
    {
        THROW(DIVIDE_BYZERO, chia cho 0);
    }
    return (double)a/b;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    TRY
    {
       printf("Ket qua: %.3lf\n", divide(a,b));
    }
    CATCH(DIVIDE_BYZERO)
    {
       printf("%s\n", error_code);
    }
    CATCH(NO_EXIST)
    {
       printf("%s\n", error_code);
    }
    return 0;
}