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

Test (my_printf, test_zero, .init = redirect_all_std)
{
    int result = my_printf("%010d", 42);

    cr_assert_stdout_eq_str("0000000042");
    cr_assert_eq(result, 10);
}

Test (my_printf, test_zero_neg, .init = redirect_all_std)
{
    int result = my_printf("%010d", -42);

    cr_assert_stdout_eq_str("-000000042");
    cr_assert_eq(result, 10);
}

Test (my_printf, test_zero_with_zero, .init = redirect_all_std)
{
    int result = my_printf("%010d", 0);

    cr_assert_stdout_eq_str("0000000000");
    cr_assert_eq(result, 10);
}
