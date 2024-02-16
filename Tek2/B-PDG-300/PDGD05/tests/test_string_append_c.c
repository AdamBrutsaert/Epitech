/*
** EPITECH PROJECT, 2024
** test_string_append_c.c
** File description:
** test_string_append_c.c
*/

#include "../string.h"

#include <criterion/criterion.h>

Test(string_append_c, append_c_string)
{
    string_t s;

    string_init(&s, "Hello ");
    cr_expect_str_eq(s.str, "Hello ");

    s.append_c(&s, "World!");
    cr_assert_str_eq(s.str, "Hello World!");

    string_destroy(&s);
}

Test(string_append_c, null_string)
{
    string_t s;

    string_init(&s, "Hello ");
    cr_expect_str_eq(s.str, "Hello ");

    s.append_c(&s, NULL);
    cr_assert_str_eq(s.str, "Hello ");

    string_destroy(&s);
}
