/*
** EPITECH PROJECT, 2024
** test_string_join_s.c
** File description:
** test_string_join_s.c
*/

#include "../string.h"

#include <criterion/criterion.h>

Test(join_s, null)
{
    string_t s;
    string_init(&s, NULL);

    string_t s2;
    string_init(&s2, "test");

    string_t s3;
    string_init(&s3, "yolo");

    join_s(&s, ' ', (const string_t * const []){&s2, &s3, NULL});
    cr_assert_str_eq(s.str, "test yolo");
}

Test(join_s, replace)
{
    string_t s;
    string_init(&s, "hey");

    string_t s2;
    string_init(&s2, "yolo");

    string_t s3;
    string_init(&s3, "test");

    join_s(&s, '-', (const string_t * const []){&s2, &s3, NULL});
    cr_assert_str_eq(s.str, "yolo-test");
}
