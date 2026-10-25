#include <assert.h>
#include <stddef.h>

#include "ccaclib/common/slink_item.h"
#include "ccaclib/queues/minimal_queue.h"

static void
assert_invariants(miniqueue_t *queue)
{
	assert(queue != NULL);

    // If a queue has a head, it must have a tail
	assert((queue->head == NULL && queue->tail == NULL)
        || (queue->head != NULL && queue->tail != NULL));
}

void
initialize_miniqueue(miniqueue_t *queue)
{
	assert(queue != NULL);
    queue->head = NULL;
    queue->tail = NULL;
    assert_invariants(queue);
}

void
minienqueue(miniqueue_t *queue, slink_item_t *item)
{
    assert_invariants(queue);
    assert(item != NULL);
    assert(item->next == NULL); // Detect possible stale linkage

    if (queue->head == NULL) {
        queue->head = item;
    } else {
        queue->tail->next = item;
    }
    queue->tail = item;
    assert_invariants(queue);
}

slink_item_t *
minidequeue(miniqueue_t *queue)
{
    slink_item_t *item;

    assert_invariants(queue);

    item = queue->head;
    if(item != NULL) {
        queue->head = item->next;
        item->next = NULL;
    }
    if(queue->head == NULL) {
        queue->tail = NULL;
    }

    assert_invariants(queue);
    return item;
}
