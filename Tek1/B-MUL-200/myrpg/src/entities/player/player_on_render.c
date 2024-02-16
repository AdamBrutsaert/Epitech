/*
** EPITECH PROJECT, 2023
** player_on_render.c
** File description:
** player_on_render.c
*/

#include "entities/player_impl.h"

void player_on_render(entity_t *entity)
{
    player_t *player = entity_get_data(entity);
    sfRenderWindow *window = entity_get_window(entity);

    sfRenderWindow_drawSprite(window, player->sprite, NULL);
    sfRenderWindow_drawSprite(window, player->weapon, NULL);
}
