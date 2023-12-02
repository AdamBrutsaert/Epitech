/*
** EPITECH PROJECT, 2023
** entity_render_hitboxes.c
** File description:
** entity_render_hitboxes.c
*/

#include "engine/entity_impl.h"

void entity_render_hitboxes(entity_t *entity)
{
    sfRectangleShape *shape = sfRectangleShape_create();

    if (shape == NULL)
        return;
    sfRectangleShape_setFillColor(shape, HITBOX_COLOR);
    for (size_t i = 0; i < entity->hitboxes_length; i++) {
        sfRectangleShape_setPosition(shape, (sfVector2f){
            entity->hitboxes[i].hitbox.left,
            entity->hitboxes[i].hitbox.top
        });
        sfRectangleShape_setSize(shape, (sfVector2f) {
            entity->hitboxes[i].hitbox.width,
            entity->hitboxes[i].hitbox.height
        });
        sfRenderWindow_drawRectangleShape(entity_get_window(entity), shape,
            NULL);
    }
    sfRectangleShape_destroy(shape);
}
