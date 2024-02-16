/*
** EPITECH PROJECT, 2022
** test_my_getnbr_base
** File description:
** Implementation of test_my_getnbr_base
*/

#include <criterion/criterion.h>

extern int my_getnbr_base(char const *str, char const *base);

Test(my_getnbr_base, decimal)
{
    char *base = "0123456789";

    cr_assert_eq(my_getnbr_base("0", base), 0);
    cr_assert_eq(my_getnbr_base("-5", base), -5);
    cr_assert_eq(my_getnbr_base("9", base), 9);
    cr_assert_eq(my_getnbr_base("-42", base), -42);
    cr_assert_eq(my_getnbr_base("84", base), 84);
    cr_assert_eq(my_getnbr_base("-2147483648", base), -2147483648);
    cr_assert_eq(my_getnbr_base("2147483647", base), 2147483647);
    cr_assert_eq(my_getnbr_base("2147483648", base), 0);
    cr_assert_eq(my_getnbr_base("-2147483649", base), 0);
    cr_assert_eq(my_getnbr_base("--+-+425cd;", base), -425);
}

Test(my_getnbr_base, hex)
{
    char *base = "0123456789abcdef";

    cr_assert_eq(my_getnbr_base("0", base), 0);
    cr_assert_eq(my_getnbr_base("-5", base), -5);
    cr_assert_eq(my_getnbr_base("9", base), 9);
    cr_assert_eq(my_getnbr_base("-2a", base), -42);
    cr_assert_eq(my_getnbr_base("54", base), 84);
    cr_assert_eq(my_getnbr_base("-80000000", base), -2147483648);
    cr_assert_eq(my_getnbr_base("7fffffff", base), 2147483647);
    cr_assert_eq(my_getnbr_base("80000000", base), 0);
    cr_assert_eq(my_getnbr_base("-80000001", base), 0);
    cr_assert_eq(my_getnbr_base("--+-+ffc3g;", base), -65475);
}

Test(my_getnbr_base, binary)
{
    char *base = "01";
    int nb;

    cr_assert_eq(my_getnbr_base("0", base), 0);
    cr_assert_eq(my_getnbr_base("-101", base), -5);
    cr_assert_eq(my_getnbr_base("1001", base), 9);
    cr_assert_eq(my_getnbr_base("-101010", base), -42);
    cr_assert_eq(my_getnbr_base("1010100", base), 84);
    nb = my_getnbr_base("-10000000000000000000000000000000", base);
    cr_assert_eq(nb, -2147483648);
    nb = my_getnbr_base("1111111111111111111111111111111", base);
    cr_assert_eq(nb, 2147483647);
    cr_assert_eq(my_getnbr_base("10000000000000000000000000000000", base), 0);
    cr_assert_eq(my_getnbr_base("-10000000000000000000000000000001", base), 0);
    cr_assert_eq(my_getnbr_base("--+-+1112;", base), -7);
}

Test(my_getnbr_base, invalid_base)
{
    cr_assert_eq(my_getnbr_base("123456", ""), 0);
    cr_assert_eq(my_getnbr_base("0000", "0"), 0);
}
