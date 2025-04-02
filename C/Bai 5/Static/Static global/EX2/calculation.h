#ifndef CALCULATION_H
#define CALCULATION_H

typedef struct 
{
    double x1;
    double x2;
}Result;

static Result tinhtoan(Result(*ptr_func)(int, int, int), int a, int b, int c);
static double calculate_Delta(int a, int b, int c);
static Result calculate_variable(int a, int b, int c);
Result solve_E2(int a, int b, int c);

#endif