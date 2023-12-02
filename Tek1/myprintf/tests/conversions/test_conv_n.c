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

Test(my_printf, test_n, .init = redirect_all_std)
{
    int a = 0;
    int result = my_printf("Hello%n World\n", &a);

    cr_assert_stdout_eq_str("Hello World\n");
    cr_assert_eq(a, 5);
    cr_assert_eq(result, 12);
}
