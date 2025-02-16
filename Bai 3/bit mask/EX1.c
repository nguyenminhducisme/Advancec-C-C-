#include<stdio.h>
#include<stdint.h>
/*
  int8_t, uint8_t   : 1 byte = 8 bit 
  int16_t, uint16_t : 2 byte = 16 bit
*/

#define gender 1<<0   // bit 0: gioi tinh nu(0) nam(1)  0b00000001 << 0
#define shirt 1<<1    // bit 1:                         0b00000010
#define hat   1<<2    //                                0b00000100
#define shoes 1<<3    //                                0b00001000
#define feature1 1<<4 //                                0b00010000
#define feature2 1<<5 //                                0b00100000
#define feature3 1<<6 //                                0b01000000
#define feature4 1<<7 //                                0b10000000

//enable bit 0 -> 1
void enable_Feature(uint8_t *options, uint8_t feature ){
    *options |= feature;
}
void disable_Feature(uint8_t *options, uint8_t feature ){
  *options = *options &(~ feature);
}

int8_t is_Feature_enabled(uint8_t options, uint8_t feature){
     return ((options & feature)!=0);
}
void listed_Selected_Features(uint8_t options){
  const char *featureName[]=
  {
    "Gender",
    "Shirt",
    "Hat",
    "Shoes",
    "Feature 1",
    "Feature 2",
    "Feature 3",
    "Feature 4"
  } ;
  for(int i=0; i<8; i++)
  {
    if((options >> i) & 1) // kiem tra bit thu i la 0 hay 1
    {
      printf("%s\n",featureName[i]);
    }
  }
}

int main(){
   
    uint8_t options = 0; // 0b00010000
    // Add features
    enable_Feature(&options, shoes);

    // remove features
   
    
    // check
    printf("%d\n",is_Feature_enabled(options, shoes));

    listed_Selected_Features(options);

    return 0;
}