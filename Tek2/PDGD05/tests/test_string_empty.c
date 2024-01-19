/*
** EPITECH PROJECT, 2024
** test_string_empty.c
** File description:
** test_string_empty.c
*/

#include "../string.h"

#include <criterion/criterion.h>

Test(empty, return_empty)
{
    string_t s;

    string_init(&s, "Hello");
    cr_assert_eq(s.empty(&s), 0);
}

Test(empty, return_empty_empty)
{
    string_t s;

    string_init(&s, "");
    cr_assert_eq(s.empty(&s), 1);
}

Test(empty, return_empty_null)
{
    string_t s;

    string_init(&s, NULL);
    cr_assert_eq(s.empty(&s), 1);
}
