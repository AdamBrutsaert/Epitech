/*
** EPITECH PROJECT, 2023
** player_has_all.c
** File description:
** player_has_all.c
*/

#include "entities/player_impl.h"
#include "save.h"

bool player_has_all(entity_t *entity)
{
    return STATE.has_blue_pot && STATE.has_red_pot;
}
