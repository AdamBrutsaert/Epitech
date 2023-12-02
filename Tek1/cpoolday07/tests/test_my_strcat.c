/*
** EPITECH PROJECT, 2022
** test_my_strcat
** File description:
** Implementation of test_my_strcat
*/

#include <criterion/criterion.h>

extern char *my_strcat(char *dest, char const *src);

Test(my_strcat, works)
{
    char dest[20] = "Hello";

    cr_assert_str_eq(my_strcat(dest, " World!"), "Hello World!");
}

Test(my_strcat, empty)
{
    char dest[20] = "Hey";

    cr_assert_str_eq(my_strcat(dest, ""), "Hey");
}
