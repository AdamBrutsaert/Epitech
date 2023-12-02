/*
** EPITECH PROJECT, 2023
** solver_create.c
** File description:
** solver_create.c
*/

#include "solver.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static char *read_file(char const *file)
{
    uint64_t size;
    char *string;

    FILE *f = fopen(file, "rb");
    if (f == NULL)
        return NULL;
    fseek(f, 0, SEEK_END);
    size = ftell(f);
    if (size == 0)
        return NULL;
    fseek(f, 0, SEEK_SET);
    string = malloc(size + 1);
    if (!string)
        return NULL;
    fread(string, size, 1, f);
    fclose(f);
    string[size] = '\0';
    return string;
}

static bool compute_size_internal(solver_t *solver, char c, bool *first_line,
    uint64_t *current_width)
{
    if (*first_line && c == '\n')
        *first_line = false;
    if (*first_line && c != '\n')
        solver->width++;
    if (c != '\n')
        (*current_width)++;
    if (c == '\n') {
        solver->height++;
        if (*current_width != solver->width)
            return false;
        *current_width = 0;
    }
    if (c != '*' && c != 'X'
        && c != '\n')
        return false;
    return true;
}

static bool compute_size(solver_t *solver)
{
    uint64_t length = strlen(solver->map);
    uint64_t current_width = 0;
    bool first_line = true;

    for (uint64_t i = 0; i < length; i++) {
        if (!compute_size_internal(solver, solver->map[i], &first_line,
            &current_width))
            return false;
    }
    if (current_width != solver->width)
        return false;
    solver->height++;
    return true;
}

static bool solver_create2(solver_t *solver)
{
    solver->cells = calloc(solver->width * solver->height, sizeof(cell_t));
    solver->queue = queue_create();
    return solver->cells && solver->queue;
}

solver_t *solver_create(char *path)
{
    solver_t *solver = calloc(1, sizeof(solver_t));

    if (solver == NULL)
        return NULL;
    solver->map = read_file(path);
    if (!solver->map) {
        solver_destroy(solver);
        return NULL;
    }
    if (!compute_size(solver)) {
        solver_destroy(solver);
        return NULL;
    }
    if (!solver_create2(solver)) {
        solver_destroy(solver);
        return NULL;
    }
    return solver;
}
