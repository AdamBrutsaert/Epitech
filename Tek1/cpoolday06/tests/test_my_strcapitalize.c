/*
** EPITECH PROJECT, 2022
** test_my_strcapitalize
** File description:
** Implementation of test_my_strcapitalize
*/

#include <criterion/criterion.h>

extern char *my_strcapitalize(char *str);

Test(my_strcapitalize, capitalizing)
{
    char str[] = "hey, how are you? 42WORds forty-two; fifty+one";
    char *expected = "Hey, How Are You? 42words Forty-Two; Fifty+One";

    cr_assert_str_eq(my_strcapitalize(str), expected);
}

Test(my_strcapitalize, empty)
{
    char str[] = "";

    cr_assert_str_eq(my_strcapitalize(str), "");
}
