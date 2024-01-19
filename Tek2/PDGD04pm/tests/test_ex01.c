/*
** EPITECH PROJECT, 2024
** ex01.c
** File description:
** ex01.c
*/

#include "int_list.h"
#include "utils.h"

#include <criterion/criterion.h>

Test(int_list_add_elem_at_front, three_add)
{
    int_list_t *list = NULL;

    cr_assert(int_list_add_elem_at_front(&list, 10));
    cr_assert(int_list_add_elem_at_front(&list, -42));
    cr_assert(int_list_add_elem_at_front(&list, -69));
    cr_assert(compare_int_list(list, (int []){ -69, -42, 10}, 3));
}

Test(int_list_add_elem_at_position, add_front)
{
    int_list_t *list = NULL;

    cr_assert(int_list_add_elem_at_position(&list, 10, 0));
    cr_assert(compare_int_list(list, (int []){ 10 }, 1));
}

Test(int_list_add_elem_at_position, add_back)
{
    int_list_t *list = NULL;

    cr_expect(int_list_add_elem_at_front(&list, 5));

    cr_assert(int_list_add_elem_at_position(&list, 10, 1));
    cr_assert(compare_int_list(list, (int []){ 5, 10 }, 2));
}

Test(int_list_add_elem_at_position, add_middle)
{
    int_list_t *list = NULL;

    cr_expect(int_list_add_elem_at_front(&list, 5));
    cr_expect(int_list_add_elem_at_front(&list, 10));

    cr_assert(int_list_add_elem_at_position(&list, 7, 1));
    cr_assert(compare_int_list(list, (int []){ 10, 7, 5 }, 3));
}

Test(int_list_add_elem_at_position, add_out_of_band)
{
    int_list_t *list = NULL;

    cr_expect(int_list_add_elem_at_front(&list, 5));
    cr_expect(int_list_add_elem_at_front(&list, 10));

    cr_assert_not(int_list_add_elem_at_position(&list, 7, 3));
    cr_assert(compare_int_list(list, (int []){ 10, 5 }, 2));
}
