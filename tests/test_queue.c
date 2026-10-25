#include <stdio.h>

#include "queue.h"

#define QUEUE_SIZE 4


void
dequeue_and_print(queue_t *queue)
{
    queue_item_t *current;
    while((current = dequeue(queue)) != NULL) {
        printf("%d\n",  *((int *)current->data));
    }
}

int
main(void)
{
    queue_t queue;
    queue_item_t items[QUEUE_SIZE];
    int data[QUEUE_SIZE];

    initialize_queue(&queue);
    for(int i = 0; i < QUEUE_SIZE; i++) {
        data[i] = QUEUE_SIZE - i;
        initialize_queue_item(&items[i], (void *)&data[i]);
        enqueue(&queue, &items[i]);
    }
    dequeue_and_print(&queue);
}
