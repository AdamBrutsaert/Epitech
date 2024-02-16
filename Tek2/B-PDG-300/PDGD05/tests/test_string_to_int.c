/*
** EPITECH PROJECT, 2024
** test_string_to_int.c
** File description:
** test_string_to_int.c
*/

#include "../string.h"

#include <criterion/criterion.h>

Test(to_int, positive)
{
    string_t s;

    string_init(&s, "123");
    cr_assert_eq(to_int(&s), atoi("123"));
}

Test(to_int, negative)
{
    string_t s;

    string_init(&s, "-1854823");
    cr_assert_eq(to_int(&s), atoi("-1854823"));
}

Test(to_int, empty)
{
    string_t s;

    string_init(&s, "");
    cr_assert_eq(to_int(&s), atoi(""));
}

Test(to_int, null)
{
    string_t s;

    string_init(&s, NULL);
    cr_assert_eq(to_int(&s), 0);
}
