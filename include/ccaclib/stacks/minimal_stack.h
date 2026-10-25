#ifndef CCAC_MINIMAL_STACK_H
#define CCAC_MINIMAL_STACK_H

#include "ccaclib/common/slink_item.h"

typedef struct ministack {
    slink_item_t *top;
} ministack_t;

void
initialize_ministack(ministack_t *stack);

void
minipush(ministack_t *stack, slink_item_t *item);

slink_item_t *
minipop(ministack_t *stack);
#endif
