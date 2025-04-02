#include "queue_linear.h"


void init_queue(Queue *queue, int newSize)
{
    queue->size = newSize;
    queue->item = (int *)malloc(sizeof(int) * newSize);
    queue->front = queue->rear = -1;
}

bool is_queue_full(Queue queue)
{
    return (queue.rear == queue.size - 1);;
}

bool is_queue_empty(Queue queue)
{
    return (queue.front == -1 || queue.front >queue.rear);
}

void enqueue_elements(Queue *queue, int new_element)
{
    if(is_queue_full(*queue))
    {
        printf("Can not enqueue more elements into queue\n");
        return;
    }
    if (queue->front == -1) queue->front = queue->rear = 0;
    else queue->rear++;
    queue->item[queue->rear] = new_element;

}

void dequeue_elements(Queue *queue)
{
    if(is_queue_empty(*queue))
    {
        printf("Queue is empty\n");
        return;
    }
    queue->item[queue->front--] = 0;
}

void display_queue(Queue queue)
{
    for(int i = queue.front; i <= queue.rear; i++)
    {
        printf("%d ",queue.item[i]);
    }
}