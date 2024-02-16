/*
** EPITECH PROJECT, 2023
** giantman_destroy.c
** File description:
** giantman_destroy.c
*/

#include "giantman.h"
#include "giantman/giantman.h"

#include <stdlib.h>

void giantman_destroy(giantman_t *giantman)
{
    free(giantman);
}
