/*
** EPITECH PROJECT, 2024
** test_vec.c
** File description:
** test_vec.c
*/

#include "my/memory/string.h"

#include <criterion/criterion.h>

Test(string, create_from_cstr)
{
    string_t *string = string_create_from_cstr("Hello, world!");

    cr_assert_eq(STRING_LEN(string), 13);
    cr_assert_str_eq(STRING_DATA(string), "Hello, world!");
    cr_assert_eq(STRING_AT(string, 0), 'H');
    cr_assert_eq(STRING_AT(string, 1), 'e');
    cr_assert_eq(STRING_AT(string, 2), 'l');
    cr_assert_eq(STRING_AT(string, 3), 'l');
    cr_assert_eq(STRING_AT(string, 4), 'o');
    cr_assert_eq(STRING_AT(string, 5), ',');
    cr_assert_eq(STRING_AT(string, 6), ' ');
    cr_assert_eq(STRING_AT(string, 7), 'w');
    cr_assert_eq(STRING_AT(string, 8), 'o');
    cr_assert_eq(STRING_AT(string, 9), 'r');
    cr_assert_eq(STRING_AT(string, 10), 'l');
    cr_assert_eq(STRING_AT(string, 11), 'd');
    cr_assert_eq(STRING_AT(string, 12), '!');
    cr_assert_eq(STRING_AT(string, 13), '\0');

    string_destroy(string);
}

Test(string, create_from_buffer)
{
    string_t *string = string_create_from_buffer("Hello, world!", 13);

    cr_assert_eq(STRING_LEN(string), 13);
    cr_assert_str_eq(STRING_DATA(string), "Hello, world!");
    cr_assert_eq(STRING_AT(string, 0), 'H');
    cr_assert_eq(STRING_AT(string, 1), 'e');
    cr_assert_eq(STRING_AT(string, 2), 'l');
    cr_assert_eq(STRING_AT(string, 3), 'l');
    cr_assert_eq(STRING_AT(string, 4), 'o');
    cr_assert_eq(STRING_AT(string, 5), ',');
    cr_assert_eq(STRING_AT(string, 6), ' ');
    cr_assert_eq(STRING_AT(string, 7), 'w');
    cr_assert_eq(STRING_AT(string, 8), 'o');
    cr_assert_eq(STRING_AT(string, 9), 'r');
    cr_assert_eq(STRING_AT(string, 10), 'l');
    cr_assert_eq(STRING_AT(string, 11), 'd');
    cr_assert_eq(STRING_AT(string, 12), '!');
    cr_assert_eq(STRING_AT(string, 13), '\0');

    string_destroy(string);
}

Test(string, compare)
{
    string_t *string1 = string_create_from_cstr("Hello, world!");
    string_t *string2 = string_create_from_cstr("Hello, world!");

    cr_assert_eq(string_compare(string1, string2), 0);

    string_destroy(string1);
    string_destroy(string2);
    string1 = string_create_from_cstr("Hello, world!");
    string2 = string_create_from_cstr("Hello, people!");
    cr_assert_gt(string_compare(string1, string2), 0);
    cr_assert_lt(string_compare(string2, string1), 0);

    string_destroy(string1);
    string_destroy(string2);
}

Test(string, insert)
{
    string_t *string = string_create_from_cstr("Hello!");
    string_t *other = string_create_from_cstr(", world");

    string_insert(string, 5, other);
    cr_assert_eq(STRING_LEN(string), 13);
    cr_assert_str_eq(STRING_DATA(string), "Hello, world!");

    string_destroy(other);
    other = string_create_from_cstr("test");
    string_insert(string, 13, other);
    cr_assert_eq(STRING_LEN(string), 17);
    cr_assert_str_eq(STRING_DATA(string), "Hello, world!test");

    string_insert(string, 18, other);
    cr_assert_eq(STRING_LEN(string), 21);
    cr_assert_str_eq(STRING_DATA(string), "Hello, world!testtest");

    string_destroy(string);
    string_destroy(other);
}

Test(string, remove)
{
    string_t *string = string_create_from_cstr("Hello, world!");

    string_remove(string, 5, 7);
    cr_assert_eq(STRING_LEN(string), 6);
    cr_assert_str_eq(STRING_DATA(string), "Hello!");

    string_remove(string, 6, 2);
    cr_assert_eq(STRING_LEN(string), 6);
    cr_assert_str_eq(STRING_DATA(string), "Hello!");

    string_remove(string, 5, 1);
    cr_assert_eq(STRING_LEN(string), 5);
    cr_assert_str_eq(STRING_DATA(string), "Hello");

    string_remove(string, 2, 10);
    cr_assert_eq(STRING_LEN(string), 2);
    cr_assert_str_eq(STRING_DATA(string), "He");

    string_remove(string, 0, 10);
    cr_assert_eq(STRING_LEN(string), 0);
    cr_assert_str_eq(STRING_DATA(string), "");

    string_destroy(string);
}

Test(string, contains_char)
{
    string_t *string = string_create_from_cstr("Hello, world!");

    cr_assert(string_contains_char(string, 'H'));
    cr_assert(string_contains_char(string, 'e'));
    cr_assert(string_contains_char(string, 'l'));
    cr_assert(string_contains_char(string, 'o'));
    cr_assert(string_contains_char(string, ','));
    cr_assert(string_contains_char(string, ' '));
    cr_assert(string_contains_char(string, 'w'));
    cr_assert(string_contains_char(string, 'r'));
    cr_assert(string_contains_char(string, 'd'));
    cr_assert(string_contains_char(string, '!'));

    cr_assert_not(string_contains_char(string, 'h'));
    cr_assert_not(string_contains_char(string, 'a'));
    cr_assert_not(string_contains_char(string, 'b'));
    cr_assert_not(string_contains_char(string, 'c'));
    cr_assert_not(string_contains_char(string, 'f'));
    cr_assert_not(string_contains_char(string, 'g'));

    string_destroy(string);
}

Test(string, split)
{
    string_t *string = string_create_from_cstr("fbesuf,tesge,gfes");

    vec_t *vec = string_split(string, ',');
    cr_assert_eq(VEC_LEN(vec), 3);
    cr_assert_str_eq(STRING_DATA(*(string_t **)VEC_AT(vec, 0)), "fbesuf");
    cr_assert_str_eq(STRING_DATA(*(string_t **)VEC_AT(vec, 1)), "tesge");
    cr_assert_str_eq(STRING_DATA(*(string_t **)VEC_AT(vec, 2)), "gfes");

    string_destroy_vec(vec);
    string_destroy(string);
}

Test(string, split_escaped)
{
    string_t *string = string_create_from_cstr("fbe\\suf,tesge\\,gfes,yolo\\\\");

    vec_t *vec = string_split_escaped(string, ',');
    cr_assert_eq(VEC_LEN(vec), 3);
    cr_assert_str_eq(STRING_DATA(*(string_t **)VEC_AT(vec, 0)), "fbe\\suf");
    cr_assert_str_eq(STRING_DATA(*(string_t **)VEC_AT(vec, 1)), "tesge,gfes");
    cr_assert_str_eq(STRING_DATA(*(string_t **)VEC_AT(vec, 2)), "yolo\\\\");

    string_destroy_vec(vec);
    string_destroy(string);
}

Test(string, escape)
{
    string_t *string = string_create_from_cstr("fbesuf,tesge,gfes,yolo");

    string_escape(string, ',');
    cr_assert_eq(STRING_LEN(string), 25);
    cr_assert_str_eq(STRING_CDATA(string), "fbesuf\\,tesge\\,gfes\\,yolo");

    string_destroy(string);
}
