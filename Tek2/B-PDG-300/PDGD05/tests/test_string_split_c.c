/*
** EPITECH PROJECT, 2024
** test_string_split_c.c
** File description:
** test_string_split_c.c
*/

#include "../string.h"

#include <criterion/criterion.h>

static size_t arraylen(char **arr)
{
    size_t length = 0;

    while (arr[length] != NULL)
        length++;
    return length;
}

Test(split_c, empty)
{
    string_t s;
    string_init(&s, NULL);

    cr_assert_eq(split_c(&s, ' '), NULL);
}

Test(split_c, one_word)
{
    string_t str;
    string_init(&str, "salut");

    char **split = split_c(&str, ' ');

    cr_assert_str_eq(split[0], "salut");
    cr_assert_eq(arraylen(split), 1);
}

Test(split_c, five_words)
{
    string_t str;
    string_init(&str, "salut  c'est pas moi");

    char **split = split_c(&str, ' ');

    cr_assert_str_eq(split[0], "salut");
    cr_assert_str_eq(split[1], "");
    cr_assert_str_eq(split[2], "c'est");
    cr_assert_str_eq(split[3], "pas");
    cr_assert_str_eq(split[4], "moi");
    cr_assert_eq(arraylen(split), 5);
}
