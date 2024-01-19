/*
** EPITECH PROJECT, 2024
** ex07.c
** File description:
** ex07.c
*/

#include "map.h"

#include <stdlib.h>

void map_clear(map_t **map_ptr)
{
    for (list_t *node = *map_ptr; node != NULL; node = node->next)
        free(node->value);
    list_clear(map_ptr);
}
