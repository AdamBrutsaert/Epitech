/*
** EPITECH PROJECT, 2023
** anthill_is_valid.c
** File description:
** anthill_is_valid.c
*/

#include "lem_in/anthill_impl.h"

bool anthill_is_valid(anthill_t *anthill)
{
    return anthill->start != NULL
        && anthill->end != NULL
        && anthill->ant_count != 0;
}
