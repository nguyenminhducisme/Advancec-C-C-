#include<stdio.h>
#include<math.h>
#include"calculation.h"



static double calculate_Delta(int a, int b, int c)
{
    return b*b - 4*a*c;
}

static Result tinhtoan(Result(*ptr_func)(int, int, int), int a, int b, int c)
{
    return ptr_func(a, b, c);
}

static Result calculate_variable(int a, int b, int c)
{
    Result nghiem;
    double delta = calculate_Delta(a,b,c);
    if(delta>0)
    {
        nghiem.x1 = (-b + sqrt(delta))/(2*a);
        nghiem.x2 = (-b - sqrt(delta))/(2*a);
    }
    else if(delta == 0)
    {
        nghiem.x1 = nghiem.x2 = (double)(-b)/(2*a);
    }
    else
    {
        nghiem.x1 = nghiem.x2 = NAN;
    }
    return nghiem;
}



Result solve_E2(int a, int b, int c)
{
   
    
printf("x1 = %0.3f, x2 = %0.3f\n", tinhtoan(calculate_variable,a,b,c).x1, tinhtoan(calculate_variable,a,b,c).x2);
}

