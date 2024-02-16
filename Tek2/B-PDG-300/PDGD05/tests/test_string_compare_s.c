/*
** EPITECH PROJECT, 2024
** test_string_compare_s.c
** File description:
** test_string_compare_s.c
*/

#include "../string.h"

#include <criterion/criterion.h>

Test(compare_s, return_equal)
{
    string_t s;
    string_t s2;

    string_init(&s, "Hello");
    string_init(&s2, "Hello");

    cr_assert_eq(compare_s(&s, &s2), 0);
}

Test(compare_s, return_equal2)
{
    string_t s;
    string_t s2;

    string_init(&s, NULL);
    string_init(&s2, NULL);
    cr_assert_eq(compare_s(&s, &s2), 0);
}

Test(compare_s, return_low)
{
    string_t s;
    string_t s2;

    string_init(&s, "Hello");
    string_init(&s2, "Helloo");
    cr_assert_leq(compare_s(&s, &s2), -1);
}

Test(compare_s, return_low2)
{
    string_t s;
    string_t s2;

    string_init(&s, "Hello");
    string_init(&s2, "Hellp");
    cr_assert_leq(compare_s(&s, &s2), -1);
}

Test(compare_s, return_low3)
{
    string_t s;
    string_t s2;

    string_init(&s, NULL);
    string_init(&s2, "a");
    cr_assert_leq(compare_s(&s, &s2), -1);
}

Test(compare_s, return_high)
{
    string_t s;
    string_t s2;

    string_init(&s, "Helloo");
    string_init(&s2, "Hello");
    cr_assert_geq(compare_s(&s, &s2), 1);
}

Test(compare_s, return_high2)
{
    string_t s;
    string_t s2;

    string_init(&s, "Hellp");
    string_init(&s2, "Hello");
    cr_assert_geq(compare_s(&s, &s2), 1);
}

Test(compare_s, return_high3)
{
    string_t s;
    string_t s2;

    string_init(&s, "b");
    string_init(&s2, NULL);
    cr_assert_geq(compare_s(&s, &s2), 1);
}

Test(compare_s, return_high4)
{
    string_t s;

    string_init(&s, "b");
    cr_assert_geq(compare_s(&s, NULL), 1);
}
