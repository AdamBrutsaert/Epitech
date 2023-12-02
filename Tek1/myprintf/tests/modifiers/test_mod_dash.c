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

Test(my_printf, test_mod_dash, .init = redirect_all_std)
{
    int result = my_printf("%-10d", 42);

    cr_assert_stdout_eq_str("42        ");
    cr_assert_eq(result, 10);
}

Test(my_printf, test_mod_dash_neg, .init = redirect_all_std)
{
    int result = my_printf("%-10d", -42);

    cr_assert_stdout_eq_str("-42       ");
    cr_assert_eq(result, 10);
}
