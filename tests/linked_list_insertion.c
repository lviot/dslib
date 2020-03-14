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
    dll_t list = dll_init();

    cr_assert_eq(list->size, 0);
    cr_assert_eq(list->_head, NULL);
    cr_assert_eq(list->_head, NULL);
    list->clear(list);
}

Test(dll_push_front, basic_push_front)
{
    dll_t list = dll_init();
    char *str[2] = {"first sentence", "second sentence"};

    list->push_front(list, str[0], strlen(str[0]));
    list->push_front(list, str[1], strlen(str[1]));
    cr_assert_str_eq(list->get_value_at(list, 0), "second sentence");
    cr_assert_str_neq(list->get_value_at(list, 0), "first sentence");
    cr_assert_str_eq(list->get_value_at(list, 1), "first sentence");
    cr_assert_str_neq(list->get_value_at(list, 1), "second sentence");
    list->clear(list);
}

Test(dll_push_back, basic_push_back)
{
    dll_t list = dll_init();
    char *str[2] = {"first sentence", "second sentence"};

    list->push_back(list, str[0], strlen(str[0]));
    list->push_back(list, str[1], strlen(str[1]));
    cr_assert_str_neq(list->get_value_at(list, 0), "second sentence");
    cr_assert_str_eq(list->get_value_at(list, 0), "first sentence");
    cr_assert_str_neq(list->get_value_at(list, 1), "first sentence");
    cr_assert_str_eq(list->get_value_at(list, 1), "second sentence");
    list->clear(list);
}

Test(dll_insert, basic_insert_at_position)
{
    dll_t list = dll_init();
    int n[4] = {1, 2, 3, 4};
    char *str = "1 bis";

    list->push_back(list, &n[0], sizeof(int));
    list->push_back(list, &n[1], sizeof(int));
    list->push_back(list, &n[2], sizeof(int));
    list->push_back(list, &n[3], sizeof(int));
    list->insert(list, 1, str, strlen(str));
    cr_assert_str_eq(list->get_value_at(list, 1), "1 bis");
    cr_assert_neq(list->get_value_at(list, 1), 1);
    // out of range
    list->insert(list, 1000, &n[2], sizeof(int));
    cr_assert_eq(list->size, 5);
    list->clear(list);
}

Test(dll_push_back, basic_push_back_with_integers)
{
    dll_t list = dll_init();
    int n[2] = {154, 45};

    list->push_back(list, &n[0], sizeof(int));
    list->push_back(list, &n[1], sizeof(int));
    cr_assert_neq(*(int *)list->get_value_at(list, 0), 45);
    cr_assert_eq(*(int *)list->get_value_at(list, 0), 154);
    cr_assert_neq(*(int *)list->get_value_at(list, 1), 154);
    cr_assert_eq(*(int *)list->get_value_at(list, 1), 45);
    list->clear(list);
}