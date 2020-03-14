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
    dll_t list = dll_init();
    dnode_t fetch = NULL;
    int n[5] = {1, 2, 3, 4, 5};

    list->push_back(list, &n[0], sizeof(int));
    list->push_back(list, &n[1], sizeof(int));
    list->push_back(list, &n[2], sizeof(int));
    list->push_back(list, &n[3], sizeof(int));
    list->push_back(list, &n[4], sizeof(int));
    list->for_each(list, &double_it);
    fetch = list->get_front(list);
    cr_assert_eq(*(int *)fetch->data, 2);
    fetch = list->get_back(list);
    cr_assert_eq(*(int *)fetch->data, 10);
    list->clear(list);
}

Test(dll_rev_for_each, rev_for_each_basic_behavior, .init=redirect_stdout)
{
    dll_t list = dll_init();
    dnode_t fetch = NULL;
    char *str[4] = {"Ceci", "est une", "liste de", "string"};

    list->push_back(list, str[0], strlen(str[0]));
    list->push_back(list, str[1], strlen(str[1]));
    list->push_back(list, str[2], strlen(str[2]));
    list->push_back(list, str[3], strlen(str[3]));
    list->rev_for_each(list, &print);
    fflush(stdout);
    cr_assert_stdout_eq_str("string\nliste de\nest une\nCeci\n", "");
    list->clear(list);
}