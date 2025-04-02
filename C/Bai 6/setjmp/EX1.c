#include<stdio.h>
#include<setjmp.h>

jmp_buf buf;

int exception;

int main()
{
    exception = setjmp(buf);

    if(exception == 0)
    {
        printf("Exception = 0\n");
    }
    else if(exception==1)
    {
        printf("Exception = 1\n");
    }
    else
    {
        printf("Exception != 0,1\n");
    }
    longjmp(buf,2);
    return 0;
}