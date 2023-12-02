/*
** EPITECH PROJECT, 2023
** my_strarrfree.c
** File description:
** my_strarrfree.c
*/

#include "my/string.h"

#include <stdlib.h>

void my_strarrfree(char **array)
{
    for (uint64_t i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}
