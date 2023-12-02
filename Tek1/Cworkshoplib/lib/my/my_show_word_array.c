/*
** EPITECH PROJECT, 2022
** my_show_word_array
** File description:
** Implementation of my_show_word_array
*/

#include "my.h"

int my_show_word_array(char *const *tab)
{
    for (; *tab; tab++) {
        my_putstr(*tab);
        my_putchar('\n');
    }
    return 0;
}
