/*
** EPITECH PROJECT, 2022
** my_putnbr_base
** File description:
** Implementation of test_my_putnbr_base
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

static char is_empty(FILE* file)
{
    return fgetc(file) == EOF;
}

extern int my_putnbr_base(int nbr, char const *base);

Test(my_putnbr_base, decimal, .init = cr_redirect_stdout)
{
    char *base = "0123456789";

    my_putnbr_base(0, base);
    my_putnbr_base(-5, base);
    my_putnbr_base(9, base);
    my_putnbr_base(42, base);
    my_putnbr_base(-84, base);
    my_putnbr_base(-2147483648, base);
    my_putnbr_base(2147483647, base);
    cr_assert_stdout_eq_str("0" "-5" "9" "42" "-84" "-2147483648" "2147483647");
}

Test(my_putnbr_base, hex, .init = cr_redirect_stdout)
{
    char *base = "0123456789abcdef";

    my_putnbr_base(0, base);
    my_putnbr_base(-5, base);
    my_putnbr_base(9, base);
    my_putnbr_base(42, base);
    my_putnbr_base(-84, base);
    my_putnbr_base(-2147483648, base);
    my_putnbr_base(2147483647, base);
    cr_assert_stdout_eq_str("0" "-5" "9" "2a" "-54" "-80000000" "7fffffff");
}

Test(my_putnbr_base, binary, .init = cr_redirect_stdout)
{
    char *base = "01";

    my_putnbr_base(0, base);
    my_putnbr_base(-5, base);
    my_putnbr_base(9, base);
    my_putnbr_base(42, base);
    my_putnbr_base(-84, base);
    my_putnbr_base(-2147483648, base);
    my_putnbr_base(2147483647, base);
    cr_assert_stdout_eq_str("0" "-101" "1001" "101010" "-1010100" \
                            "-10000000000000000000000000000000" \
                            "1111111111111111111111111111111");
}

Test(my_putnbr_base, invalid_base, .init = cr_redirect_stdout)
{
    char *base = "";

    my_putnbr_base(0, base);
    my_putnbr_base(-5, base);
    my_putnbr_base(9, base);
    my_putnbr_base(42, base);
    my_putnbr_base(-84, base);
    my_putnbr_base(-2147483648, base);
    my_putnbr_base(2147483647, base);
    base = "0";
    my_putnbr_base(0, base);
    my_putnbr_base(-5, base);
    my_putnbr_base(9, base);
    my_putnbr_base(42, base);
    my_putnbr_base(-84, base);
    my_putnbr_base(-2147483648, base);
    my_putnbr_base(2147483647, base);
    cr_assert(is_empty(cr_get_redirected_stdout()));
}
