/*
** LOUIS VIOT, 2019
** dslib
** File description:
** basic_remove.c
*/

#include <criterion/criterion.h>
#include "ds.h"

Test(dll_pop_front, remove_first_item)
{
    dll_t list = dll_init(sizeof(int));
    int n[2] = {-42, -21};

    cr_assert_eq(list->pop_front(NULL), -1);
    cr_assert_eq(list->pop_front(list), -1);
    list->push_back(list, &n[0]);
    list->push_back(list, &n[1]);
    cr_assert_eq(list->size, 2);
    cr_assert_eq(list->pop_front(list), 0);
    cr_assert_eq(list->size, 1);
    cr_assert_eq(list->pop_front(list), 0);
    cr_assert_eq(list->size, 0);
    list->clear(list);
}

Test(dll_pop_back, remove_last_item)
{
    dll_t list = dll_init(sizeof(int));
    int n[2] = {-42, -21};

    cr_assert_eq(list->pop_back(NULL), -1);
    cr_assert_eq(list->pop_back(list), -1);
    list->push_back(list, &n[0]);
    list->push_back(list, &n[1]);
    cr_assert_eq(list->size, 2);
    cr_assert_eq(list->pop_back(list), 0);
    cr_assert_eq(list->size, 1);
    cr_assert_eq(list->pop_back(list), 0);
    cr_assert_eq(list->size, 0);
    list->clear(list);
}

Test(dll_pop_at, remove_item_at_position)
{
    dll_t list = dll_init(sizeof(int));
    dnode_t fetch = NULL;
    int n[5] = {0, 1, 2, 3, 4};

    cr_assert_eq(list->pop_at(NULL, 0), -1);
    cr_assert_eq(list->pop_at(list, 1), -1);
    list->push_back(list, &n[0]);
    list->push_back(list, &n[1]);
    list->push_back(list, &n[2]);
    list->push_back(list, &n[3]);
    list->push_back(list, &n[4]);
    cr_assert_eq(list->pop_at(list, 0), 0);
    cr_assert_eq(*(int *)list->get_value_at(list, 0), 1);
    cr_assert_eq(list->pop_at(list, 42), -1);
    cr_assert_eq(list->size, 4);
    cr_assert_eq(list->pop_at(list, 3), 0);
    fetch = list->get_back(list);
    cr_assert_eq(*(int *)fetch->data, 3);
    list->clear(list);
}