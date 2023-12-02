/*
** EPITECH PROJECT, 2023
** entity_map_on_render.c
** File description:
** entity_map_on_render.c
*/

#include "entities/map_impl.h"

void entity_map_on_render(entity_t *entity)
{
    entity_map_t *data = entity_get_data(entity);
    sfRenderWindow *window = entity_get_window(entity);

    sfRenderWindow_drawSprite(window, data->sprite, NULL);
}
