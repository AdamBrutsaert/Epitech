/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** skeleton_dying
*/

#include "entities/skeleton_impl.h"

void skeleton_kill(entity_t *entity)
{
    entity_skeleton_t *skeleton = entity_get_data(entity);

    skeleton->state = DYING;
    sfSprite_setTexture(skeleton->sprite, skeleton->dying_texture, sfTrue);
    sfSprite_setTextureRect(skeleton->sprite, (sfIntRect){0, 0, 16, 16});
    sfSound_play(skeleton->death_sound);
    entity_remove_hitbox(entity, 0);
}
