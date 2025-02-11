#include<stdio.h>
#include "test.h"

int SIZE2= 20;
#define SIZE  20
#undef SIZE 
#define SIZE 30

#ifdef SIZE
int arr[SIZE]={1,2};
#endif

int arr[SIZE];
int main(){
    int arr2[SIZE2];
    display();
    
    return 0;
}