/*
** LOUIS VIOT, 2020
** dslib
** File description:
** single_linked_list.c
*/

#include <stdlib.h>
#include "private.h"
#include "linked_list.h"

dll_t dll_init(void)
{
    dll_t list = malloc(sizeof(struct dll_s));

    if (list == NULL)
        return NULL;
    list->size = 0;
    list->_head = NULL;
    list->_tail = NULL;
    list->push_front = &dll_push_front;
    list->push_back = &dll_push_back;
    list->insert = &dll_insert;
    list->get_node_at = &dll_get_node_at;
    list->get_front = &dll_get_head;
    list->get_back = &dll_get_tail;
    list->get_value_at = &dll_get_value_at;
    list->pop_front = &dll_pop_front;
    list->pop_back = &dll_pop_back;
    list->pop_at = &dll_pop_at;
    list->clear = &dll_free_list;
    list->for_each = &dll_for_each;
    list->rev_for_each = &dll_rev_for_each;
    return list;
}