/*
** LOUIS VIOT, 2020
** dslib
** File description:
** generic.c
*/

#include <stdlib.h>
#include <string.h>
#include "node.h"

dnode_t create_dnode(void *data, size_t size)
{
    dnode_t new = malloc(sizeof(struct double_node_s));

    if (new == NULL) {
        return NULL;
    }
    new->data = malloc(size);
    if (new->data == NULL) {
        return NULL;
    }
    memcpy(new->data, data, size);
    new->prev = NULL;
    new->next = NULL;
    return new;
}