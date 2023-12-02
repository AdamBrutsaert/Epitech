/*
** EPITECH PROJECT, 2022
** test_miniprintf
** File description:
** Implementation of test_miniprintf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../miniprintf.h"

Test(mini_printf, simple, .init = cr_redirect_stdout)
{
    int ret = mini_printf("Hello, world!");

    cr_assert_stdout_eq_str("Hello, world!");
    cr_assert_eq(ret, 13);
}

Test(mini_printf, string, .init = cr_redirect_stdout)
{
    int ret = mini_printf("%s %   d %i %c %%!", "Hello", -2147483648, 0, 'A');

    cr_assert_stdout_eq_str("Hello -2147483648 0 A %!");
    cr_assert_eq(ret, 24);
}

Test(mini_printf, error, .init = cr_redirect_stdout)
{
    int ret = mini_printf("%b", 8);

    cr_assert_lt(ret, 0);
}
