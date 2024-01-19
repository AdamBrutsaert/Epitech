/*
** EPITECH PROJECT, 2024
** test_string_destroy.c
** File description:
** test_string_destroy.c
*/

#include "../string.h"

#include <criterion/criterion.h>

Test(string_destroy, destroy_string)
{
    string_t s;

    string_init(&s, "Hello World");
    string_destroy(&s);
    cr_assert_null(s.str);
}

Test(string_destroy, null_string)
{
    string_t s;

    string_init(&s, NULL);
    string_destroy(&s);
    cr_assert_null(s.str);
}
