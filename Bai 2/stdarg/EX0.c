#include<stdio.h>
#include<stdarg.h>

void test(int count,...){ // count: so luong doi so minh truyen vao

    va_list args;
    // typedef char* va_list
    // char *args ="int count, 1, 2, 6"
    
    va_start(args, count);

    // va_arg(args, int); Dung de truy cap vao cac doi so

    printf("value 1: %d\n",va_arg(args, int));
    printf("value 2: %d\n",va_arg(args, int));
    printf("value 3: %d\n",va_arg(args, int));
    printf("value 4: %f\n",va_arg(args, double));
    printf("%s\n",va_arg(args, char*));

    va_end(args);

}

int main(){
    test(5,1,2,6,3.5,"hello"); // count == 5
    return 0;
}

 