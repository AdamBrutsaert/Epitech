/*
** EPITECH PROJECT, 2023
** entity_fireball_on_render.c
** File description:
** entity_fireball_on_render.c
*/

#include "entities/fireball_impl.h"

void entity_fireball_on_render(entity_t *entity)
{
    entity_fireball_t *fireball = entity_get_data(entity);
    sfRenderWindow *window = entity_get_window(entity);

    sfRenderWindow_drawSprite(window, fireball->sprite, NULL);
}
