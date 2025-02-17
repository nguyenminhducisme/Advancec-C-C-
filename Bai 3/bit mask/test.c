#include<stdio.h>
#include<stdint.h>

int main(){
    uint8_t bit = 0b00100101;


    printf("%d\n",bit & (~(1<<5))); /* Tat bit*/ 
    printf("%d\n",bit);

    // Bat bit
    printf("%d",(bit | (1<<1)));

    // Dao bit
    

    return 0;
}


//      00100101 
// 1<<1 00000010  
//      00100111 00100111 &(11111101)=