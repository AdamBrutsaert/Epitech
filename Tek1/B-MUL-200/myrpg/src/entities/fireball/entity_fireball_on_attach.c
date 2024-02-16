/*
** EPITECH PROJECT, 2023
** entity_fireball_on_attach.c
** File description:
** entity_fireball_on_attach.c
*/

#include "entities/fireball_impl.h"

static bool create_sound(entity_fireball_t *fireball)
{
    fireball->sound_buffer = sfSoundBuffer_createFromFile(
        "res/sounds/fireball.ogg");
    if (fireball->sound_buffer == NULL)
        return false;
    fireball->sound = sfSound_create();
    if (fireball->sound == NULL)
        return false;
    sfSound_setBuffer(fireball->sound, fireball->sound_buffer);
    sfSound_play(fireball->sound);
    sfSound_setVolume(fireball->sound, 25);
    return true;
}

static bool create_boom(entity_fireball_t *fireball)
{
    fireball->boom_buffer = sfSoundBuffer_createFromFile(
        "res/sounds/boom.ogg");
    if (fireball->boom_buffer == NULL)
        return false;
    fireball->boom = sfSound_create();
    if (fireball->boom == NULL)
        return false;
    sfSound_setBuffer(fireball->boom, fireball->boom_buffer);
    sfSound_setVolume(fireball->boom, 10);
    return true;
}

static bool set_hitbox(entity_t *entity)
{
    entity_fireball_t *fireball = entity_get_data(entity);
    sfFloatRect hitbox = sfSprite_getGlobalBounds(fireball->sprite);

    hitbox.left += 2;
    hitbox.top += 2;
    hitbox.width -= 4;
    hitbox.height -= 4;
    return entity_add_hitbox(entity, hitbox) != -1;
}

static bool add_animation(entity_t *entity)
{
    entity_fireball_t *fireball = entity_get_data(entity);

    fireball->animation = animation_new();
    fireball->destroying = animation_new();
    if (fireball->animation == NULL || fireball->destroying == NULL)
        return false;
    for (size_t i = 0; i < 5; i++) {
        if (!animation_add_frame(fireball->animation,
            (sfIntRect){i * 16, 0, 16, 16}))
            return false;
    }
    for (size_t i = 0; i < 3; i++) {
        if (!animation_add_frame(fireball->destroying,
            (sfIntRect){80 + i * 16, 0, 16, 16}))
            return false;
    }
    animation_set_speed(fireball->animation, 10.0f);
    animation_set_speed(fireball->destroying, 5.0f);
    animation_set_repeat(fireball->destroying, false);
    return true;
}

bool entity_fireball_on_attach(entity_t *entity)
{
    entity_fireball_t *fireball = entity_get_data(entity);

    fireball->texture = sfTexture_createFromFile("res/fireball.png", NULL);
    fireball->sprite = sfSprite_create();
    if (fireball->texture == NULL || fireball->sprite == NULL)
        return false;
    sfSprite_setTexture(fireball->sprite, fireball->texture, sfFalse);
    sfSprite_setTextureRect(fireball->sprite, (sfIntRect){0,0,16,16});
    sfSprite_setOrigin(fireball->sprite, (sfVector2f){8,8});
    entity_set_type(entity, "Fireball");
    return set_hitbox(entity) && create_sound(fireball)
        && add_animation(entity) && create_boom(fireball);
}
