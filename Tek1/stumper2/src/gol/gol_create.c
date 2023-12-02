/*
** EPITECH PROJECT, 2023
** gol_create.c
** File description:
** gol_create.c
*/

#include "gameoflife.h"
#include "my/memory.h"
#include "my/stdio.h"
#include "my/string.h"

static ssize_t get_width(const char *content)
{
    ssize_t width = 0;

    while (content[width] != '\0' && content[width] != '\n')
        width++;
    return width;
}

static ssize_t get_height(const char *content)
{
    ssize_t height = 0;

    for (; *content != '\0'; content++)
        height += *content == '\n';
    return height;
}

static bool create(gol_t *gol, const char *file)
{
    gol->current = my_readfile(file);
    if (gol->current == NULL) {
        my_eputs("Error: failed to read map.\n");
        return false;
    }
    if (!gol_check_map(gol)) {
        my_eputs("Error: invalid map.\n");
        return false;
    }
    gol->next = my_strdup(gol->current);
    if (gol->next == NULL) {
        my_eputs("Error: failed to allocate\n");
        return false;
    }
    gol->width = get_width(gol->current);
    gol->height = get_height(gol->current);
    return true;
}

gol_t *gol_create(const char *file)
{
    gol_t *gol = my_calloc(sizeof(gol_t));

    if (gol == NULL)
        return NULL;
    if (!create(gol, file)) {
        gol_destroy(gol);
        return NULL;
    }
    return gol;
}
