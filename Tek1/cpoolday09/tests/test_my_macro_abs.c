/*
** EPITECH PROJECT, 2022
** test_my_macro_abs
** File description:
** Implementation of test_my_macro_abs
*/

#include <criterion/criterion.h>
#include "../include/my_macro_abs.h"

Test(my_macro_abs, abs)
{
    cr_assert_eq(ABS(-1), 1);
    cr_assert_eq(ABS(1), 1);
    cr_assert_eq(ABS(0), 0);
    cr_assert_eq(ABS(0 - 8), 8);
    cr_assert_eq(ABS(-32 * 7), 224);
}
