#include <stddef.h>

#include "queue.h"

void
initialize_queue(queue_t *queue)
{
    queue->head = NULL;
    queue->tail = NULL;
}

void
initialize_queue_item(queue_item_t *item, void *data)
{
    item->data = data;
    item->next = NULL;
}

void
enqueue(queue_t *queue, queue_item_t *item)
{
    if (queue->head == NULL) {
        queue->head = item;
    } else {
        queue->tail->next = item;
    }
    queue->tail = item;
}

queue_item_t *
dequeue(queue_t *queue)
{
    queue_item_t *item;

    item = queue->head;
    if(item != NULL) {
        queue->head = item->next;
        item->next = NULL;
    }
    if(queue->head == NULL) {
        queue->tail = NULL;
    }
    return item;
}
