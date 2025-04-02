#include "queue_linear.h"
#include<stdio.h>

int main()
{
    Queue queue;
    init_queue(&queue, 5);
    printf("%d %d\n", queue.front, queue.rear);
    printf("%d\n", queue.size);
    enqueue_elements(&queue, 5);
    enqueue_elements(&queue, 5);
    enqueue_elements(&queue, 5);
    enqueue_elements(&queue, 5);
    enqueue_elements(&queue, 5);
    enqueue_elements(&queue, 5);
    dequeue_elements(&queue);
    display_queue(queue);
}

