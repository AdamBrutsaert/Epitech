/*
** EPITECH PROJECT, 2024
** test_ex02.c
** File description:
** test_ex02.c
*/

#include "int_list.h"

#include <criterion/criterion.h>

Test(int_list_get_elem_at_front, empty_list)
{
    cr_assert_eq(int_list_get_elem_at_front(NULL), 0);
}

Test(int_list_get_elem_at_front, two_nodes)
{
    int_list_t *list = NULL;

    cr_expect(int_list_add_elem_at_front(&list, 10));
    cr_expect(int_list_add_elem_at_front(&list, 25));

    cr_assert_eq(int_list_get_elem_at_front(list), 25);
}


Test(int_list_get_elem_at_back, empty_list)
{
    cr_assert_eq(int_list_get_elem_at_back(NULL), 0);
}

Test(int_list_get_elem_at_back, two_nodes)
{
    int_list_t *list = NULL;

    cr_expect(int_list_add_elem_at_front(&list, 10));
    cr_expect(int_list_add_elem_at_front(&list, 25));

    cr_assert_eq(int_list_get_elem_at_back(list), 10);
}

Test(int_list_get_elem_at_position, two_nodes)
{
    int_list_t *list = NULL;

    cr_expect(int_list_add_elem_at_front(&list, 10));
    cr_expect(int_list_add_elem_at_front(&list, 25));

    cr_assert_eq(int_list_get_elem_at_position(list, 0), 25);
    cr_assert_eq(int_list_get_elem_at_position(list, 1), 10);
    cr_assert_eq(int_list_get_elem_at_position(list, 2), 0);
    cr_assert_eq(int_list_get_elem_at_position(NULL, 0), 0);
    cr_assert_eq(int_list_get_elem_at_position(NULL, 4), 0);
}
