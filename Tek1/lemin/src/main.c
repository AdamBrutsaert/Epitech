/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main.c
*/

#include "lem_in/parser.h"
#include "lem_in.h"

int main(void)
{
    anthill_t *anthill = parse();

    if (anthill == NULL)
        return 84;
    if (!anthill_is_valid(anthill)) {
        anthill_delete(anthill);
        return 84;
    }
    if (!lem_in_solve(anthill)) {
        anthill_delete(anthill);
        return 84;
    }
    anthill_delete(anthill);
    return 0;
}
