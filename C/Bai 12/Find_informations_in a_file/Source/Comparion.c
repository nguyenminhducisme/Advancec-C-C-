#include "Comparison.h"



int stringCompare(const char *str1, const char *str2) {
   while (*str1 && (*str1 == *str2)) {
       str1++; 
       str2++; 
   }
   return *(const unsigned char*)str1 - *(const unsigned char*)str2; 
}

int compare_by_name_or_phone(const char *str1, const char *str2)
{
    return stringCompare(str1, str2);
}