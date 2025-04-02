#include<stdio.h>
#include<stdint.h>

#define LED1 1<<0 // 00000001
#define LED2 1<<1 // 00000010
#define LED3 1<<2 // 00000100
#define LED4 1<<3 // 00001000

void enableLED(uint8_t *GPIO, uint8_t led)
{
    *GPIO = *GPIO | led ;  // 00000000 
}

void disableLed(uint8_t *GPIO, uint8_t led) 
{
    *GPIO = *GPIO &(~led);
}

void displayActiveLed(uint8_t GPIO)
{
     if(GPIO & LED1)
     printf("LED1 is on        ");
     if(GPIO & LED2)
     printf("LED2 is on        ");
     if(GPIO & LED3)
     printf("LED3 is on        ");
     if(GPIO & LED4)
     printf("LED4 is on        ");
}

int main()
{  
    uint8_t GPIO = 0;
    
    enableLED(&GPIO, LED1 | LED2 ); // Turn on led1 and led2
    disableLed(&GPIO, LED1);
    displayActiveLed(GPIO);

    return 0;
}