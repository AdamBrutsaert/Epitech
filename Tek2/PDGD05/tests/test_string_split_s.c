/*
** EPITECH PROJECT, 2024
** test_string_split_c.c
** File description:
** test_string_split_c.c
*/

#include "../string.h"

#include <criterion/criterion.h>

static size_t arraylen(string_t **arr)
{
    size_t length = 0;

    while (arr[length] != NULL)
        length++;
    return length;
}

Test(split_s, empty)
{
    string_t s;
    string_init(&s, NULL);

    cr_assert_eq(split_s(&s, ' '), NULL);
}

Test(split_s, one_word)
{
    string_t str;
    string_init(&str, "salut");

    string_t **split = split_s(&str, ' ');

    cr_assert_str_eq(split[0]->str, "salut");
    cr_assert_eq(arraylen(split), 1);
}

Test(split_s, five_words)
{
    string_t str;
    string_init(&str, "salut  c'est pas moi");

    string_t **split = split_s(&str, ' ');

    cr_assert_str_eq(split[0]->str, "salut");
    cr_assert_str_eq(split[1]->str, "");
    cr_assert_str_eq(split[2]->str, "c'est");
    cr_assert_str_eq(split[3]->str, "pas");
    cr_assert_str_eq(split[4]->str, "moi");
    cr_assert_eq(arraylen(split), 5);
}
