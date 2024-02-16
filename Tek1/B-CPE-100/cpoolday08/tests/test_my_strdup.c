/*
** EPITECH PROJECT, 2022
** test_my_strdup
** File description:
** Implementation of my_strdup
*/

#include <criterion/criterion.h>
#include <stdlib.h>

extern char *my_strdup(char const *src);

Test(my_strdup, copy)
{
    char *src = "Hello, world!";
    char *allocated = my_strdup(src);

    cr_assert_neq(src, allocated);
    cr_assert_str_eq(src, allocated);

    free(allocated);
}
