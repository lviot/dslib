/*
** LOUIS VIOT, 2020
** dslib
** File description:
** getters.c
*/

#include "linked_list.h"

dnode_t dll_get_node_at(dll_t this, size_t pos)
{
    dnode_t curr;

    if (this == NULL || pos > this->size) {
        return NULL;
    }
    curr = pos < this->size / 2 ? this->_head : this->_tail;
    if (curr == this->_head) {
        for (size_t i = 0; i < pos; ++i) {
            curr = curr->next;
        }
    } else {
        for (size_t i = this->size; i - 1 > pos; --i) {
            curr = curr->prev;
        }
    }
    return curr;
}

dnode_t dll_get_head(dll_t this)
{
    return this == NULL ? NULL : this->_head;
}

dnode_t dll_get_tail(dll_t this)
{
    return this == NULL ? NULL : this->_tail;
}

/*
 * safer to use get_node_at and then read data
 */
void *dll_get_value_at(dll_t this, size_t pos)
{
    dnode_t node;

    if (this == NULL) {
        return NULL;
    }
    node = dll_get_node_at(this, pos);
    return node == NULL ? NULL : node->data;
}