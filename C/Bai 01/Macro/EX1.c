#include<stdio.h>

#define CREATE_FUNC(name, cmd)   \
void name(){                       \
    printf(cmd);                   \
}

CREATE_FUNC(test1, "this is test1\n");

#define CREATE_FUNC1(name2, commd)   \
void name2(){                       \
    printf(#commd);                   \
}

CREATE_FUNC1(test2, this is test2\n);


#define CREATE_VAR(name)    \
int int_##name       ;       \
char char_##name     ;     \
double heloo##name   ;

// variadic

// #define sum(a,b,c)  a+b+c // mat thoi gian

#define sum(...)     \
int arr[]={__VA_ARGS__};\
int tong=0;  \
int i=0;    \
for(size_t i=0; i<(sizeof(arr)/sizeof(arr[0]));i++){ \
    tong+=arr[i];   \
}  \
printf("Tong=%d\n",tong);

 

int main(){
    test1();
    test2();
    CREATE_VAR(hi);
    sum(1,2,3,4);
    return 0;
}