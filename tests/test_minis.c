#include <stdint.h>
#include <stdio.h>

#include "minimal_stack.h"
#include "minimal_queue.h"

static const size_t TINY_SIZE = 4;
static const size_t SMALL_SIZE = 128;

static void
fill_ministack(ministack_t *stack, size_t *data,
               slink_item_t *items, size_t size)
{
    for(size_t i = 0; i < size; i++) {
        data[i] = size - i;
        initialize_slink_item(&items[i], (void *)&data[i]);
        minipush(stack, &items[i]);
    }
}

static void
empty_ministack_and_print(ministack_t *stack)
{
    slink_item_t *current;
    while((current = minipop(stack)) != NULL) {
        printf("%lu ",  *((size_t *)current->data));
    }
    puts("");
}

static void
test_ministack(ministack_t *stack, size_t size)
{
    uint64_t data[size];
    slink_item_t items[size];

    fill_ministack(stack, data, items, size);
    empty_ministack_and_print(stack);
}

static void
fill_miniqueue(miniqueue_t *queue, size_t *data,
               slink_item_t *items, size_t size)
{
    for(size_t i = 0; i < size; i++) {
        data[i] = size - i;
        initialize_slink_item(&items[i], (void *)&data[i]);
        minienqueue(queue, &items[i]);
    }
}

static void
empty_miniqueue_and_print(miniqueue_t *queue)
{
    slink_item_t *current;
    while((current = minidequeue(queue)) != NULL) {
        printf("%lu ",  *((size_t *)current->data));
    }
    puts("");
}


static void
test_miniqueue(miniqueue_t *queue, size_t size)
{
    uint64_t data[size];
    slink_item_t items[size];

    fill_miniqueue(queue, data, items, size);
    empty_miniqueue_and_print(queue);
}

int
main(void)
{
    miniqueue_t queue;
    ministack_t stack;

    initialize_miniqueue(&queue);
    test_miniqueue(&queue, TINY_SIZE);
    test_miniqueue(&queue, SMALL_SIZE);

    initialize_ministack(&stack);
    test_ministack(&stack, TINY_SIZE);
    test_ministack(&stack, SMALL_SIZE);
}
