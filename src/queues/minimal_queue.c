#include <stddef.h>

#include "ccaclib/common/slink_item.h"
#include "ccaclib/queues/minimal_queue.h"

void
initialize_miniqueue(miniqueue_t *queue)
{
    queue->head = NULL;
    queue->tail = NULL;
}

void
minienqueue(miniqueue_t *queue, slink_item_t *item)
{
    if (queue->head == NULL) {
        queue->head = item;
    } else {
        queue->tail->next = item;
    }
    queue->tail = item;
}

slink_item_t *
minidequeue(miniqueue_t *queue)
{
    slink_item_t *item;

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
