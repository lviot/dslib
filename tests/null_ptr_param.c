/*
** LOUIS VIOT, 2019
** dslib
** File description:
** null_ptr_param.c
*/

#include <criterion/criterion.h>
#include "ds.h"

Test(null_ptr_param, basic)
{
    dll_t list = dll_init(0);

    cr_assert_eq(list->push_front(NULL, NULL), -1);
    cr_assert_eq(list->push_back(NULL, NULL), -1);
    cr_assert_eq(list->insert(NULL, 0, NULL), -1);
    cr_assert_eq(list->get_node_at(NULL, 0), NULL);
    cr_assert_eq(list->get_value_at(NULL, 0), NULL);
    cr_assert_eq(list->pop_front(NULL), -1);
    cr_assert_eq(list->pop_back(NULL), -1);
    cr_assert_eq(list->pop_at(NULL, 1), -1);
    cr_assert_eq(list->clear(NULL), -1);
    cr_assert_eq(list->for_each(NULL, NULL), -1);
    cr_assert_eq(list->rev_for_each(NULL, NULL), -1);
    cr_assert_eq(list->for_each(list, NULL), -1);
    cr_assert_eq(list->rev_for_each(list, NULL), -1);
    list->clear(list);
}