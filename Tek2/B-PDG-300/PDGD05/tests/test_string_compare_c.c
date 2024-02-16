/*
** EPITECH PROJECT, 2024
** test_string_compare_c.c
** File description:
** test_string_compare_c.c
*/

#include "../string.h"

#include <criterion/criterion.h>

Test(compare_c, return_equal)
{
    string_t s;

    string_init(&s, "Hello");
    cr_assert_eq(compare_c(&s, "Hello"), 0);
}

Test(compare_c, return_equal2)
{
    string_t s;

    string_init(&s, NULL);
    cr_assert_eq(compare_c(&s, NULL), 0);
}

Test(compare_c, return_low)
{
    string_t s;

    string_init(&s, "Hello");
    cr_assert_leq(compare_c(&s, "Helloo"), -1);
}

Test(compare_c, return_low2)
{
    string_t s;

    string_init(&s, "Hello");
    cr_assert_leq(compare_c(&s, "Hellp"), -1);
}

Test(compare_c, return_low3)
{
    string_t s;

    string_init(&s, NULL);
    cr_assert_leq(compare_c(&s, "a"), -1);
}

Test(compare_c, return_high)
{
    string_t s;

    string_init(&s, "Helloo");
    cr_assert_geq(compare_c(&s, "Hello"), 1);
}

Test(compare_c, return_high2)
{
    string_t s;

    string_init(&s, "Hellp");
    cr_assert_geq(compare_c(&s, "Hello"), 1);
}

Test(compare_c, return_high3)
{
    string_t s;

    string_init(&s, "b");
    cr_assert_geq(compare_c(&s, NULL), 1);
}
