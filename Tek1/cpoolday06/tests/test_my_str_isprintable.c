/*
** EPITECH PROJECT, 2022
** test_my_str_isprintable
** File description:
** Implementation of test_my_str_isprintable
*/

#include <criterion/criterion.h>

extern int my_str_isprintable(char const *str);

Test(my_str_isprintable, yes)
{
    char str[2] = " ";

    for (char c = 32; c != -128; c++) {
        str[0] = c;
        cr_assert(my_str_isprintable(str));
    }
}

Test(my_str_isprintable, no)
{
    char str[2] = " ";

    for (char c = 1; c < 32; c++) {
        str[0] = c;
        cr_assert(!my_str_isprintable(str));
    }
}
