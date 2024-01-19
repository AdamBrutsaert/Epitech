/*
** EPITECH PROJECT, 2024
** test_string_join_c.c
** File description:
** test_string_join_c.c
*/

#include "../string.h"

#include <criterion/criterion.h>

Test(join_c, null)
{
    string_t s;
    string_init(&s, NULL);

    join_c(&s, ' ', (const char * const []){"test", "yolo", NULL});
    cr_assert_str_eq(s.str, "test yolo");
}

Test(join_c, replace)
{
    string_t s;
    string_init(&s, "hey");

    join_c(&s, '-', (const char * const []){"yolo", "test", NULL});
    cr_assert_str_eq(s.str, "yolo-test");
}
