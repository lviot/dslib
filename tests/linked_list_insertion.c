/*
** LOUIS VIOT, 2019
** dslib
** File description:
** linked_list_insertion.c
*/

#include <criterion/criterion.h>
#include <string.h>
#include "ds.h"

Test(dll_init, init_function)
{
    dll_t list = dll_init(sizeof(double));

    cr_assert_eq(list->size, 0);
    cr_assert_eq(list->type_size, sizeof(double));
    cr_assert_eq(list->_head, NULL);
    cr_assert_eq(list->_head, NULL);
    list->clear(list);
}

Test(dll_insert, basic_insert_at_position)
{
    dll_t list = dll_init(sizeof(int));
    int n[4] = {1, 2, 3, 4};

    list->push_back(list, &n[0]);
    list->push_back(list, &n[1]);
    list->push_back(list, &n[2]);
    list->push_back(list, &n[3]);
    cr_assert_neq(list->get_value_at(list, 1), 1);
    // out of range
    list->insert(list, 1000, &n[2]);
    cr_assert_eq(list->size, 4);
    list->clear(list);
}

Test(dll_push_back, basic_push_back_with_integers)
{
    dll_t list = dll_init(sizeof(int));
    int n[2] = {154, 45};

    list->push_back(list, &n[0]);
    list->push_back(list, &n[1]);
    cr_assert_neq(*(int *)list->get_value_at(list, 0), 45);
    cr_assert_eq(*(int *)list->get_value_at(list, 0), 154);
    cr_assert_neq(*(int *)list->get_value_at(list, 1), 154);
    cr_assert_eq(*(int *)list->get_value_at(list, 1), 45);
    list->clear(list);
}