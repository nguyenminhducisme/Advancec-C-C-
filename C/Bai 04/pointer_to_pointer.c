#include <stdio.h>

int main() {
    int value = 42;
    int *ptr1 = &value;  // Con trỏ thường trỏ đến một biến

    int **ptr2 = &ptr1;  // Con trỏ đến con trỏ

    /*
        **ptr2 = &ptr1
        ptr2 = &ptr1;
        *ptr2 = ptr1 = &value;
        **ptr2 = *ptr1 = value
    */

    printf("address of value: %p\n", &value);
    printf("value of ptr1: %p\n", ptr1);

    printf("address of ptr1: %p\n", &ptr1);

    printf("deference ptr1: %d\n", *ptr1);

    printf("value of ptr2: %p\n", ptr2);

    printf("dereference ptr2 first time: %p\n", *ptr2);

    printf("dereference ptr2 second time: %d\n", **ptr2);
/*
Output: 
    address of value: 000000000061FE44
    value of ptr1: 000000000061FE44
    address of ptr1: 000000000061FE38
    deference ptr1: 42
    value of ptr2: 000000000061FE38
    dereference ptr2 first time: 000000000061FE44
    dereference ptr2 second time: 42
*/
    return 0;
}
