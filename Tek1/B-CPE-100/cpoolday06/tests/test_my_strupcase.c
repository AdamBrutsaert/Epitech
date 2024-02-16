/*
** EPITECH PROJECT, 2022
** test_my_strupcase
** File description:
** Implementation of test_my_strupcase
*/

#include <criterion/criterion.h>

extern char *my_strupcase(char *str);

Test(my_strupcase, uppercase)
{
    char str[] = "Salut, je suis Adam! Ceci est un test : *$!@\n";
    char *expected = "SALUT, JE SUIS ADAM! CECI EST UN TEST : *$!@\n";

    cr_assert_str_eq(my_strupcase(str), expected);
}

Test(my_strupcase, empty)
{
    char str[] = "";

    cr_assert_str_eq(my_strupcase(str), "");
}
