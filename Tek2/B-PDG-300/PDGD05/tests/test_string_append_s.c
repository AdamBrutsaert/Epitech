/*
** EPITECH PROJECT, 2024
** test_string_append_s.c
** File description:
** test_string_append_s.c
*/

#include "../string.h"

#include <criterion/criterion.h>

Test(string_append_s, append_s_string)
{
    string_t s;
    string_t ap;

    string_init(&s, "Hello ");
    string_init(&ap, "World!");
    cr_expect_str_eq(s.str, "Hello ");
    cr_expect_str_eq(ap.str, "World!");

    s.append_s(&s, &ap);
    cr_assert_str_eq(s.str, "Hello World!");
    cr_assert_str_eq(ap.str, "World!");

    string_destroy(&s);
    string_destroy(&ap);
}

Test(string_append_s, null_string)
{
    string_t s;
    string_t ap;

    string_init(&s, "Hello ");
    string_init(&ap, NULL);
    cr_expect_str_eq(s.str, "Hello ");
    cr_expect_null(ap.str);

    s.append_s(&s, &ap);
    cr_assert_str_eq(s.str, "Hello ");
    cr_assert_null(ap.str);

    string_destroy(&s);
    string_destroy(&ap);
}
