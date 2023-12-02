/*
** EPITECH PROJECT, 2022
** test_my_str_isalpha
** File description:
** Implementation of test_my_str_isalpha
*/

#include <criterion/criterion.h>

extern int my_str_isalpha(char const *str);

Test(my_str_isalpha, yes)
{
    cr_assert(my_str_isalpha("gbuebguiebsiguesi"));
    cr_assert(my_str_isalpha(""));
}

Test(my_str_isalpha, no)
{
    cr_assert(!my_str_isalpha("test test"));
    cr_assert(!my_str_isalpha("test."));
    cr_assert(!my_str_isalpha("test^"));
}
