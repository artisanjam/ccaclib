#include <assert.h>
#include <stddef.h>

#include "ccaclib/common/slink_item.h"
#include "ccaclib/stacks/minimal_stack.h"

void
initialize_ministack(ministack_t *stack)
{
    assert(stack != NULL);
    stack->top = NULL;
}

void
minipush(ministack_t *stack, slink_item_t *item)
{
    assert(stack != NULL);
    assert(item != NULL);
    assert(item->next == NULL); // Detect possible stale linkage

    item->next = stack->top;
    stack->top = item;
}

slink_item_t *
minipop(ministack_t *stack)
{
    slink_item_t *item;
    assert(stack != NULL);

    item = stack->top;
    if(item != NULL) {
        stack->top = item->next;
        item->next = NULL;
    }
    return item;
}
