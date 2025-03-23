/************************************************************************
 * @file  : circular_queue.h
 * @author:
 * @date  : 22/3/2025
 * @details: Implement usual functions of circular queue data structure
 * @version: 1.0
 ************************************************************************/
/*==============================[GUARD]===================================*/
#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

/*==============================[INCLUDE FILES]===========================*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*==============================[TYPES DEFINITIONS]=======================*/
#define QUEUE_EMPTY -1
typedef struct
{
    int *items; // mảng lưu trữ giá trị các phần tử
    int size;   // kích thước của hàng đợi
    int front;  // chỉ số phần tử đầu hàng đợi
    int rear;   // chỉ số phần tử cuối hàng đợi
} Queue;

/*==============================[FUNCTION DECLARATIONS]===================*/

/**
 * @brief Initialize queue
 * @param queue: con trỏ thao tác trên queue
 * @param size : số lượng thành phần muốn khởi tạo
 */
void queue_Init(Queue *queue, int size);

/**
 * @brief Kiểm tra hàng đợi rỗng
 * @param queue: biến thao tác trên queue
 * @return int
 */
int queue_IsEmpty(Queue queue);

/**
 * @brief Kiểm tra hàng đợi đầy
 * @param queue: biến thao tác trên queue
 * @return int
 */
int queue_IsFull(Queue queue);

/**
 * @brief Thêm phần tử vào cuối hàng đợi
 * @param queue: con trỏ thao tác trên queue
 * @param data : giá trị cần thêm vào
 */
void enqueue(Queue *queue, int data);

/**
 * @brief Xóa phần tử từ đầu hàng đợi
 * @param queue: con trỏ thao tác trên queue
 * @return int: giá trị của phần tử bị xóa
 */
int dequeue(Queue *queue);

/**
 * @brief Lấy giá trị của phần tử đứng đầu hàng đợi (front)
 * @param queue: biến thao tác trên queue
 * @return int: giá trị của phần tử đầu hàng đợi
 */
int front(Queue queue);

/**
 * @brief Lấy giá trị của phần tử đứng cuối hàng đợi (rear)
 * @param queue: biến thao tác trên queue
 * @return int: giá trị của phần tử cuối hàng đợi
 */
int rear(Queue queue);

/**
 * @brief Hiển thị các phần tử trong hàng đợi
 * @param queue: biến thao tác trên queue
 */
void display(Queue queue);

#endif // CIRCULAR_QUEUE_H