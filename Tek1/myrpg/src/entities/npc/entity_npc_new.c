/*
** EPITECH PROJECT, 2023
** entity_npc_new.c
** File description:
** entity_npc_new.c
*/

#include "entities/npc_impl.h"

entity_t *entity_npc_new(entity_t *player, const char *string, sfVector2f pos)
{
    entity_t *entity = entity_new(sizeof(entity_npc_t));
    entity_npc_t *npc;

    if (entity == NULL)
        return NULL;
    npc = entity_get_data(entity);
    npc->player_entity = player;
    npc->string = string;
    npc->position = pos;
    entity_bind_on_attach(entity, entity_npc_on_attach);
    entity_bind_on_detach(entity, entity_npc_on_detach);
    entity_bind_on_event(entity, entity_npc_on_event);
    entity_bind_on_update(entity, entity_npc_on_update);
    entity_bind_on_render(entity, entity_npc_on_render);
    return entity;
}
