/*
** EPITECH PROJECT, 2024
** free_args_array.c
** File description:
** free_args_array.c
*/

#include "utils/parsing.h"

#include <stdlib.h>

void free_args_array(char **array)
{
    if (array == NULL)
        return;
    for (size_t i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}
