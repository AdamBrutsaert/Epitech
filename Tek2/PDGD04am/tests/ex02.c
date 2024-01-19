/*
** EPITECH PROJECT, 2024
** ex02.c
** File description:
** ex02.c
*/

#include "../ex02/concat.h"

#include <criterion/criterion.h>

extern void concat_strings(const char *str1, const char *str2, char **res);
extern void concat_struct(concat_t *str);

Test(concat_strings, test1)
{
    char *str1 = "hello";
    char *str2 = " world";
    char *res = NULL;

    concat_strings(str1, str2, &res);
    cr_expect_neq(res, NULL);
    cr_assert_str_eq(res, "hello world");
}

Test(concat_struct, test1)
{
    concat_t concat = {
        .str1 = "hello",
        .str2 = " world",
        .res = NULL
    };

    concat_struct(&concat);
    cr_expect_neq(concat.res, NULL);
    cr_assert_str_eq(concat.res, "hello world");
}
