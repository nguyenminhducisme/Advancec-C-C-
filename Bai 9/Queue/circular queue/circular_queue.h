/************************************************************************
 * @author: Nguyen Minh Duc
 * @date  : 22/3/3025
 * @details: Implement usual functions of circular queue data structure
 * @version: 1.0 
*************************************************************************/
/*==============================[GUARD]===================================*/
#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

/*==============================[INCLUDE FILES]===========================*/
#include<stdlib.h>

/*==============================[TYPES DEFINITIONS]=======================*/
typedef struct Queue
{
    int *item;  /*<mảng lưu trữ giá trị các phần tử>*/
    int size;   // số lượng phần tử tối đa có thể đưa vào
    int front;  // chỉ số của phần tử đầu hàng đợi
    int rear;   // chỉ số của phần tử cuối hàng đợi
}Queue;

#endif