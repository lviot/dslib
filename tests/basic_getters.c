/*
** LOUIS VIOT, 2019
** dslib
** File description:
** getters.c
*/

#include <criterion/criterion.h>
#include "ds.h"

Test(dll_get_node_at, basic_get_node)
{
    dll_t list = dll_init();
    dnode_t fetch = NULL;

    list->push_back(list, (void *)1);
    list->push_back(list, (void *)2);
    list->push_back(list, (void *)3);
    cr_assert_eq(list->get_node_at(list, 23), NULL);
    fetch = list->get_node_at(list, 1);
    cr_assert_neq(fetch, NULL);
    cr_assert_eq(fetch->data, 2);
    list->clear(list);
}

Test(dll_get_head, fetch_list_head)
{
    dll_t list = dll_init();
    dnode_t fetch = NULL;

    cr_assert_eq(list->get_front(list), NULL);
    list->push_back(list, (void *)1);
    list->push_back(list, (void *)2);
    list->push_back(list, (void *)3);
    fetch = list->get_front(list);
    cr_assert_neq(fetch, NULL);
    cr_assert_eq(fetch->data, 1);
    cr_assert_eq(list->get_front(NULL), NULL);
    list->clear(list);
}

Test(dll_get_tail, fetch_list_tail)
{
    dll_t list = dll_init();
    dnode_t fetch = NULL;
    
    cr_assert_eq(list->get_back(list), NULL);
    list->push_back(list, (void *)1);
    list->push_back(list, (void *)2);
    list->push_back(list, (void *)3);
    fetch = list->get_back(list);
    cr_assert_neq(fetch, NULL);
    cr_assert_eq(fetch->data, 3);
    cr_assert_eq(list->get_back(NULL), NULL);
    list->clear(list);
}

Test(dll_get_value_at, fetch_value_at)
{
    dll_t list = dll_init();
    dnode_t fetch = NULL;

    cr_assert_eq(list->get_value_at(NULL, 0), NULL);
    cr_assert_eq(list->get_value_at(list, 0), NULL);
    list->insert(list, (void *)"bonjour", 0);
    list->insert(list, (void *)"aurevoir", 1);
    cr_assert_eq(list->get_value_at(list, 0), "bonjour");
    list->clear(list);
}