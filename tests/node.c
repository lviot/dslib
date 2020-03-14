/*
** LOUIS VIOT, 2020
** dslib
** File description:
** node.c
*/

#include <criterion/criterion.h>
#include "linked_list.h"

Test(create_dnode, generic_functions_preliminary)
{
    dnode_t dnode = create_dnode((void *)42);

    cr_assert_eq(dnode->data, 42);
    cr_assert_neq(dnode, NULL);
}