/*
** EPITECH PROJECT, 2023
** path_advance.c
** File description:
** path_advance.c
*/

#include "lem_in/path_impl.h"
#include "my/memory.h"
#include "my/stdio.h"

#include <stdlib.h>

static bool path_advance_ant(path_t *path, ant_t *ant)
{
    size_t step = ant_get_step(ant);

    if (step == path->length - 1)
        return false;
    ant_set_step(ant, step + 1);
    ant_print(ant, path->rooms[step + 1]);
    return true;
}

static bool grow(path_t *path)
{
    size_t capacity = path->ant_capacity * 2 + !path->ant_capacity;
    ant_t **ants = malloc(sizeof(ant_t *) * capacity);

    if (ants == NULL)
        return false;
    my_memcpy(ants, path->ants, sizeof(ant_t *) * path->ant_length);
    free(path->ants);
    path->ants = ants;
    path->ant_capacity = capacity;
    return true;
}

static bool add_new_ant(path_t *path, bool *print_space)
{
    ant_t *ant = ant_new();

    if (ant == NULL)
        return false;
    if (path->ant_length == path->ant_capacity && !grow(path)) {
        ant_delete(ant);
        return false;
    }
    ant_set_step(ant, 0);
    if (*print_space)
        my_putc(' ');
    ant_print(ant, path->rooms[0]);
    *print_space = true;
    path->ants[path->ant_length] = ant;
    path->ant_length++;
    path->ant_count--;
    return true;
}

static bool is_finished(path_t *path)
{
    for (size_t i = 0; i < path->ant_length; i++)
        if (ant_get_step(path->ants[i]) != path->length - 1)
            return false;
    return path->ant_count == 0;
}

bool path_advance(path_t *path, bool *print_space)
{
    if (is_finished(path))
        return true;
    if (*print_space) {
        my_putc(' ');
        *print_space = false;
    }
    for (size_t i = 0; i < path->ant_length; i++) {
        if (*print_space == true)
            my_putc(' ');
        *print_space = path_advance_ant(path, path->ants[i]);
    }
    while (path->length == 1 && path->ant_count != 0) {
        if (!add_new_ant(path, print_space))
            return false;
    }
    if (path->ant_count != 0 && !add_new_ant(path, print_space))
        return false;
    return is_finished(path);
}
