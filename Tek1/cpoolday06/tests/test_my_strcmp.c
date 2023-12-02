/*
** EPITECH PROJECT, 2022
** test_my_strcmp
** File description:
** Implementation of my_strcmp
*/

#include <criterion/criterion.h>

extern int my_strcmp(char const *s1, char const *s2);

Test(my_strcmp, same)
{
    char *s1 = "Hello";
    char *s2 = "Hello";

    cr_assert_eq(my_strcmp(s1, s2), 0);
}

Test(my_strcmp, lower)
{
    char *s1 = "Different";
    char *s2 = "Dimmed";

    cr_assert_lt(my_strcmp(s1, s2), 0);
}

Test(my_strcmp, greater)
{
    char *s1 = "Oh my lord";
    char *s2 = "Oh my god";

    cr_assert_gt(my_strcmp(s1, s2), 0);
}

Test(my_strcmp, same_beginning)
{
    char *s1 = "Super";
    char *s2 = "Super saiyan";

    cr_assert_lt(my_strcmp(s1, s2), 0);
}

Test(my_strcmp, empty)
{
    char *s1 = "gbeubguesbgubg";
    char *s2 = "";

    cr_assert_gt(my_strcmp(s1, s2), 0);
}
