/*
** EPITECH PROJECT, 2022
** test_my_show_word_array
** File description:
** Implementation of test_my_show_word_array.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

extern int my_show_word_array(char *const *tab);

Test(my_show_word_array, print, .init = cr_redirect_stdout)
{
    char *tab[] = {
        "Will", "the", "test", "work?", 0
    };

    my_show_word_array(tab);
    cr_assert_stdout_eq_str("Will\nthe\ntest\nwork?\n");
}
