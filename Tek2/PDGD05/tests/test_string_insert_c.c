/*
** EPITECH PROJECT, 2024
** test_string_insert_c.c
** File description:
** test_string_insert_c.c
*/

#include "../string.h"

#include <criterion/criterion.h>

Test(insert_c, insert_to_empty)
{
    string_t s;

    string_init(&s, "");
    insert_c(&s, 0, "hello");
    cr_assert_str_eq(s.str, "hello");
}

Test(insert_c, insert_to_empty2)
{
    string_t s;

    string_init(&s, "");
    insert_c(&s, 3, "hello");
    cr_assert_str_eq(s.str, "hello");
}

Test(insert_c, insert)
{
    string_t s;

    string_init(&s, "hello");
    insert_c(&s, 3, "world");
    cr_assert_str_eq(s.str, "helworldlo");
}

Test(insert_c, insert2)
{
    string_t s;

    string_init(&s, "hello");
    insert_c(&s, 8, "world");
    cr_assert_str_eq(s.str, "helloworld");
}

Test(insert_c, null)
{
    string_t s;

    string_init(&s, "");
    insert_c(&s, 0, NULL);
    cr_assert_str_eq(s.str, "");
}

Test(insert_c, null2)
{
    string_t s;

    string_init(&s, NULL);
    insert_c(&s, 0, "test");
    cr_assert_null(s.str);
}
