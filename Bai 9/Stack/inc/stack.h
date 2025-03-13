/**********************************************************
* @file     : stack.h
* @brief    : Implement functions to apply stack data structues
* @details  : Include functions that generate basic actions of stack like push, pop...
* @date     : 10-3-2025
* @author   : Nguyen Minh Duc
 * @version : 1.0
***********************************************************/



#ifndef STACK_H
#define STACK_H
/*=======================[INCLUDE FILES]========================*/
#include<stdio.h>
#include<stdint.h>
#include <stdbool.h>
#include <stdlib.h>

/*=======================[MACRO DEFINITIONS]====================*/
#define EMPTY_STACK -1

/*=======================[TYPES DEFINITIONS]====================*/
typedef struct 
{
    int *item; // mảng lưu giá trị các phần tử
    int size;  // số lượng phần tử tối đa của stack
    int top; // chỉ số lấy giá trị ở đỉnh stack
}Stack;


/**************************************************************************
 * @brief   Khởi tạo stack
 * @param   stack:  con trỏ thao tác vớ struct
 * @param   newSize: số lượng phần tử của stack
 * @return  void
 **************************************************************************/
void stack_init(Stack *stack, int newSize);

/**************************************************************************
 * @brief  Kiểm tra stack có trống hay chưa
 * @param   stack: biến thao tác trên struct
 * @return  void
 **************************************************************************/
bool is_stack_empty(Stack stack);

/**************************************************************************
 * @brief  Kiểm tra stack có trống hay chưa
 * @param   stack: biến thao tác trên struct
 * @return  void
 **************************************************************************/
bool is_stack_full(Stack stack);

/**************************************************************************
 * @brief  đẩy thêm phần tử vào đỉnh stack
 * @param   stack: biến con trỏ thao tác trên struct
 * @param   new_element: phần tử mới muốn thêm vào stack
 * @return  void
 **************************************************************************/
void push_elements(Stack *stack, int new_element);

/**************************************************************************
 * @brief  đẩy thêm phần tử vào đỉnh stack
 * @param   stack: biến con trỏ thao tác trên struct
 * @param   new_element: phần tử mới muốn thêm vào stack
 * @return  void
 **************************************************************************/
void pop_elements(Stack *stack);

/**************************************************************************
 * @brief  lấy giá trị ở đỉnh stack
 * @param   stack: biến thao tác trên struct
 * @return  void
 **************************************************************************/
void peek_element(Stack stack);

/**************************************************************************
 * @brief  in ra các phần tử trong stack
 * @param  stack: biến thao tác trên struct
 * @return  void
 **************************************************************************/
void display_stack(Stack stack);

/**************************************************************************
 * @brief   giải phóng bộ nhớ mảng lưu giá trị các phần tử
 * @param   stack: biến con trỏ thao tác trên struct
 * @return  void
 **************************************************************************/
void stack_free(Stack *stack);



#endif // STACK_H