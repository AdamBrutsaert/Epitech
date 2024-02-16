/*
** EPITECH PROJECT, 2023
** entity_skeleton_on_render.c
** File description:
** entity_skeleton_on_render.c
*/

#include "entities/skeleton_impl.h"

void entity_skeleton_on_render(entity_t *entity)
{
    entity_skeleton_t *skeleton = entity_get_data(entity);
    sfRenderWindow *window = entity_get_window(entity);

    sfRenderWindow_drawSprite(window, skeleton->sprite, NULL);
}
