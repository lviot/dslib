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
    dll_t list = dll_init();
    dnode_t fetch = NULL;
    int n[3] = {1, 2, 3};

    list->push_back(list, &n[0], sizeof(int));
    list->push_back(list, &n[1], sizeof(int));
    list->push_back(list, &n[2], sizeof(int));
    cr_assert_eq(list->get_node_at(list, 23), NULL);
    fetch = list->get_node_at(list, 1);
    cr_assert_neq(fetch, NULL);
    cr_assert_eq(*(int *)fetch->data, 2);
    list->clear(list);
}

Test(dll_get_head, fetch_list_head)
{
    dll_t list = dll_init();
    dnode_t fetch = NULL;
    int n[3] = {1, 2, 3};

    cr_assert_eq(list->get_front(list), NULL);
    list->push_back(list, &n[0], sizeof(int));
    list->push_back(list, &n[1], sizeof(int));
    list->push_back(list, &n[2], sizeof(int));
    fetch = list->get_front(list);
    cr_assert_neq(fetch, NULL);
    cr_assert_eq(*(int *)fetch->data, 1);
    cr_assert_eq(list->get_front(NULL), NULL);
    list->clear(list);
}

Test(dll_get_tail, fetch_list_tail)
{
    dll_t list = dll_init();
    dnode_t fetch = NULL;
    int n[3] = {1, 2, 3};

    cr_assert_eq(list->get_back(list), NULL);
    list->push_back(list, &n[0], sizeof(int));
    list->push_back(list, &n[1], sizeof(int));
    list->push_back(list, &n[2], sizeof(int));
    fetch = list->get_back(list);
    cr_assert_neq(fetch, NULL);
    cr_assert_eq(*(int *)fetch->data, 3);
    cr_assert_eq(list->get_back(NULL), NULL);
    list->clear(list);
}

Test(dll_get_value_at, fetch_value_at)
{
    dll_t list = dll_init();
    dnode_t fetch = NULL;
    char *str[2] = {"bonjour", "aurevoir"};

    cr_assert_eq(list->get_value_at(NULL, 0), NULL);
    cr_assert_eq(list->get_value_at(list, 0), NULL);
    list->insert(list, 0, str[0], strlen(str[0]));
    list->insert(list, 1, str[1], strlen(str[1]));
    cr_assert_str_eq(list->get_value_at(list, 0), "bonjour");
    list->clear(list);
}