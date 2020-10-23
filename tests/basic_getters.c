/*
** LOUIS VIOT, 2019
** dslib
** File description:
** getters.c
*/

#include <criterion/criterion.h>
#include <string.h>
#include "ds.h"

Test(dll_get_node_at, basic_get_node)
{
    dll_t list = dll_init(sizeof(int));
    dnode_t fetch = NULL;
    int n[3] = {1, 2, 3};

    list->push_back(list, &n[0]);
    list->push_back(list, &n[1]);
    list->push_back(list, &n[2]);
    cr_assert_eq(list->get_node_at(list, 23), NULL);
    fetch = list->get_node_at(list, 1);
    cr_assert_neq(fetch, NULL);
    cr_assert_eq(*(int *)fetch->data, 2);
    list->clear(list);
}

Test(dll_get_head, fetch_list_head)
{
    dll_t list = dll_init(sizeof(int));
    dnode_t fetch = NULL;
    int n[3] = {1, 2, 3};

    cr_assert_eq(list->get_front(list), NULL);
    list->push_back(list, &n[0]);
    list->push_back(list, &n[1]);
    list->push_back(list, &n[2]);
    fetch = list->get_front(list);
    cr_assert_neq(fetch, NULL);
    cr_assert_eq(*(int *)fetch->data, 1);
    cr_assert_eq(list->get_front(NULL), NULL);
    list->clear(list);
}

Test(dll_get_tail, fetch_list_tail)
{
    dll_t list = dll_init(sizeof(int));
    dnode_t fetch = NULL;
    int n[3] = {1, 2, 3};

    cr_assert_eq(list->get_back(list), NULL);
    list->push_back(list, &n[0]);
    list->push_back(list, &n[1]);
    list->push_back(list, &n[2]);
    fetch = list->get_back(list);
    cr_assert_neq(fetch, NULL);
    cr_assert_eq(*(int *)fetch->data, 3);
    cr_assert_eq(list->get_back(NULL), NULL);
    list->clear(list);
}