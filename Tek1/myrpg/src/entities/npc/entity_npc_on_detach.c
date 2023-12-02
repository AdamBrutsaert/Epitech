/*
** EPITECH PROJECT, 2023
** entity_npc_on_detach.c
** File description:
** entity_npc_on_detach.c
*/

#include "entities/npc_impl.h"

void entity_npc_on_detach(entity_t *entity)
{
    entity_npc_t *npc = entity_get_data(entity);

    sfTexture_destroy(npc->texture);
    sfSprite_destroy(npc->sprite);
    sfFont_destroy(npc->font);
    sfText_destroy(npc->text);
    sfSound_destroy(npc->sound);
    sfSoundBuffer_destroy(npc->sound_buffer);
}
