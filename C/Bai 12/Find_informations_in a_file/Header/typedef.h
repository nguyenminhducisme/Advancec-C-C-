#ifndef TYPE_DEF_H
#define TYPE_DEF_H



#include <stdio.h>


typedef struct Info
{
    char *name;
    int age;
    char *phone;
    char *address;
}Info;

/**
  * @struct  Node
  * @brief   Cấu trúc của một node trong danh sách liên kết đơn.
  */
 typedef struct Node
 {
    Info User_Information; /**< Con trỏ Info để lưu trữ thông tin users */
    struct Node *next; /**< Con trỏ đến node tiếp theo */
 } Node;
 

#endif // TYPE_DEF_H