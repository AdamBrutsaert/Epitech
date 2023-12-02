/*
** EPITECH PROJECT, 2023
** entity_skeleton_on_attach.c
** File description:
** entity_skeleton_on_attach.c
*/

#include "entities/skeleton_impl.h"

static bool create_sound(entity_skeleton_t *skeleton)
{
    skeleton->death_sound_buffer = sfSoundBuffer_createFromFile(
        "res/sounds/ennemie_killed.ogg");
    if (skeleton->death_sound_buffer == NULL)
        return false;
    skeleton->death_sound = sfSound_create();
    if (skeleton->death_sound == NULL)
        return false;
    sfSound_setBuffer(skeleton->death_sound, skeleton->death_sound_buffer);
    sfSound_setVolume(skeleton->death_sound, 25);
    return true;
}

static bool create_textures(entity_skeleton_t *skeleton)
{
    skeleton->texture = sfTexture_createFromFile("res/skeleton.png", NULL);
    skeleton->dying_texture = sfTexture_createFromFile("res/skeleton_dying.png",
        NULL);
    return skeleton->texture && skeleton->dying_texture;
}

static bool set_hitbox(entity_t *entity, entity_skeleton_t *skeleton)
{
    sfVector2f position = sfSprite_getPosition(skeleton->sprite);

    return entity_add_hitbox(entity, (sfFloatRect) {
        position.x,
        position.y,
        14,
        15
    }) != -1;
}

bool entity_skeleton_on_attach(entity_t *entity)
{
    entity_skeleton_t *skeleton = entity_get_data(entity);

    skeleton->sprite = sfSprite_create();
    if (skeleton->sprite == NULL || !create_textures(skeleton) ||
        !skeleton_create_animations(entity))
        return false;
    sfSprite_setTexture(skeleton->sprite, skeleton->texture, sfTrue);
    sfSprite_setPosition(skeleton->sprite, skeleton->pos);
    skeleton->cooldown = 0;
    return set_hitbox(entity, skeleton) && create_sound(skeleton);
}
