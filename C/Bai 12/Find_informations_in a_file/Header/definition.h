#ifndef definition_h
#define definition_h

#define FAIL_CREATED_FILE    false
#define SUCCESS_CREATED_FILE true
#define FILE_PATH "database/data.csv"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node /* Chương trình biên dịch từ trên xuống dưới nên ta phải định nghĩa struct là Node ở ngay đầu*/
{
    char* name;
    int age;
    char* phone;
    char* address;
    struct Node *next; // Lí do phải để kiểu con trỏ là struct Node, vì con trỏ next này chứa 2 thành phần là giá trị và một con trỏ
}Node;

typedef struct{
    char* name;
    int age;
    char* phone;
    char* address;
}Info;


 /**
  * @struct  CenterPoint
  * @brief   Cấu trúc của một node trong cây nhị phân tìm kiếm.
  */
 typedef struct CenterPoint
 {
     char* name;
     int age;
     char* address;   
     char* phone;  /**< Giá trị của node */
     struct CenterPoint *left;   /**< Con trỏ đến node con trái */
     struct CenterPoint *right;  /**< Con trỏ đến node con phải */
 }CenterPoint;

#endif