/*
** EPITECH PROJECT, 2024
** test_string_at.c
** File description:
** test_string_at.c
*/

#include "../string.h"

#include <criterion/criterion.h>

Test(at, return_char_at_index)
{
    string_t s;

    string_init(&s, "Hello World!");
    cr_expect_str_eq(s.str, "Hello World!");

    cr_assert_eq(s.at(&s, 0), 'H');
    cr_assert_eq(s.at(&s, 1), 'e');
    cr_assert_eq(s.at(&s, 2), 'l');
    cr_assert_eq(s.at(&s, 3), 'l');
    cr_assert_eq(s.at(&s, 4), 'o');
    cr_assert_eq(s.at(&s, 5), ' ');
    cr_assert_eq(s.at(&s, 6), 'W');
    cr_assert_eq(s.at(&s, 7), 'o');
    cr_assert_eq(s.at(&s, 8), 'r');
    cr_assert_eq(s.at(&s, 9), 'l');
    cr_assert_eq(s.at(&s, 10), 'd');
    cr_assert_eq(s.at(&s, 11), '!');
    cr_assert_eq(s.at(&s, 12), -1);

    string_destroy(&s);
}

Test(at, null_string)
{
    string_t s;

    string_init(&s, NULL);
    cr_expect_null(s.str);

    cr_assert_eq(s.at(&s, 0), -1);
    cr_assert_eq(s.at(&s, 1), -1);
    cr_assert_eq(s.at(&s, 2), -1);

    string_destroy(&s);
}
