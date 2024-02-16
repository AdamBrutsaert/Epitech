/*
** EPITECH PROJECT, 2024
** test_string_find_c.c
** File description:
** test_string_find_c.c
*/

#include "../string.h"

#include <criterion/criterion.h>

Test(find_c, does_find)
{
    string_t s;

    string_init(&s, "Hello");
    cr_assert_eq(s.find_c(&s, "llo", 0), 2);
}

Test(find_c, does_find2)
{
    string_t s;

    string_init(&s, "Hello");
    cr_assert_eq(s.find_c(&s, "", 1), 1);
}

Test(find_c, does_find3)
{
    string_t s;

    string_init(&s, "Hello, world! How are you today ?");
    cr_assert_eq(s.find_c(&s, "you", 3), 22);
}

Test(find_c, does_not_find0)
{
    string_t s;

    string_init(&s, "World");
    cr_assert_eq(s.find_c(&s, "Hello", 0), -1);
}

Test(find_c, does_not_find1)
{
    string_t s;

    string_init(&s, "Hello");
    cr_assert_eq(s.find_c(&s, "llo", 3), -1);
}

Test(find_c, does_not_find2)
{
    string_t s;

    string_init(&s, NULL);
    cr_assert_eq(s.find_c(&s, "llo", 3), -1);
}

Test(find_c, does_not_find3)
{
    string_t s;

    string_init(&s, "Hello");
    cr_assert_eq(s.find_c(&s, NULL, 0), -1);
}
