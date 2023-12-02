/*
** EPITECH PROJECT, 2023
** solver_destroy.c
** File description:
** solver_destroy.c
*/

#include "solver.h"

#include <stdlib.h>

void solver_destroy(solver_t *solver)
{
    if (solver->queue)
        queue_destroy(solver->queue);
    free(solver->cells);
    free(solver->map);
    free(solver);
}
