/*
** EPITECH PROJECT, 2023
** gol_run.c
** File description:
** gol_run.c
*/

#include "gameoflife.h"

#include <stdbool.h>

static bool is_empty(gol_t *gol, ssize_t x, ssize_t y)
{
    if (x < 0 || y < 0 || x >= gol->width || y >= gol->height)
        return true;
    return gol->current[y * (gol->width + 1) + x] == '.';
}

static void set(gol_t *gol, ssize_t x, ssize_t y, char character)
{
    gol->next[y * (gol->width + 1) + x] = character;
}

static void process(gol_t *gol, ssize_t x, ssize_t y)
{
    uint8_t count = !is_empty(gol, x - 1, y - 1) + !is_empty(gol, x, y - 1)
                + !is_empty(gol, x + 1, y - 1) + !is_empty(gol, x - 1, y)
                + !is_empty(gol, x + 1, y) + !is_empty(gol, x - 1, y + 1)
                + !is_empty(gol, x, y + 1) + !is_empty(gol, x + 1, y + 1);

    if (is_empty(gol, x, y) && count == 3)
        set(gol, x, y, 'X');
    if (is_empty(gol, x, y) && count != 3)
        set(gol, x, y, '.');
    if (!is_empty(gol, x, y) && (count <= 1 || count >= 4))
        set(gol, x, y, '.');
    if (!is_empty(gol, x, y) && (count == 2 || count == 3))
        set(gol, x, y, 'X');
}

static void iterate(gol_t *gol)
{
    char *current = gol->current;

    for (ssize_t y = 0; y < gol->height; y++) {
        for (ssize_t x = 0; x < gol->width; x++)
            process(gol, x, y);
    }
    gol->current = gol->next;
    gol->next = current;
}

void gol_run(gol_t *gol, uint32_t count)
{
    for (uint32_t i = 0; i < count; i++)
        iterate(gol);
}
