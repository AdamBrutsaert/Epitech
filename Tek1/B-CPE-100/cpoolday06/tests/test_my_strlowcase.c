/*
** EPITECH PROJECT, 2022
** test_my_strlowcase
** File description:
** Implementation of test_my_strlowcase
*/

#include <criterion/criterion.h>

extern char *my_strlowcase(char *str);

Test(my_strlowcase, uppercase)
{
    char str[] = "SALUT, JE SUIS ADAM! CECI EST UN TEST : *$!@\n";
    char *expected = "salut, je suis adam! ceci est un test : *$!@\n";

    cr_assert_str_eq(my_strlowcase(str), expected);
}

Test(my_strlowcase, empty)
{
    char str[] = "";

    cr_assert_str_eq(my_strlowcase(str), "");
}
