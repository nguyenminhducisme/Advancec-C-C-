#include "Comparison.h"




int stringCompare(const char *str1, const char *str2) {
   while (*str1 && (*str1 == *str2)) {
       str1++; 
       str2++; 
   }
   return *(const unsigned char*)str1 - *(const unsigned char*)str2; 
}

int compare_by_name(const void *str1, const void *str2)
{
    Info *user1 = (Info *)str1;
    Info *user2 = (Info *)str2;

    return stringCompare(user1->name, user2->name);
}

int compare_by_phone(const void *str1, const void *str2)
{
    Info *user1 = (Info *)str1;
    Info *user2 = (Info *)str2;

    return stringCompare(user1->phone, user2->phone);
}