/*
** EPITECH PROJECT, 2022
** test_my_strcat
** File description:
** Implementation of test_my_strcat
*/

#include <criterion/criterion.h>

extern char *my_strncat(char *dest, char const *src, int nb);

Test(my_strncat, works)
{
    char dest[20] = "Hello";

    cr_assert_str_eq(my_strncat(dest, " World!", 8), "Hello World!");
}

Test(my_strncat, null)
{
    char dest[20] = "Hey";

    cr_assert_str_eq(my_strncat(dest, "yyyy", 0), "Hey");
}
