/*
** LOUIS VIOT, 2019
** dslib
** File description:
** basic_tools.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string.h>
#include "ds.h"

static void redirect_stdout(void)
{
    cr_redirect_stdout();
}

static void print(dnode_t node)
{
    printf("%s\n", (char *)node->data);
}

static void double_it(dnode_t node)
{
    int n = *(int *)node->data;
    n *= 2;
    memcpy(node->data, &n, sizeof(n));
}

Test(dll_for_each, for_each_basic_behavior)
{
    dll_t list = dll_init(sizeof(int));
    dnode_t fetch = NULL;
    int n[5] = {1, 2, 3, 4, 5};

    list->push_back(list, &n[0]);
    list->push_back(list, &n[1]);
    list->push_back(list, &n[2]);
    list->push_back(list, &n[3]);
    list->push_back(list, &n[4]);
    list->for_each(list, &double_it);
    fetch = list->get_front(list);
    cr_assert_eq(*(int *)fetch->data, 2);
    fetch = list->get_back(list);
    cr_assert_eq(*(int *)fetch->data, 10);
    list->clear(list);
}