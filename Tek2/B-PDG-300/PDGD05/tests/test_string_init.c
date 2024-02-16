/*
** EPITECH PROJECT, 2024
** test_string_init.c
** File description:
** test_string_init.c
*/

#include "../string.h"

#include <criterion/criterion.h>

Test(string_init, init_string)
{
    string_t s;

    string_init(&s, "Hello World");
    cr_assert_str_eq(s.str, "Hello World");
    string_destroy(&s);
}

Test(string_init, null_string)
{
    string_t s;

    string_init(&s, NULL);
    cr_assert_null(s.str);
    string_destroy(&s);
}
