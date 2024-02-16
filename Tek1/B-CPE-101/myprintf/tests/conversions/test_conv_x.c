/*
** EPITECH PROJECT, 2022
** Test my_printf
** File description:
** Test my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, test_x, .init = redirect_all_std)
{
    int result = my_printf("210 in hexadecimal is %x", 210);

    cr_assert_stdout_eq_str("210 in hexadecimal is d2");
    cr_assert_eq(result, 24);
}

Test(my_printf, test_X, .init = redirect_all_std)
{
    int result = my_printf("210 in hexadecimal is %X", 210);

    cr_assert_stdout_eq_str("210 in hexadecimal is D2");
    cr_assert_eq(result, 24);
}
