/*
** EPITECH PROJECT, 2023
** solver_reconstruct.c
** File description:
** solver_reconstruct.c
*/

#include "solver.h"

void construct_and_next(solver_t *solver, position_t *pos)
{
    solver->map[pos->y * (solver->width + 1) + pos->x] = 'o';

    if (pos->x == 0 && pos->y == 0)
        return;
    switch (solver->cells[pos->y * solver->width + pos->x].previous) {
    case DOWN:
        pos->y++;
        break;
    case UP:
        pos->y--;
        break;
    case LEFT:
        pos->x--;
        break;
    case RIGHT:
        pos->x++;
        break;
    }
}

void solver_reconstruct(solver_t *solver)
{
    position_t pos = { solver->width - 1, solver->height - 1};

    while (!(pos.x == 0 && pos.y == 0))
        construct_and_next(solver, &pos);
    construct_and_next(solver, &pos);
}
