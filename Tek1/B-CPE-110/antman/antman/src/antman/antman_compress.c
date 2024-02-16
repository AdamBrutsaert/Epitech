/*
** EPITECH PROJECT, 2023
** antman_compress.c
** File description:
** antman_compress.c
*/

#include "antman.h"
#include "antman/antman.h"
#include "lz77.h"

int8_t antman_compress(antman_t *antman)
{
    file_t *file = file_create(antman->filepath);

    if (!file)
        return ANTMAN_ERROR;
    if (lz77(file, 255) == 84) {
        file_destroy(file);
        return ANTMAN_ERROR;
    }
    file_destroy(file);
    return ANTMAN_OK;
}
