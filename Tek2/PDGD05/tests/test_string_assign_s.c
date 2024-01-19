/*
** EPITECH PROJECT, 2024
** test_string_assign_s.c
** File description:
** test_string_assign_s.c
*/

#include "../string.h"

#include <criterion/criterion.h>

Test(string_assign_s, assign_string)
{
    string_t s;
    string_t s2;

    string_init(&s, "Hello World");
    string_init(&s2, "World Hello");

    cr_expect_str_eq(s.str, "Hello World");
    cr_expect_str_eq(s2.str, "World Hello");

    s.assign_s(&s, &s2);

    cr_assert_str_eq(s.str, "World Hello");

    string_destroy(&s);
    string_destroy(&s2);
}

Test(string_assign_s, null_string)
{
    string_t s;

    string_init(&s, "Hello World");
    cr_expect_str_eq(s.str, "Hello World");

    s.assign_s(&s, NULL);

    cr_assert_null(s.str);

    string_destroy(&s);
}
