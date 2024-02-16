/*
** EPITECH PROJECT, 2023
** ant_delete.c
** File description:
** ant_delete.c
*/

#include "lem_in/ant_impl.h"

#include <stdlib.h>

void ant_delete(ant_t *ant)
{
    free(ant);
}
