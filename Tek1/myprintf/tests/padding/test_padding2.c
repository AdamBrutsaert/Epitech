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

Test(my_printf, test_padding_on_char, .init = redirect_all_std)
{
    int result = my_printf("%5c", 'a');

    cr_assert_stdout_eq_str("    a");
    cr_assert_eq(result, 5);
}

Test(my_printf, test_padding_on_char_l_adjusted, .init = redirect_all_std)
{
    int result = my_printf("%-5c", 'a');

    cr_assert_stdout_eq_str("a    ");
    cr_assert_eq(result, 5);
}

Test(my_printf, test_padding_on_char_zero, .init = redirect_all_std)
{
    int result = my_printf("%05c", 'a');

    cr_assert_stdout_eq_str("    a");
    cr_assert_eq(result, 5);
}

Test(my_printf, test_padding_on_char_2, .init = redirect_all_std)
{
    int result = my_printf("%5.4s", "Hello world!");

    cr_assert_stdout_eq_str(" Hell");
    cr_assert_eq(result, 5);
}
