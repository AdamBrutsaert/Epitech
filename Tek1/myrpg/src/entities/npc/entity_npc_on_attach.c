/*
** EPITECH PROJECT, 2023
** entity_npc_on_attach.c
** File description:
** entity_npc_on_attach.c
*/

#include "entities/npc_impl.h"

static bool create_sound(entity_t *entity, entity_npc_t *npc)
{
    npc->sound_buffer = sfSoundBuffer_createFromFile(RES("sounds/npc.ogg"));
    if (npc->sound_buffer == NULL)
        return false;
    npc->sound = sfSound_create();
    if (npc->sound == NULL)
        return false;
    sfSound_setBuffer(npc->sound, npc->sound_buffer);
    return true;
}

static bool load_texture(entity_t *entity, entity_npc_t *npc)
{
    npc->texture = sfTexture_createFromFile(RES("npc.png"), NULL);
    if (npc->texture == NULL)
        return false;
    npc->sprite = sfSprite_create();
    if (npc->sprite == NULL)
        return false;
    sfSprite_setTexture(npc->sprite, npc->texture, sfTrue);
    sfSprite_setPosition(npc->sprite, npc->position);
    return true;
}

static bool load_text(entity_t *entity, entity_npc_t *npc)
{
    sfFloatRect rect;

    npc->font = sfFont_createFromFile(RES("font/dogica.ttf"));
    if (npc->font == NULL)
        return false;
    npc->text = sfText_create();
    if (npc->text == NULL)
        return false;
    sfText_setFont(npc->text, npc->font);
    sfText_setCharacterSize(npc->text, 7);
    sfText_setString(npc->text, npc->string);
    rect = sfText_getGlobalBounds(npc->text);
    sfText_setPosition(npc->text, (sfVector2f){npc->position.x - rect.width / 2
        + 25, npc->position.y - 20});
    return true;
}

bool entity_npc_on_attach(entity_t *entity)
{
    entity_npc_t *npc = entity_get_data(entity);

    if (npc == NULL || !load_texture(entity, npc)
        || !npc_create_animations(entity) || !load_text(entity, npc))
        return false;
    entity_add_hitbox(entity, (sfFloatRect){npc->position.x,
        npc->position.y + 3, 16, 17});
    return create_sound(entity, npc);
}
