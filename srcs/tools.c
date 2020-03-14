/*
** LOUIS VIOT, 2020
** dslib
** File description:
** tools.c
*/

#include <stdlib.h>
#include "linked_list.h"

int dll_free_list(dll_t this)
{
    dnode_t current = NULL;
    dnode_t tmp = NULL;

    if (this == NULL) {
        return -1;
    }
    current = this->_head;
    while (current) {
        tmp = current;
        current = current->next;
        free(tmp);
    }
    free(this);
    return 0;
}

int dll_for_each(dll_t this, void (*fptr)(dnode_t))
{
    dnode_t current = NULL;

    if (this == NULL || fptr == NULL) {
        return -1;
    }
    current = this->_head;
    while (current) {
        fptr(current);
        current = current->next;
    }
    return 0;
}

int dll_rev_for_each(dll_t this, void (*fptr)(dnode_t))
{
    dnode_t current = NULL;

    if (this == NULL || fptr == NULL) {
        return -1;
    }
    current = this->_tail;
    while (current) {
        fptr(current);
        current = current->prev;
    }
    return 0;
}