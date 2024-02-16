/*
** EPITECH PROJECT, 2022
** test_convert_base
** File description:
** Implementation of convert_base
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include <string.h>

char *convert_base(char const *nbr, char const *base_from, char const *base_to);

Test(convert_base, decimal_to_binary)
{
    char *base_from = "0123456789";
    char *base_to = "01";
    char *nbs[] = {
        "0", "4", "-9", "42", "-84", "2147483647", "-2147483648"
    };
    char *expected[] = {
        "0", "100", "-1001", "101010", "-1010100",
        "1111111111111111111111111111111",
        "-10000000000000000000000000000000"
    };
    char *result;

    for (unsigned int i = 0; i < 7; i++) {
        result = convert_base(nbs[i], base_from, base_to);
        cr_assert_str_eq(result, expected[i]);
        free(result);
    }
}

Test(convert_base, binary_to_hex)
{
    char *base_from = "01";
    char *base_to = "0123456789ABCDEF";
    char *nbs[] = {
        "0", "100", "-1001", "101010", "-1010100",
        "1111111111111111111111111111111",
        "-10000000000000000000000000000000"
    };
    char *expected[] = {
        "0", "4", "-9", "2A", "-54", "7FFFFFFF", "-80000000"
    };
    char *result;

    for (unsigned int i = 0; i < 7; i++) {
        result = convert_base(nbs[i], base_from, base_to);
        cr_assert_str_eq(result, expected[i]);
        free(result);
    }
}
