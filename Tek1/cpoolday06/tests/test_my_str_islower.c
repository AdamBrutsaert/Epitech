/*
** EPITECH PROJECT, 2022
** test_my_str_islower
** File description:
** Implementation of test_my_str_islower
*/

#include <criterion/criterion.h>

extern int my_str_islower(char const *str);

Test(my_str_islower, yes)
{
    cr_assert(my_str_islower("abcdefghiklmnopqrstuvwxyz"));
    cr_assert(my_str_islower(""));
}

Test(my_str_islower, no)
{
    cr_assert(!my_str_islower("salutàTous"));
    cr_assert(!my_str_islower("salut."));
    cr_assert(!my_str_islower("salut^"));
}
