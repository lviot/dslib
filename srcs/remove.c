/*
** LOUIS VIOT, 2020
** dslib
** File description:
** remove.c
*/

#include <stdlib.h>
#include "linked_list.h"

int dll_pop_front(dll_t this)
{
    dnode_t tmp = NULL;

    if (this == NULL || this->_head == NULL) {
        return -1;
    }
    tmp = this->_head;
    this->_head = this->_head->next;
    if (this->_head == NULL) {
        this->_tail = NULL;
    } else {
        this->_head->prev = NULL;
    }
    this->size--;
    free(tmp);
    return 0;
}

int dll_pop_back(dll_t this)
{
    dnode_t tmp = NULL;

    if (this == NULL || this->_tail == NULL) {
        return -1;
    }
    tmp = this->_tail;
    this->_tail = this->_tail->prev;
    if (this->_tail == NULL) {
        this->_head = NULL;
    } else {
        this->_tail->next = NULL;
    }
    this->size--;
    free(tmp);
    return 0;
}

int dll_pop_at(dll_t this, size_t pos)
{
    dnode_t node = NULL;

    if (this == NULL) {
        return -1;
    }
    if (pos == 0) {
        return this->pop_front(this);
    } else if (pos == this->size - 1) {
        return this->pop_back(this);
    }
    node = this->get_node_at(this, pos);
    if (node == NULL) {
        return -1;
    }
    node->prev->next = node->next;
    free(node);
    return 0;
}