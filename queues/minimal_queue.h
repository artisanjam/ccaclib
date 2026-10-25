#ifndef CCAC_MINIMAL_QUEUE_H
#define CCAC_MINIMAL_QUEUE_H

#include "slink_item.h"

typedef struct miniqueue {
   slink_item_t *head;
   slink_item_t *tail;
} miniqueue_t;

void
initialize_miniqueue(miniqueue_t *queue);

void
minienqueue(miniqueue_t *queue, slink_item_t *item);

slink_item_t *
minidequeue(miniqueue_t *queue);
#endif
