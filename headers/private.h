/*
** LOUIS VIOT, 2020
** dslib
** File description:
** private.h
*/

#ifndef DSLIB_PRIVATE_H
#define DSLIB_PRIVATE_H

#include "linked_list.h"

dnode_t dll_get_head(dll_t);
dnode_t dll_get_tail(dll_t);
dnode_t dll_get_node_at(dll_t, size_t);
int dll_free_list(dll_t);
int dll_for_each(dll_t, void (*)(dnode_t));
int dll_rev_for_each(dll_t, void (*)(dnode_t));
int dll_push_front(dll_t, void *);
int dll_push_back(dll_t, void *);
int dll_insert(dll_t, size_t, void *);
void *dll_get_value_at(dll_t, size_t);
int dll_pop_front(dll_t);
int dll_pop_back(dll_t);
int dll_pop_at(dll_t, size_t);

#endif //DSLIB_PRIVATE_H