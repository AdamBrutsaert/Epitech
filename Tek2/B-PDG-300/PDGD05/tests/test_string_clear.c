/*
** EPITECH PROJECT, 2024
** test_string_clear.c
** File description:
** test_string_clear.c
*/

#include "../string.h"

#include <criterion/criterion.h>

Test(clear, clear_string)
{
    string_t s;

    string_init(&s, "Hello World!");
    cr_expect_str_eq(s.str, "Hello World!");

    s.clear(&s);
    cr_assert_str_eq(s.str, "");

    string_destroy(&s);
}

Test(clear, null_string)
{
    string_t s;

    string_init(&s, NULL);
    cr_expect_null(s.str);

    s.clear(&s);
    cr_assert_null(s.str);

    string_destroy(&s);
}
