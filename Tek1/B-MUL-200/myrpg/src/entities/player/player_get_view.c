/*
** EPITECH PROJECT, 2023
** player_get_view.c
** File description:
** player_get_view.c
*/

#include "entities/player_impl.h"

sfView *player_get_view(entity_t *entity)
{
    player_t *player = entity_get_data(entity);

    return camera_get_view(player->camera);
}
