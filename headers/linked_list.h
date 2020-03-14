/*
** LOUIS VIOT, 2020
** dslib
** File description:
** linked_list.h
*/

#ifndef DSLIB_LINKED_LIST_H
#define DSLIB_LINKED_LIST_H

#include <stddef.h>
#include "node.h"

struct dll_s
{
    dnode_t _head;
    dnode_t _tail;
    size_t size;
    int (*push_front)(struct dll_s *, void *);
    int (*push_back)(struct dll_s *, void *);
    int (*insert)(struct dll_s *, void *, size_t);
    dnode_t (*get_node_at)(struct dll_s *, size_t);
    dnode_t (*get_front)(struct dll_s *);
    dnode_t (*get_back)(struct dll_s *);
    void *(*get_value_at)(struct dll_s *, size_t);
    int (*pop_front)(struct dll_s *);
    int (*pop_back)(struct dll_s *);
    int (*pop_at)(struct dll_s *, size_t);
    int (*clear)(struct dll_s *);
    int (*for_each)(struct dll_s *, void (*)(dnode_t));
    int (*rev_for_each)(struct dll_s *, void (*)(dnode_t));
};

typedef struct dll_s *dll_t;

#endif //DSLIB_LINKED_LIST_H