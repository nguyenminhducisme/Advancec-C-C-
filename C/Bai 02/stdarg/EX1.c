#include<stdio.h>
#include<stdarg.h>

void sum(int amount,...){
    va_list args;
    va_start(args,amount);
    int Sum=0;
    for(int i=0;i<amount;i++){
        Sum+=va_arg(args,int);
    }
    printf("%d",Sum);

    va_end(args);

}

int main(){
    sum(5,1,2,3,4,6);
    return 0;
}