#include <stdint.h>
#include <stdio.h>

#include "minimal_queue.h"

static const size_t TINY_QUEUE_SIZE = 4;
static const size_t SMALL_QUEUE_SIZE = 128;
static const size_t LARGE_QUEUE_SIZE = 1024;
static const size_t HUGE_QUEUE_SIZE = 4096;
static const size_t MASSIVE_QUEUE_SIZE = 65536;
static const size_t UNREASONABLE_QUEUE_SIZE = 262144;

void
fill_queue(queue_t *queue, size_t *data,
           queue_item_t *items, size_t size)
{
    for(size_t i = 0; i < size; i++) {
        data[i] = size - i;
        initialize_queue_item(&items[i], (void *)&data[i]);
        enqueue(queue, &items[i]);
    }
}

void
dequeue_and_print(queue_t *queue)
{
    queue_item_t *current;
    while((current = dequeue(queue)) != NULL) {
        printf("%lu ",  *((size_t *)current->data));
    }
    puts("");
}

void
basic_queue_test(queue_t *queue, size_t size)
{
    uint64_t data[size];
    queue_item_t items[size];

    fill_queue(queue, data, items, size);
    dequeue_and_print(queue);
}

int
main(void)
{
    queue_t queue;
    initialize_queue(&queue);
    basic_queue_test(&queue, TINY_QUEUE_SIZE);
    basic_queue_test(&queue, SMALL_QUEUE_SIZE);
    basic_queue_test(&queue, LARGE_QUEUE_SIZE);
    basic_queue_test(&queue, HUGE_QUEUE_SIZE);
    basic_queue_test(&queue, MASSIVE_QUEUE_SIZE);
    basic_queue_test(&queue, UNREASONABLE_QUEUE_SIZE);
}
