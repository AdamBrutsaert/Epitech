/*
** EPITECH PROJECT, 2024
** test_string_length.c
** File description:
** test_string_length.c
*/

#include "../string.h"

#include <criterion/criterion.h>

Test(length, return_length_of_string)
{
    string_t s;

    string_init(&s, "Hello");
    cr_assert_eq(length(&s), 5);
}

Test(length, return_length_of_string_with_empty_string)
{
    string_t s;

    string_init(&s, "");
    cr_assert_eq(length(&s), 0);
}

Test(length, return_length_of_string_with_null_string)
{
    string_t s;

    string_init(&s, NULL);
    cr_assert_eq(length(&s), -1);
}
