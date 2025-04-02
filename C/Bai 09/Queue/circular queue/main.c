#include"circular_queue.h"

int main(int argc, char const *argv[])
{
    Queue queue;
   
    queue_Init(&queue, 5);

    enqueue(&queue, 10);
    enqueue(&queue, 15);
    enqueue(&queue, 20);
    enqueue(&queue, 25);
    enqueue(&queue, 30);

    display(queue);

    printf("Front element: %d\n", front(queue));
    printf("Rear element: %d\n", rear(queue));

    printf("Dequeued %d\n", dequeue(&queue));
    // printf("Dequeued %d\n", dequeue(&queue));
    // printf("Dequeued %d\n", dequeue(&queue));
    // printf("Dequeued %d\n", dequeue(&queue));

    display(queue);

    enqueue(&queue, 50);
    display(queue);

    printf("Front element: %d\n", front(queue));
    printf("Rear element: %d\n", rear(queue));

    return 0;
}

