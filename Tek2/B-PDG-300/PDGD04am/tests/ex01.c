/*
** EPITECH PROJECT, 2024
** ex01.c
** File description:
** ex01.c
*/

#include <criterion/criterion.h>

extern void mul_div_long(int a, int b, int *mul, int *div);
extern void mul_div_short(int *a, int *b);

Test(mul_div_long, test1)
{
    int mul = -1;
    int div = -1;

    mul_div_long(13, 4, &mul, &div);
    cr_assert_eq(mul, 52);
    cr_assert_eq(div, 3);
}

Test(mul_div_long, test2)
{
    int mul = -1;
    int div = -1;

    mul_div_long(15, 0, &mul, &div);
    cr_assert_eq(mul, 0);
    cr_assert_eq(div, 42);
}

Test(mul_div_short, test1)
{
    int a = 13;
    int b = 4;

    mul_div_short(&a, &b);
    cr_assert_eq(a, 52);
    cr_assert_eq(b, 3);
}

Test(mul_div_short, test2)
{
    int a = 15;
    int b = 0;

    mul_div_short(&a, &b);
    cr_assert_eq(a, 0);
    cr_assert_eq(b, 42);
}
