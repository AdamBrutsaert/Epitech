/*
** EPITECH PROJECT, 2024
** test_string_insert_s.c
** File description:
** test_string_insert_s.c
*/

#include "../string.h"

#include <criterion/criterion.h>


Test(insert_s, insert_to_empty)
{
    string_t s;
    string_t s2;

    string_init(&s, "");
    string_init(&s2, "hello");
    insert_s(&s, 0, &s2);
    cr_assert_str_eq(s.str, "hello");
}

Test(insert_s, insert_to_empty2)
{
    string_t s;
    string_t s2;

    string_init(&s, "");
    string_init(&s2, "hello");
    insert_s(&s, 3, &s2);
    cr_assert_str_eq(s.str, "hello");
}

Test(insert_s, insert)
{
    string_t s;
    string_t s2;

    string_init(&s, "hello");
    string_init(&s2, "world");
    insert_s(&s, 3, &s2);
    cr_assert_str_eq(s.str, "helworldlo");
}

Test(insert_s, insert2)
{
    string_t s;
    string_t s2;

    string_init(&s, "hello");
    string_init(&s2, "world");
    insert_s(&s, 8, &s2);
    cr_assert_str_eq(s.str, "helloworld");
}

Test(insert_s, null)
{
    string_t s;
    string_t s2;

    string_init(&s, "");
    string_init(&s2, NULL);
    insert_s(&s, 0, &s2);
    cr_assert_str_eq(s.str, "");
}

Test(insert_s, null2)
{
    string_t s;
    string_t s2;

    string_init(&s, NULL);
    string_init(&s2, "test");
    insert_s(&s, 0, &s2);
    cr_assert_null(s.str);
}

Test(insert_s, null3)
{
    string_t s;

    string_init(&s, NULL);
    insert_s(&s, 0, NULL);
    cr_assert_null(s.str);
}
