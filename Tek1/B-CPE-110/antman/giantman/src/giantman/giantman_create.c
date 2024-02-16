/*
** EPITECH PROJECT, 2023
** giantman_create.c
** File description:
** giantman_create.c
*/

#include "giantman.h"
#include "giantman/giantman.h"

#include <stdlib.h>

giantman_t *giantman_create(void)
{
    giantman_t *giantman = malloc(sizeof(giantman_t));

    if (giantman == NULL)
        return NULL;
    giantman->type = NONE;
    giantman->filepath = NULL;
    return giantman;
}
