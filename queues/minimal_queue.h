typedef struct queue_item queue_item_t;

typedef struct queue {
   queue_item_t *head;
   queue_item_t *tail;
} queue_t;

struct queue_item {
    void *data;
    queue_item_t *next;
};

void
initialize_queue(queue_t *queue);

void
initialize_queue_item(queue_item_t *item, void *data);

void
enqueue(queue_t *queue, queue_item_t *item);

queue_item_t *
dequeue(queue_t *queue);
