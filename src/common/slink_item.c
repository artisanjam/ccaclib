#include <assert.h>
#include <stddef.h>

#include "ccaclib/common/slink_item.h"

void
initialize_slink_item(slink_item_t *item, void *data)
{
    assert(item != NULL);
    item->data = data;
    item->next = NULL;
}
