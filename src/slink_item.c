#include <stddef.h>

#include "slink_item.h"

void
initialize_slink_item(slink_item_t *item, void *data)
{
    item->data = data;
    item->next = NULL;
}
