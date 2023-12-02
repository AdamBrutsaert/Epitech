/*
** EPITECH PROJECT, 2023
** giantman_compress.c
** File description:
** giantman_compress.c
*/

#include "giantman.h"
#include "giantman/giantman.h"
#include "lz77.h"

int8_t giantman_uncompress(giantman_t *giantman)
{
    file_t *file = file_create(giantman->filepath);

    if (!file)
        return GIANTMAN_ERROR;
    if (lz77(file, 255) == 84) {
        file_destroy(file);
        return GIANTMAN_ERROR;
    }
    file_destroy(file);
    return GIANTMAN_OK;
}
