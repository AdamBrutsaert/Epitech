/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main.c
*/

#include "solver.h"

#include <stddef.h>

int main(int argc, char **argv)
{
    solver_t *solver;

    if (argc != 2)
        return 84;
    solver = solver_create(argv[1]);
    if (solver == NULL)
        return 84;
    solver_solve(solver);
    solver_destroy(solver);
    return 0;
}
