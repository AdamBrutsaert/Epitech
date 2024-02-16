/*
** EPITECH PROJECT, 2024
** test_string_copy.c
** File description:
** test_string_copy.c
*/

#include "../string.h"

#include <criterion/criterion.h>

Test(copy, marvin1)
{
    string_t s;
    char str[10] = {0};

    string_init(&s, "My strin");
    cr_assert_eq(s.copy(&s, str, 9, 0), 9);

    cr_assert_arr_eq(str, "My strin", 9);
}

Test(copy, marvin2)
{
    string_t s;
    char str[10] = {0};

    string_init(&s, "pierre");
    cr_assert_eq(s.copy(&s, str, 9, 0), 7);

    cr_assert_arr_eq(str, "pierre", 7);
}

Test(copy, overflow)
{
    string_t s;
    char str[10] = {0};

    string_init(&s, "pierre");
    cr_assert_eq(s.copy(&s, str, 9, 1), 6);

    cr_assert_arr_eq(str, "ierre", 6);
}
