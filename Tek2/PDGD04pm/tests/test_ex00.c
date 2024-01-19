/*
** EPITECH PROJECT, 2024
** int_list.c
** File description:
** int_list.c
*/

#include "int_list.h"
#include "utils.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(int_list_add_elem_at_back, three_add)
{
    int_list_t *list = NULL;

    cr_assert(int_list_add_elem_at_back(&list, 10));
    cr_assert(int_list_add_elem_at_back(&list, -42));
    cr_assert(int_list_add_elem_at_back(&list, 69));
    cr_assert(compare_int_list(list, (int []){10, -42, 69}, 3));
}

Test(int_list_dump, three_nodes, .init = cr_redirect_stdout)
{
    int_list_t *list = NULL;

    cr_expect(int_list_add_elem_at_back(&list, 10));
    cr_expect(int_list_add_elem_at_back(&list, -42));
    cr_expect(int_list_add_elem_at_back(&list, 69));

    int_list_dump(list);
    fflush(stdout);

    cr_assert_stdout_eq_str("10\n-42\n69\n");
}

Test(int_list_dump, empty_list, .init = cr_redirect_stdout)
{
    int_list_dump(NULL);
    fflush(stdout);

    cr_assert_stdout_eq_str("");
}

Test(int_list_get_size, three_nodes)
{
    int_list_t *list = NULL;

    cr_expect(int_list_add_elem_at_back(&list, 10));
    cr_expect(int_list_add_elem_at_back(&list, -42));
    cr_expect(int_list_add_elem_at_back(&list, 69));

    cr_assert_eq(int_list_get_size(list), 3);
}

Test(int_list_get_size, empty_list)
{
    cr_assert_eq(int_list_get_size(NULL), 0);
}

Test(int_list_is_empty, empty_list)
{
    cr_assert(int_list_is_empty(NULL));
}

Test(int_list_is_empty, one_node)
{
    int_list_t *list = NULL;

    cr_expect(int_list_add_elem_at_back(&list, 10));

    cr_assert_not(int_list_is_empty(list));
}

Test(int_list_clear, three_nodes)
{
    int_list_t *list = NULL;

    cr_expect(int_list_add_elem_at_back(&list, 10));
    cr_expect(int_list_add_elem_at_back(&list, -42));
    cr_expect(int_list_add_elem_at_back(&list, 69));

    cr_expect_not_null(list);
    int_list_clear(&list);

    cr_assert_null(list);
}

Test(int_list_clear, empty_list)
{
    int_list_t *list = NULL;

    int_list_clear(&list);
    cr_assert_null(list);
}
