#include <stdint.h>
#include <stdio.h>

#include "ccaclib/common/slink_item.h"
#include "ccaclib/queues/minimal_queue.h"

static const size_t TINY_QUEUE_SIZE = 4;
static const size_t SMALL_QUEUE_SIZE = 128;
static const size_t LARGE_QUEUE_SIZE = 1024;
static const size_t HUGE_QUEUE_SIZE = 4096;
static const size_t MASSIVE_QUEUE_SIZE = 65536;
static const size_t UNREASONABLE_QUEUE_SIZE = 262144;

static void
test_complete(void)
{
	puts("test complete!");
}

void
fill_miniqueue(miniqueue_t *queue, size_t *data,
               slink_item_t *items, size_t size)
{
    for(size_t i = 0; i < size; i++) {
        data[i] = size - i;
        initialize_slink_item(&items[i], (void *)&data[i]);
        minienqueue(queue, &items[i]);
    }
}

void
minidequeue_and_print(miniqueue_t *queue)
{
    slink_item_t *current;
    while((current = minidequeue(queue)) != NULL) {
        printf("%lu ",  *((size_t *)current->data));
    }
    puts("");
}

void
miniqueue_test(miniqueue_t *queue, size_t size)
{
    uint64_t data[size];
    slink_item_t items[size];

    fill_miniqueue(queue, data, items, size);
    minidequeue_and_print(queue);
}

int
main(void)
{
    miniqueue_t queue;
    initialize_miniqueue(&queue);
    miniqueue_test(&queue, TINY_QUEUE_SIZE);
    miniqueue_test(&queue, SMALL_QUEUE_SIZE);
    miniqueue_test(&queue, LARGE_QUEUE_SIZE);
    miniqueue_test(&queue, HUGE_QUEUE_SIZE);
    miniqueue_test(&queue, MASSIVE_QUEUE_SIZE);
    miniqueue_test(&queue, UNREASONABLE_QUEUE_SIZE);
	test_complete();
}
