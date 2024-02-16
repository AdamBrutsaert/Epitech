/*
** EPITECH PROJECT, 2022
** concat_params
** File description:
** Implementation of concat_params
*/

#include <criterion/criterion.h>

extern char *concat_params(int argc, char **argv);

Test(concat_params, concat)
{
    char *argv[3] = {
        "hello",
        "world",
        "how are you?"
    };
    char *params = concat_params(3, argv);

    cr_assert_str_eq(params, "hello\nworld\nhow are you?");
    free(params);
}

Test(concat_params, empty)
{
    char *params = concat_params(0, (char**)0);

    cr_assert_eq(params, 0);
    free(params);
}
