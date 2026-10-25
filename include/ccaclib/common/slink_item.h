#ifndef CCACLIB_SLINK_ITEM_H
#define CCACLIB_SLINK_ITEM_H

typedef struct slink_item slink_item_t;

struct slink_item {
    void *data;
    slink_item_t *next;
};

void
initialize_slink_item(slink_item_t *item, void *data);

#endif
