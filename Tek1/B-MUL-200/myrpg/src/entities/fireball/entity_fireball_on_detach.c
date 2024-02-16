/*
** EPITECH PROJECT, 2023
** entity_fireball_on_detach.c
** File description:
** entity_fireball_on_detach.c
*/

#include "entities/fireball_impl.h"

void entity_fireball_on_detach(entity_t *entity)
{
    entity_fireball_t *fireball = entity_get_data(entity);

    sfTexture_destroy(fireball->texture);
    sfSprite_destroy(fireball->sprite);
    animation_delete(fireball->animation);
    animation_delete(fireball->destroying);
    sfSound_destroy(fireball->sound);
    sfSoundBuffer_destroy(fireball->sound_buffer);
    sfSound_destroy(fireball->boom);
    sfSoundBuffer_destroy(fireball->boom_buffer);
}
