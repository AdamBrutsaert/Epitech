/*
** EPITECH PROJECT, 2024
** test_ex03.c
** File description:
** test_ex03.c
*/

#include "int_list.h"
#include "utils.h"

#include <criterion/criterion.h>

Test(int_list_del_elem_at_front, two_nodes)
{
    int_list_t *list = NULL;

    cr_expect(int_list_add_elem_at_front(&list, 10));
    cr_expect(int_list_add_elem_at_front(&list, 5));

    cr_assert(int_list_del_elem_at_front(&list));
    cr_assert(compare_int_list(list, (int []){ 10 }, 1));

    cr_assert(int_list_del_elem_at_front(&list));
    cr_assert(compare_int_list(list, (int []){}, 0));

    cr_assert_not(int_list_del_elem_at_front(&list));
}

Test(int_list_del_elem_at_back, two_node)
{
    int_list_t *list = NULL;

    cr_expect(int_list_add_elem_at_front(&list, 10));
    cr_expect(int_list_add_elem_at_front(&list, 5));

    cr_assert(int_list_del_elem_at_back(&list));
    cr_assert(compare_int_list(list, (int []){ 5 }, 1));

    cr_assert(int_list_del_elem_at_front(&list));
    cr_assert(compare_int_list(list, (int []){}, 0));

    cr_assert_not(int_list_del_elem_at_front(&list));
}

Test(int_list_del_elem_at_position, four_nodes)
{
    int_list_t *list = NULL;

    cr_expect(int_list_add_elem_at_front(&list, 10));
    cr_expect(int_list_add_elem_at_front(&list, 5));
    cr_expect(int_list_add_elem_at_front(&list, 2));
    cr_expect(int_list_add_elem_at_front(&list, 1));

    cr_assert(int_list_del_elem_at_position(&list, 0));
    cr_assert(compare_int_list(list, (int[]){2, 5, 10}, 3));

    cr_assert(int_list_del_elem_at_position(&list, 1));
    cr_assert(compare_int_list(list, (int[]){2, 10}, 2));

    cr_assert(int_list_del_elem_at_position(&list, 1));
    cr_assert(compare_int_list(list, (int[]){2}, 1));

    cr_assert_not(int_list_del_elem_at_position(&list, 1));
    cr_assert(int_list_del_elem_at_position(&list, 0));
    cr_assert(compare_int_list(list, (int[]){}, 0));

    cr_assert_not(int_list_del_elem_at_position(&list, 0));
}
