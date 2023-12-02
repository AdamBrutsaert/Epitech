/*
** EPITECH PROJECT, 2022
** my_advanced_sort_word_array
** File description:
** Implementation of my_advanced_sort_word_array
*/

#include "my.h"
#include <stdio.h>

static void swap_strings(char **s1, char **s2)
{
    char *temp = *s1;

    *s1 = *s2;
    *s2 = temp;
}

static unsigned int find_minimum(
    char **tab, int (*cmp)(char const *, char const *))
{
    unsigned int min_index = 0;

    for (unsigned int i = 0; tab[i]; i++) {
        if (cmp(tab[i], tab[min_index]) < 0)
            min_index = i;
    }
    return min_index;
}

int my_advanced_sort_word_array(
    char **tab, int (*cmp)(char const *, char const *))
{
    for (unsigned int i = 0; tab[i]; i++)
        swap_strings(&tab[i], &tab[i + find_minimum(&tab[i], cmp)]);
    return 0;
}
