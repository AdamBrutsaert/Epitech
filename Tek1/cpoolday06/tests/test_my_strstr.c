/*
** EPITECH PROJECT, 2022
** test_my_strstr
** File description:
** Implementation of my_strstr
*/

#include <criterion/criterion.h>
#include <string.h>

extern char *my_strstr(char *str, char const *to_find);

Test(my_strstr, found)
{
    char *string = "Hello, my name is Adam";
    char *to_find = "is";

    cr_assert_eq(my_strstr(string, to_find), strstr(string, to_find));
}

Test(my_strstr, not_found)
{
    char *string = "yooo man";
    char *to_find = "gigachad";

    cr_assert_eq(my_strstr(string, to_find), strstr(string, to_find));
}

Test(my_strstr, found_empty)
{
    char *string = "Hello, I'm under the water, I need help please help me";
    char *to_find = "";

    cr_assert_eq(my_strstr(string, to_find), strstr(string, to_find));
}
