/*
** EPITECH PROJECT, 2023
** solver_solve.c
** File description:
** solver_solve.c
*/

#include "solver.h"

#include <stdio.h>

static cell_t *get(solver_t *solver, uint64_t x, uint64_t y)
{
    return &solver->cells[y * solver->width + x];
}

static char cget(solver_t *solver, uint64_t x, uint64_t y)
{
    return solver->map[y * (solver->width + 1) + x];
}

static bool explore2(solver_t *solver, position_t *pos)
{
    if (pos->y != 0 && get(solver, pos->x, pos->y - 1)->visited == UNVISITED
        && cget(solver, pos->x, pos->y - 1) != 'X') {
        get(solver, pos->x, pos->y - 1)->visited = WILL_VISIT;
        get(solver, pos->x, pos->y - 1)->previous = DOWN;
        if (!queue_push(solver->queue, pos->x, pos->y - 1))
            return false;
    }
    if (pos->y + 1 != solver->height
        && get(solver, pos->x, pos->y + 1)->visited == UNVISITED
        && cget(solver, pos->x, pos->y + 1) != 'X') {
        get(solver, pos->x, pos->y + 1)->visited = WILL_VISIT;
        get(solver, pos->x, pos->y + 1)->previous = UP;
        if (!queue_push(solver->queue, pos->x, pos->y + 1))
            return false;
    }
    return true;
}

static bool explore(solver_t *solver)
{
    position_t pos;

    queue_pop(solver->queue, &pos);
    get(solver, pos.x, pos.y)->visited = VISITED;
    if (pos.x != 0 && get(solver, pos.x - 1, pos.y)->visited == UNVISITED
        && cget(solver, pos.x - 1, pos.y) != 'X') {
        get(solver, pos.x - 1, pos.y)->visited = WILL_VISIT;
        get(solver, pos.x - 1, pos.y)->previous = RIGHT;
        if (!queue_push(solver->queue, pos.x - 1, pos.y))
            return false;
    }
    if (pos.x + 1 != solver->width
        && get(solver, pos.x + 1, pos.y)->visited == UNVISITED
        && cget(solver, pos.x + 1, pos.y) != 'X') {
        get(solver, pos.x + 1, pos.y)->visited = WILL_VISIT;
        get(solver, pos.x + 1, pos.y)->previous = LEFT;
        if (!queue_push(solver->queue, pos.x + 1, pos.y))
            return false;
    }
    return explore2(solver, &pos);
}

bool solver_solve(solver_t *solver)
{
    cell_t *last = get(solver, solver->width - 1, solver->height - 1);

    if (!queue_push(solver->queue, 0, 0))
        return false;
    while (last->visited == UNVISITED && solver->queue->length > 0)
        explore(solver);
    if (last->visited != UNVISITED) {
        solver_reconstruct(solver);
        fputs(solver->map, stdout);
    } else {
        fputs("no solution found\n", stdout);
    }
    return true;
}
