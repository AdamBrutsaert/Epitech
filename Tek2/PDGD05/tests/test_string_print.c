/*
** EPITECH PROJECT, 2024
** test_string_print.c
** File description:
** test_string_print.c
*/

#include "../string.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(print, null, .init = cr_redirect_stdout)
{
    string_t s;
    string_init(&s, NULL);

    print(&s);
    cr_assert_stdout_eq_str("");
}

Test(print, empty, .init = cr_redirect_stdout)
{
    string_t s;
    string_init(&s, "");

    print(&s);
    cr_assert_stdout_eq_str("");
}

Test(print, hello_world, .init = cr_redirect_stdout)
{
    string_t s;
    string_init(&s, "hello_world");

    print(&s);
    cr_assert_stdout_eq_str("hello_world");
}
