/*
** EPITECH PROJECT, 2022
** test_my_str_to_word_array
** File description:
** Implementation of test_my_str_to_word_array
*/

#include <criterion/criterion.h>
#include <string.h>
#include <stdlib.h>

extern char **my_str_to_word_array(char const *str);
extern int my_show_word_array(char *const *tab);

static char str_array_eq(char **arr1, char **arr2)
{
    unsigned int i = 0;

    for (; arr1[i] && arr2[i]; i++) {
        if (strcmp(arr1[i], arr2[i]) != 0)
            return 0;
    }
    if (arr1[i] != arr2[i])
        return 0;
    return 1;
}

static void free_arr(char **arr)
{
    for (unsigned int i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
}

Test(my_str_to_word_array, works)
{
    char **words = my_str_to_word_array("-[t 0Hello~<how are++--you?");
    char *expected[] = { "t", "0Hello", "how", "are", "you", 0 };

    cr_assert(str_array_eq(words, expected));
    free_arr(words);
}

Test(my_str_to_word_array, empty)
{
    char **words = my_str_to_word_array("-?+-,");
    char *expected[] = { 0 };

    cr_assert(str_array_eq(words, expected));
    free_arr(words);
}
