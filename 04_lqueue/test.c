#include "lqueue.h"
#include "err.h"
#include <stdio.h>

int main() {
    LQueue* queue = CreateQueue();

    Enqueue(10, queue);
    Enqueue(20, queue);
    Enqueue(30, queue);

    printf("Queue contents: ");
    PrintQueue(queue);

    printf("Front element: %d\n", Front(queue));

    Dequeue(queue);
    printf("Queue contents after Dequeue: ");
    PrintQueue(queue);

    printf("Front element and removing it: %d\n", FrontAndDequeue(queue));
    PrintQueue(queue);

    RemoveQueue(queue);
    printf("Queue contents after removing: ");
    PrintQueue(queue);

    return 0;
}