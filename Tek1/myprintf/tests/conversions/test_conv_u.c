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

Test(my_printf, test_u, .init = redirect_all_std)
{
    int result = my_printf("8 in unsigned is %u", 8);

    cr_assert_stdout_eq_str("8 in unsigned is 8");
    cr_assert_eq(result, 18);
}
