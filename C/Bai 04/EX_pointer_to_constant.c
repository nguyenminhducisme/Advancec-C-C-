#include<stdio.h>
#include<string.h>


int val1 = 10;
int val2 = 3;
const int *ptr_const = &val1; // con trỏ đến hằng số trỏ đến giá trị của value1

const char *str1 = "hello";
const char *str2 = "world";

int compare(const char *str1, const char *str2)
{
    // put your code here
    // str1[0] = 'a'; error
    return strlen(str1) - strlen(str2);
}

int main()
{
    printf("%p\n", ptr_const);
    printf("%d\n", *ptr_const);

    // *ptr_const = 100;
    val1 = 100;
    printf("%d\n", *ptr_const); 
    /* if we change to *ptr_const = 100, this is not gonna work because we can not change the value of the address which pointer
    points at, we can just change the value of the original variable which is pointed at. 
    (error: assignment of read-only location '*ptr_const')
    */
   ptr_const = &val2;
   printf("%p\n", ptr_const);
    return 0;
    
}