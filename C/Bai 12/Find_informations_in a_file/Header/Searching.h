/********************************************************************************
 * @file     searching.h 
 * @brief    Dùng để triển khai các hàm tìm kiếm thông tin cần tìm
 * @details  Dùng cây nhị phân để tìm kiếm thông tin đã được sắp xếp
 * @version  1.0
 * @date     3/5/2025
 * @author   Nguyen Minh Duc
********************************************************************************/

#ifndef SEARCHING_H
#define SEARCHING_H
/*========================================[FILES INCLUDED]========================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "file_handler.h"
#include "Comparison.h"
/**
  * @struct  Node
  * @brief   Cấu trúc của một node trong danh sách liên kết đơn.
  */
 typedef struct Node
 {
    Info User_Information; /**< Con trỏ Info để lưu trữ thông tin users */
    struct Node *next; /**< Con trỏ đến node tiếp theo */
 } Node;
 

 /* ========================================[ FUNCTION INPLEMENTATION ]======================================*/
 
 /**
  * @brief  Thêm thông tin vào danh sách đồng thời sắp xếp nó
  * @param  head   Con trỏ đến con trỏ head của danh sách liên kết
  * @param  info   Con trỏ đến thông tin người dùng có sẵn trong database
  * @return void
  */
 void add_Information(Node **head, Info info, int (*compare_functions_handler)(const char *, const char *));

  /**
  * @struct  CenterPoint
  * @brief   Cấu trúc của một node trong cây nhị phân tìm kiếm.
  */
 typedef struct CenterPoint
 {
    Info *User_Information; /**< Con trỏ Info để lưu trữ thông tin users */
    struct CenterPoint *left;   /**< Con trỏ đến node con trái */
    struct CenterPoint *right;  /**< Con trỏ đến node con phải */
 } CenterPoint;

  /**
  * @brief   Xây dựng cây nhị phân từ danh sách liên kết.
  * @details Tìm điểm giữa danh sách và chia danh sách thành cây nhị phân tìm kiếm.
  * @param   head   Con trỏ đến danh sách liên kết.
  * @param   start  Vị trí bắt đầu của danh sách.
  * @param   end    Vị trí kết thúc của danh sách.
  * @return  CenterPoint*   Gốc của cây nhị phân tìm kiếm.
  */
 CenterPoint *buildTree(Node *head, int start, int end);

 /**
  * @brief   Chuyển danh sách liên kết thành cây nhị phân tìm kiếm (BST).
  * @details Tính độ dài danh sách liên kết và gọi `buildTree()` để xây dựng BST.
  * @param   head  Con trỏ đến danh sách liên kết.
  * @return  CenterPoint*  Gốc của cây nhị phân tìm kiếm.
  */
 CenterPoint *centerPoint(Node *head);
  /**
  * @brief   Thực hiện tìm kiếm nhị phân trên cây BST.
  * @details Duyệt cây nhị phân để tìm kiếm giá trị cần tìm.
  * @param   root   Gốc của cây nhị phân.
  * @param   info  Giá trị cần tìm.
  * @return  CenterPoint*   Trả về con trỏ đến node tìm thấy, NULL nếu không tìm thấy.
  */
  CenterPoint *binarySearch(CenterPoint *root, Info info);

  /**
  * @brief   In danh sách liên kết.
  * @details Duyệt danh sách liên kết và in ra từng phần tử.
  * @param   new_info  Con trỏ đến danh sách liên kết.
  * @return void
  */
static void print_list(Node *new_info);
// void Execute_memory(Node *new_info);
static void free_list(Node *new_info);
#endif // SEARCHING_H