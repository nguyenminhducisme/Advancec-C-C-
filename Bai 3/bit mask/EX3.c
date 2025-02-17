#include<stdio.h>
#include<stdint.h>

// Define color of the car
#define BLUE  1<<0
#define BLACK 1<<1
#define RED   1<<2

// Define horse power of the car
#define ENGINE_300_HP 1<<3
#define ENGINE_400_HP 1<<4

// Define brand of the car
#define VINFAST 1<<5
#define FORD    1<<6
#define TOYOTA  1<<7
#define HONDA   1<<8


typedef struct ADDITIONAL_CAR_OPTIONS
{
  uint8_t Wings   : 1; // bit-field: Quy định cụ thể số lượng bit mình sẽ sử dụng(chỉ dùng trong struct)
  uint8_t BiTurbo : 2
}Car_Options;


void choosingColor(uint8_t *options ){
    
}