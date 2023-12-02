/*
** EPITECH PROJECT, 2023
** giantman_set_file.c
** File description:
** giantman_set_file.c
*/

#include "giantman.h"
#include "giantman/giantman.h"

void giantman_set_file(giantman_t *giantman, const char *filepath)
{
    giantman->filepath = filepath;
}
