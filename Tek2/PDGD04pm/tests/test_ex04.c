/*
** EPITECH PROJECT, 2024
** test_ex04.c
** File description:
** test_ex04.c
*/

#include "list.h"
#include "utils.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(list_get_size, empty_list)
{
    cr_assert_eq(list_get_size(NULL), 0);
}

Test(list_get_size, two_nodes)
{
    list_t *list = NULL;

    cr_expect(list_add_elem_at_front(&list, NULL));
    cr_expect(list_add_elem_at_front(&list, NULL));

    cr_assert_eq(list_get_size(list), 2);
}

Test(list_is_empty, empty_list)
{
    cr_assert(list_is_empty(NULL));
}

Test(list_is_empty, one_node)
{
    list_t *list = NULL;

    cr_expect(list_add_elem_at_front(&list, NULL));

    cr_assert_not(list_is_empty(list));
}

Test(list_add_elem_at_front, three_add)
{
    list_t *list = NULL;

    cr_assert(list_add_elem_at_front(&list, NULL));
    cr_assert(list_add_elem_at_front(&list, (void *)0x1));
    cr_assert(list_add_elem_at_front(&list, (void *)0x2));
    cr_assert(compare_list(list, (void *[]){(void *)0x2, (void *)0x1, NULL}, 3));
}

Test(list_add_elem_at_back, three_add)
{
    list_t *list = NULL;

    cr_assert(list_add_elem_at_back(&list, NULL));
    cr_assert(list_add_elem_at_back(&list, (void *)0x1));
    cr_assert(list_add_elem_at_back(&list, (void *)0x2));
    cr_assert(compare_list(list, (void *[]){NULL, (void *)0x1, (void *)0x2}, 3));
}

Test(list_add_elem_at_position, add_front)
{
    list_t *list = NULL;

    cr_assert(list_add_elem_at_position(&list, NULL, 0));
    cr_assert(compare_list(list, (void *[]){NULL}, 1));
}

Test(list_add_elem_at_position, add_back)
{
    list_t *list = NULL;

    cr_expect(list_add_elem_at_front(&list, NULL));

    cr_assert(list_add_elem_at_position(&list, (void *)0x1, 1));
    cr_assert(compare_list(list, (void *[]){NULL, (void *)0x1}, 2));
}

Test(list_add_elem_at_position, add_middle)
{
    list_t *list = NULL;

    cr_expect(list_add_elem_at_front(&list, NULL));
    cr_expect(list_add_elem_at_front(&list, (void *)0x1));

    cr_assert(list_add_elem_at_position(&list, (void *)0x2, 1));
    cr_assert(compare_list(list, (void *[]){ (void *)0x1, (void *)0x2, NULL }, 3));
}

Test(list_add_elem_at_position, add_out_of_band)
{
    list_t *list = NULL;

    cr_expect(list_add_elem_at_front(&list, NULL));
    cr_expect(list_add_elem_at_front(&list, (void *)0x1));

    cr_assert_not(list_add_elem_at_position(&list, (void *)0x2, 3));
    cr_assert(compare_list(list, (void *[]){ (void *)0x1, NULL }, 2));
}

Test(list_get_elem_at_front, empty_list)
{
    cr_assert_eq(list_get_elem_at_front(NULL), NULL);
}

Test(list_get_elem_at_front, two_nodes)
{
    list_t *list = NULL;

    cr_expect(list_add_elem_at_front(&list, NULL));
    cr_expect(list_add_elem_at_front(&list, (void *)0x1));

    cr_assert_eq(list_get_elem_at_front(list), (void *)0x1);
}

Test(list_get_elem_at_back, empty_list)
{
    cr_assert_eq(list_get_elem_at_back(NULL), NULL);
}

Test(list_get_elem_at_back, two_nodes)
{
    list_t *list = NULL;

    cr_expect(list_add_elem_at_front(&list, NULL));
    cr_expect(list_add_elem_at_front(&list, (void *)0x1));

    cr_assert_eq(list_get_elem_at_back(list), NULL);
}

