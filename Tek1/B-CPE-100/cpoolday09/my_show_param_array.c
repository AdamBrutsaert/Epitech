/*
** EPITECH PROJECT, 2022
** my_show_param_array
** File description:
** Implementation of my_show_param_array
*/

#include "my.h"

int my_show_param_array(struct info_param const *par)
{
    for (; par->str; par++) {
        my_putstr(par->str);
        my_putchar('\n');
        my_put_nbr(par->length);
        my_putchar('\n');
        my_show_word_array(par->word_array);
    }
    return 0;
}
