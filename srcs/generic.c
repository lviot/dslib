/*
** LOUIS VIOT, 2020
** dslib
** File description:
** generic.c
*/

#include <stdlib.h>
#include "node.h"

dnode_t create_dnode(void *data)
{
    dnode_t new = malloc(sizeof(struct double_node_s));

    if (new == NULL) {
        return NULL;
    }
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}