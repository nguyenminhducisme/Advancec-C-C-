#include <stdio.h>
#include <setjmp.h>


jmp_buf buf;

int exception_code;

typedef enum
{
    NO_ERROR,
    NO_EXIT,
    DIVIDE_BY_0 
} ErrorCodes;

#define TRY if ((exception_code = setjmp(buf)) == 0)
#define CATCH(x) else if (exception_code == x)
#define THROW(x) longjmp(buf, x)

double divide(int a, int b)
{
    if (a == 0 && b == 0)
    {
        THROW(NO_EXIT);
    }
    else if (b == 0)
    {
        THROW(DIVIDE_BY_0);
    }

    return (double)a/b;
}

int main(int argc, char const *argv[])
{
    exception_code = NO_ERROR;

    TRY
    {
        printf("Ket qua: %0.3f\n", divide(4,0));
    }
    CATCH(NO_EXIT)
    {
        printf("ERROR! Khong ton tai\n");
    }
    CATCH(DIVIDE_BY_0)
    {
        printf("ERROR! Chia cho 0\n");
    }

    // thêm code ở đây
    printf("Hello world\n");
    return 0;
}


