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

Test(my_printf, test_mod_diez_octal, .init = redirect_all_std)
{
    int result = my_printf("%#o", 42);

    cr_assert_stdout_eq_str("052");
    cr_assert_eq(result, 3);
}

Test(my_printf, test_mod_diez_x, .init = redirect_all_std)
{
    int result = my_printf("%#x", 42);

    cr_assert_stdout_eq_str("0x2a");
    cr_assert_eq(result, 4);
}

Test(my_printf, test_mod_diez_X, .init = redirect_all_std)
{
    int result = my_printf("%#X", 42);

    cr_assert_stdout_eq_str("0X2A");
    cr_assert_eq(result, 4);
}
