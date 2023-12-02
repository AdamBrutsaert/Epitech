/*
** EPITECH PROJECT, 2022
** test_my_str_isupper
** File description:
** Implementation of test_my_str_isupper
*/

#include <criterion/criterion.h>

extern int my_str_isupper(char const *str);

Test(my_str_isupper, yes)
{
    cr_assert(my_str_isupper("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
    cr_assert(my_str_isupper(""));
}

Test(my_str_isupper, no)
{
    cr_assert(!my_str_isupper("SALUTaTOUS"));
    cr_assert(!my_str_isupper("SALUT."));
    cr_assert(!my_str_isupper("SALUT^"));
}
