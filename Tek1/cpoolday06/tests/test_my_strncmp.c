/*
** EPITECH PROJECT, 2022
** test_my_strncmp
** File description:
** Implementation of my_strncmp
*/

#include <criterion/criterion.h>

int my_strncmp(char const *s1, char const *s2, int n);

Test(my_strncmp, same)
{
    char *s1 = "Hello marvin";
    char *s2 = "Hello someone";

    cr_assert_eq(my_strncmp(s1, s2, 6), 0);
}

Test(my_strncmp, lower)
{
    char *s1 = "Different";
    char *s2 = "Dimmed";

    cr_assert_lt(my_strncmp(s1, s2, 3), 0);
}

Test(my_strncmp, greater)
{
    char *s1 = "Oh my lord";
    char *s2 = "Oh my god";

    cr_assert_gt(my_strncmp(s1, s2, 7), 0);
}

Test(my_strncmp, smaller_string)
{
    char *s1 = "Super";
    char *s2 = "Super saiyan";

    cr_assert_lt(my_strncmp(s1, s2, 10), 0);
}

Test(my_strncmp, empty)
{
    char *s1 = "gbeubguesbgubg";
    char *s2 = "";

    cr_assert_gt(my_strncmp(s1, s2, 5), 0);
}

Test(my_strncmp, nullcomp)
{
    char *s1 = "gesbbg";
    char *s2 = "jneign";

    cr_assert_eq(my_strncmp(s1, s2, 0), 0);
}