Test(list_get_elem_at_position, two_nodes)
{
    list_t *list = NULL;

    cr_expect(list_add_elem_at_front(&list, (void *)0x2));
    cr_expect(list_add_elem_at_front(&list, (void *)0x1));

    cr_assert_eq(list_get_elem_at_position(list, 0), (void *)0x1);
    cr_assert_eq(list_get_elem_at_position(list, 1), (void *)0x2);
    cr_assert_eq(list_get_elem_at_position(list, 2), NULL);
    cr_assert_eq(list_get_elem_at_position(NULL, 0), NULL);
    cr_assert_eq(list_get_elem_at_position(NULL, 4), NULL);
}

Test(list_del_elem_at_front, two_nodes)
{
    list_t *list = NULL;

    cr_expect(list_add_elem_at_front(&list, (void *)0x1));
    cr_expect(list_add_elem_at_front(&list, (void *)0x2));

    cr_assert(list_del_elem_at_front(&list));
    cr_assert(compare_list(list, (void *[]){ (void *)0x1 }, 1));

    cr_assert(list_del_elem_at_front(&list));
    cr_assert(compare_list(list, (void *[]){}, 0));

    cr_assert_not(list_del_elem_at_front(&list));
}

Test(list_del_elem_at_back, two_node)
{
    list_t *list = NULL;

    cr_expect(list_add_elem_at_front(&list, (void *)0x1));
    cr_expect(list_add_elem_at_front(&list, (void *)0x2));

    cr_assert(list_del_elem_at_back(&list));
    cr_assert(compare_list(list, (void *[]){ (void *)0x2 }, 1));

    cr_assert(list_del_elem_at_front(&list));
    cr_assert(compare_list(list, (void *[]){}, 0));

    cr_assert_not(list_del_elem_at_front(&list));
}

Test(list_del_elem_at_position, four_nodes)
{
    list_t *list = NULL;

    cr_expect(list_add_elem_at_back(&list, (void *)0x1));
    cr_expect(list_add_elem_at_back(&list, (void *)0x2));
    cr_expect(list_add_elem_at_back(&list, (void *)0x3));
    cr_expect(list_add_elem_at_back(&list, (void *)0x4));

    cr_assert(list_del_elem_at_position(&list, 0));
    cr_assert(compare_list(list, (void *[]){(void *)0x2, (void *)0x3, (void *)0x4}, 3));

    cr_assert(list_del_elem_at_position(&list, 1));
    cr_assert(compare_list(list, (void *[]){(void *)0x2, (void *)0x4}, 2));

    cr_assert(list_del_elem_at_position(&list, 1));
    cr_assert(compare_list(list, (void *[]){(void *)0x2}, 1));

    cr_assert_not(list_del_elem_at_position(&list, 1));

    cr_assert(list_del_elem_at_position(&list, 0));
    cr_assert(compare_list(list, (void *[]){}, 0));

    cr_assert_not(list_del_elem_at_position(&list, 0));
}

Test(list_clear, three_nodes)
{
    list_t *list = NULL;

    cr_expect(list_add_elem_at_back(&list, (void *)0x1));
    cr_expect(list_add_elem_at_back(&list, (void *)0x2));
    cr_expect(list_add_elem_at_back(&list, (void *)0x3));

    cr_expect_not_null(list);
    list_clear(&list);

    cr_assert_null(list);
}

Test(list_clear, empty_list)
{
    list_t *list = NULL;

    list_clear(&list);
    cr_assert_null(list);
}

static void value_displayer(const void *value)
{
    printf("%p\n", value);
}

Test(list_dump, empty_list, .init = cr_redirect_stdout)
{
    list_dump(NULL, value_displayer);
    fflush(stdout);

    cr_assert_stdout_eq_str("");
}

Test(list_dump, three_nodes, .init = cr_redirect_stdout)
{
    list_t *list = NULL;

    cr_expect(list_add_elem_at_front(&list, (void *)0x3));
    cr_expect(list_add_elem_at_front(&list, (void *)0x2));
    cr_expect(list_add_elem_at_front(&list, (void *)0x1));

    list_dump(list, value_displayer);
    fflush(stdout);

    cr_assert_stdout_eq_str("0x1\n0x2\n0x3\n");
}
