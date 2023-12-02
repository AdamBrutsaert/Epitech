/*
** EPITECH PROJECT, 2022
** test_my_strcpy.c
** File description:
** Implementation of test_my_strcpy.c
*/

#include <criterion/criterion.h>
#include <string.h>

extern char *my_strcpy(char *dest, char const *src);

Test(my_strcpy, copy)
{
    char dest[11];
    char my_dest[11];
    char src[11] = "HelloWorld";

    cr_assert_str_eq(my_strcpy(my_dest, src), strcpy(dest, src));
}

Test(my_strcpy, empty)
{
    char dest[1];
    char my_dest[1];
    char src[1] = "";

    cr_assert_str_eq(my_strcpy(my_dest, src), strcpy(dest, src));
}
