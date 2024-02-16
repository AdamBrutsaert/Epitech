/*
** EPITECH PROJECT, 2022
** test_my_str_isnum
** File description:
** Implementation of test_my_str_isnum
*/

#include <criterion/criterion.h>

extern int my_str_isnum(char const *str);

Test(my_str_isnum, yes)
{
    cr_assert(my_str_isnum("0123456789"));
    cr_assert(my_str_isnum(""));
}

Test(my_str_isnum, no)
{
    cr_assert(!my_str_isnum("0123 4567"));
    cr_assert(!my_str_isnum("01523a."));
    cr_assert(!my_str_isnum("4879^"));
}
