/*
** EPITECH PROJECT, 2023
** player_new.c
** File description:
** player_new.c
*/

#include "entities/player_impl.h"

entity_t *player_new(void)
{
    entity_t *entity = entity_new(sizeof(player_t));

    if (entity == NULL)
        return NULL;
    entity_bind_on_attach(entity, player_on_attach);
    entity_bind_on_detach(entity, player_on_detach);
    entity_bind_on_event(entity, player_on_event);
    entity_bind_on_update(entity, player_on_update);
    entity_bind_on_render(entity, player_on_render);
    return entity;
}
