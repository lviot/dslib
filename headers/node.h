/*
** LOUIS VIOT, 2020
** dslib
** File description:
** node.h
*/

#ifndef DSLIB_NODE_H
#define DSLIB_NODE_H

#include <stddef.h>

struct double_node_s
{
    void *data;
    struct double_node_s *prev;
    struct double_node_s *next;
};

typedef struct double_node_s *dnode_t;

dnode_t create_dnode(void *, size_t);

#endif //DSLIB_NODE_H