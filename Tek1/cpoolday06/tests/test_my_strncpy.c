/*
** EPITECH PROJECT, 2022
** test_my_strncpy
** File description:
** Implementation of test_my_strncpy
*/

#include <criterion/criterion.h>
#include <string.h>

extern char *my_strncpy(char *dest, char const *src, int n);

Test(my_strncpy, copy_full)
{
    char dest[11];
    char my_dest[11];
    char src[11] = "HelloWorld";

    cr_assert_str_eq(my_strncpy(my_dest, src, 11), strncpy(dest, src, 11));
}

Test(my_strncpy, copy_part)
{
    char dest[6];
    char my_dest[6];
    char src[11] = "HelloWorld";

    dest[5] = '\0';
    my_dest[6] = '\0';
    cr_assert_str_eq(my_strncpy(my_dest, src, 5), strncpy(dest, src, 5));
}

Test(my_strncpy, copy_nothing)
{
    char my_dest[1] = "";
    char src[] = "test";

    cr_assert_str_eq(my_strncpy(my_dest, src, 0), "");
}
