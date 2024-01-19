/*
** EPITECH PROJECT, 2024
** test_string_assign_c.c
** File description:
** test_string_assign_c.c
*/

#include "../string.h"

#include <criterion/criterion.h>

Test(string_assign_c, assign_c_string)
{
    string_t s;

    string_init(&s, "Hello World");
    cr_expect_str_eq(s.str, "Hello World");

    s.assign_c(&s, "World Hello");
    cr_assert_str_eq(s.str, "World Hello");

    string_destroy(&s);
}

Test(string_assign_c, null_string)
{
    string_t s;

    string_init(&s, "Hello World");
    cr_expect_str_eq(s.str, "Hello World");

    s.assign_c(&s, NULL);
    cr_assert_null(s.str);

    string_destroy(&s);
}
