/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** Implementation of my_revstr
*/

#include <criterion/criterion.h>

extern char *my_revstr(char *str);

Test(my_revstr, even_length)
{
    char str[] = "abcd";

    cr_assert_str_eq(my_revstr(str), "dcba");
}

Test(my_revstr, odd_length)
{
    char str[] = "abcde";

    cr_assert_str_eq(my_revstr(str), "edcba");
}

Test(my_revstr, empty)
{
    char str[] = "";

    cr_assert_str_eq(my_revstr(str), "");
}
