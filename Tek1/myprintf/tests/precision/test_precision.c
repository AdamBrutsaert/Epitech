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

Test(my_printf, test_precision_1, .init = redirect_all_std)
{
    int result = my_printf("%.1f", 0.9375);

    cr_assert_stdout_eq_str("0.9");
    cr_assert_eq(result, 3);
}

Test(my_printf, test_precision_2, .init = redirect_all_std)
{
    int result = my_printf("%.2f", 0.9375);

    cr_assert_stdout_eq_str("0.94");
    cr_assert_eq(result, 4);
}

Test(my_printf, test_precision_2_on_int, .init = redirect_all_std)
{
    int result = my_printf("%.2d", 42);

    cr_assert_stdout_eq_str("42");
    cr_assert_eq(result, 2);
}
