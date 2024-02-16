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

Test(my_printf, test_e, .init = redirect_all_std)
{
    int result = my_printf("%e", 0.03);

    cr_assert_stdout_eq_str("3.000000e-02");
    cr_assert_eq(result, 12);
}

Test(my_printf, test_E, .init = redirect_all_std)
{
    int result = my_printf("%E", 0.03);

    cr_assert_stdout_eq_str("3.000000E-02");
    cr_assert_eq(result, 12);
}
