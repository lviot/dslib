/*
** LOUIS VIOT, 2019
** dslib
** File description:
** linked_list_insertion.c
*/

#include <criterion/criterion.h>
#include "ds.h"

Test(dll_init, init_function)
{
    dll_t list = dll_init();

    cr_assert_eq(list->size, 0);
    cr_assert_eq(list->_head, NULL);
    cr_assert_eq(list->_head, NULL);
    list->clear(list);
}

Test(dll_push_front, basic_push_front)
{
    dll_t list = dll_init();

    list->push_front(list, (void *)"first sentence");
    list->push_front(list, (void *)"second sentence");
    cr_assert_eq(list->get_value_at(list, 0), "second sentence");
    cr_assert_neq(list->get_value_at(list, 0), "first sentence");
    cr_assert_eq(list->get_value_at(list, 1), "first sentence");
    cr_assert_neq(list->get_value_at(list, 1), "second sentence");
    list->clear(list);
}

Test(dll_push_back, basic_push_back)
{
    dll_t list = dll_init();

    list->push_back(list, (void *)"first sentence");
    list->push_back(list, (void *)"second sentence");
    cr_assert_neq(list->get_value_at(list, 0), "second sentence");
    cr_assert_eq(list->get_value_at(list, 0), "first sentence");
    cr_assert_neq(list->get_value_at(list, 1), "first sentence");
    cr_assert_eq(list->get_value_at(list, 1), "second sentence");
    list->clear(list);
}

Test(dll_insert, basic_insert_at_position)
{
    dll_t list = dll_init();

    list->push_back(list, (void *)1);
    list->push_back(list, (void *)2);
    list->push_back(list, (void *)3);
    list->push_back(list, (void *)4);
    list->insert(list, (void *)"1 bis", 1);
    cr_assert_eq(list->get_value_at(list, 1), "1 bis");
    cr_assert_neq(list->get_value_at(list, 1), 1);
    // out of range
    list->insert(list, (void *)42, 1000);
    cr_assert_eq(list->size, 5);
    list->clear(list);
}

Test(dll_push_back, basic_push_back_with_integers)
{
    dll_t list = dll_init();

    list->push_back(list, (void *)154);
    list->push_back(list, (void *)45);
    cr_assert_neq(list->get_value_at(list, 0), 45);
    cr_assert_eq(list->get_value_at(list, 0), 154);
    cr_assert_neq(list->get_value_at(list, 1), 154);
    cr_assert_eq(list->get_value_at(list, 1), 45);
    list->clear(list);
}