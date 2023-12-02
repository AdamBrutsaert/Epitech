/*
** EPITECH PROJECT, 2023
** entity_skeleton_on_detach.c
** File description:
** entity_skeleton_on_detach.c
*/

#include "entities/skeleton_impl.h"

void entity_skeleton_on_detach(entity_t *entity)
{
    entity_skeleton_t *skeleton = entity_get_data(entity);

    animation_delete(skeleton->idle_animation);
    animation_delete(skeleton->walk_animation);
    animation_delete(skeleton->death_animation);
    sfTexture_destroy(skeleton->texture);
    sfTexture_destroy(skeleton->dying_texture);
    sfSprite_destroy(skeleton->sprite);
    sfSound_destroy(skeleton->death_sound);
    sfSoundBuffer_destroy(skeleton->death_sound_buffer);
}
