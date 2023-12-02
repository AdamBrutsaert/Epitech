/*
** EPITECH PROJECT, 2023
** lem_in_advance.c
** File description:
** lem_in_advance.c
*/

#include "lem_in_impl.h"
#include "my/stdio.h"

static bool lem_in_advance_one_step(lem_in_t *lem_in)
{
    bool finished = true;
    bool print_space = false;

    for (size_t i = 0; i < lem_in->length; i++) {
        if (!path_advance(lem_in->paths[i], &print_space))
            finished = false;
    }
    return finished;
}

void lem_in_advance(lem_in_t *lem_in)
{
    my_puts("#moves\n");
    while (!lem_in_advance_one_step(lem_in))
        my_putc('\n');
    my_putc('\n');
}
