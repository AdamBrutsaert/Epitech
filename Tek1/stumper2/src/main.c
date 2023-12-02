/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main.c
*/

#include "gameoflife.h"
#include "my/stdio.h"

#include <stdlib.h>
#include <stddef.h>

bool check_number(const char *arg, uint32_t *value)
{
    char *end;

    if (*arg == '\0' || *arg < '0' || *arg > '9')
        return false;
    *value = strtoul(arg, &end, 10);
    return *end == '\0';
}

int main(int argc, char **argv)
{
    gol_t *gol;
    uint32_t iteration;

    if (argc != 3) {
        my_eputs("Usage: ./gameoflife <map> <iteration>\n");
        return 84;
    }
    if (!check_number(argv[2], &iteration)) {
        my_eputs("Error: invalid number\n");
        return 84;
    }
    gol = gol_create(argv[1]);
    if (gol == NULL)
        return 84;
    gol_run(gol, iteration);
    gol_print(gol);
    gol_destroy(gol);
    return 0;
}
