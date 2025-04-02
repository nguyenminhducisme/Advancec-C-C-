#include<stdio.h>
#include<stdarg.h>

#define tong(...) sum(__VA_ARGS__,'a')

int sum(int count,...){
    va_list args;
    va_list args1;
    va_start(args, count);
    va_copy(args1, args); // copy all the data of args into args1
    int result = count;
    while((va_arg(args1,char*))!=(char*)'a'){
        result+= va_arg(args,int);
    } 
    va_end(args);
    return result;
}
int main(){
    printf("%d",tong(3,1,2,3,0,5,7));
    return 0;
}