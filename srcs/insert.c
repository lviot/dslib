/*
** LOUIS VIOT, 2020
** dslib
** File description:
** insert.c
*/

#include <stdlib.h>
#include "linked_list.h"

int dll_push_front(dll_t this, void *data)
{
    dnode_t node;

    if (this == NULL) {
        return -1;
    }
    node = create_dnode(data);
    if (node == NULL) {
        return -1;
    }
    this->size++;
    node->next = this->_head;
    node->prev = NULL;
    if (this->_head != NULL) {
        this->_head->prev = node;
    }
    if (this->_tail == NULL) {
        this->_tail = node;
    }
    this->_head = node;
    return 0;
}

int dll_push_back(dll_t this, void *data)
{
    dnode_t node;

    if (this == NULL) {
        return -1;
    }
    node = create_dnode(data);
    if (node == NULL) {
        return -1;
    }
    this->size++;
    if (this->_tail == NULL) {
        this->_head = node;
        this->_tail = node;
        return 0;
    }
    this->_tail->next = node;
    node->prev = this->_tail;
    this->_tail = node;
    return 0;
}

/*
 * 'if' statement at line 67 missing brackets to fit with
 * Epitech C coding style,
 */
int dll_insert(dll_t this, void *data, size_t pos)
{
    dnode_t node = NULL;
    dnode_t prev_node = NULL;

    if (this == NULL)
        return -1;
    if (pos == 0) {
        return dll_push_front(this, data);
    }
    node = create_dnode(data);
    prev_node = this->get_node_at(this, pos - 1);
    if (node == NULL || prev_node == NULL) {
        return -1;
    }
    this->size++;
    node->prev = prev_node;
    node->next = prev_node->next;
    if (prev_node->next) {
        prev_node->next->prev = node;
    }
    prev_node->next = node;
    return 0;
}
