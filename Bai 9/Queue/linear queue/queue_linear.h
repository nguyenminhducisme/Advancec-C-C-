/**********************************************************
* @file     queue_linear.h
* @brief    Implement functions to apply stacke data structues
* @details  Include functions that generate basic actions of queue like enqueue, dequeue...
* @date     10-3-2025
* @author   Nguyen Minh Duc
 
***********************************************************/
#ifndef QUEUE_LINEAR_H
#define QUEUE_LINEAR_H
/*=======================[INCLUDE FILES]==================*/
#include<stdlib.h>
#include<stdbool.h>
#include <stdio.h>

/*======================[DEFINITIONS]======================*/
#define QUEUE_EMPTY true
#define QUEUE_FULL  true

/*=======================[TYPES DEFINITION]===============*/
typedef struct
{
    int *item;  // mảng lưu trữ giá trị các phần tử
    int size;   // số lượng phần tử tối đa có thể đưa vào
    int front;  // chỉ số của phần tử đầu hàng đợi
    int rear;   // chỉ số của phần tử cuối hàng đợi
} Queue;

/*********************************************************** 
 * @brief Khởi tạo queue
 * @param *queue: con trỏ thao tác trên queue
 *         newSize: số lượng phần tử trên queue
 * @return void
***********************************************************/
void init_queue(Queue *queue, int newSize);

bool is_queue_full(Queue queue);

bool is_queue_empty(Queue queue);

void enqueue_elements(Queue *queue, int new_element);
void dequeue_elements(Queue *queue);
void display_queue(Queue queue);
#endif // QUEUE_LINEAR_H