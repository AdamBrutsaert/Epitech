/*
** EPITECH PROJECT, 2023
** ant_new.c
** File description:
** ant_new.c
*/

#include "lem_in/ant_impl.h"

#include <stdlib.h>

ant_t *ant_new(void)
{
    static size_t id = 1;
    ant_t *ant = malloc(sizeof(ant_t));

    if (ant == NULL)
        return NULL;
    ant->id = id;
    id++;
    return ant;
}
