/*
** LOUIS VIOT, 2019
** dslib
** File description:
** basic_tools.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
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
    node->data = (void *)((unsigned long)node->data * 2);
}

Test(dll_for_each, for_each_basic_behavior)
{
    dll_t list = dll_init();
    dnode_t fetch = NULL;

    list->push_back(list, (void *)1);
    list->push_back(list, (void *)2);
    list->push_back(list, (void *)3);
    list->push_back(list, (void *)4);
    list->push_back(list, (void *)5);
    list->for_each(list, &double_it);
    fetch = list->get_front(list);
    cr_assert_eq(fetch->data, 2);
    fetch = list->get_back(list);
    cr_assert_eq(fetch->data, 10);
    list->clear(list);
}

Test(dll_rev_for_each, rev_for_each_basic_behavior, .init=redirect_stdout)
{
    dll_t list = dll_init();
    dnode_t fetch = NULL;

    list->push_back(list, (void *)"Ceci");
    list->push_back(list, (void *)"est une");
    list->push_back(list, (void *)"liste de");
    list->push_back(list, (void *)"string");
    list->rev_for_each(list, &print);
    fflush(stdout);
    cr_assert_stdout_eq_str("string\nliste de\nest une\nCeci\n", "");
    list->clear(list);
}