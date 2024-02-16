/*
** EPITECH PROJECT, 2024
** test_string_c_str.c
** File description:
** test_string_c_str.c
*/

#include "../string.h"

#include <criterion/criterion.h>

Test(c_str, return_c_str)
{
    string_t s;

    string_init(&s, "Hello");
    cr_assert_str_eq(s.c_str(&s), "Hello");
}

Test(c_str, return_c_str_empty)
{
    string_t s;

    string_init(&s, "");
    cr_assert_str_eq(s.c_str(&s), "");
}

Test(c_str, return_c_str_null)
{
    string_t s;

    string_init(&s, NULL);
    cr_assert_null(s.c_str(&s));
}
