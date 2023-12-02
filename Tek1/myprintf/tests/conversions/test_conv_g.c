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

Test(my_printf, test_g_float, .init = redirect_all_std)
{
    int result = my_printf("%g", 4.5);

    cr_assert_stdout_eq_str("4.5");
    cr_assert_eq(result, 3);
}

Test(my_printf, test_G_float, .init = redirect_all_std)
{
    int result = my_printf("%G", 4.5);

    cr_assert_stdout_eq_str("4.5");
    cr_assert_eq(result, 3);
}

Test(my_printf, test_g_e, .init = redirect_all_std)
{
    int result = my_printf("%g", 1.79e30);

    cr_assert_stdout_eq_str("1.79e+30");
    cr_assert_eq(result, 8);
}

Test(my_printf, test_G_e, .init = redirect_all_std)
{
    int result = my_printf("%G", 1.79e308);

    cr_assert_stdout_eq_str("1.79E+308");
    cr_assert_eq(result, 9);
}
