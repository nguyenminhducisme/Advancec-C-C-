#include<stdio.h>
#include<setjmp.h>

jmp_buf buf;

#define TRY   if((exception = setjmp(buf)) ==0)
#define CATCH(x) else if(exception == x)
#define THROW(x) longjmp(buf,x)

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
        THROW(NO_EXIST);
    }
    else if(b == 0 && a!=0)
    {
        THROW(DIVIDE_BYZERO);
    }
    return (double)a/b;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    TRY
    {
       printf("Ket qua: %lf\n", divide(a, b));
    }
    CATCH(DIVIDE_BYZERO)
    {
       printf("Chia cho 0\n");
    }
    CATCH(NO_EXIST)
    {
        printf("Khong ton tai\n");
    }
    return 0;
}