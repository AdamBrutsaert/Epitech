/*
** EPITECH PROJECT, 2023
** entity_fireball_new.c
** File description:
** entity_fireball_new.c
*/

#include "entities/fireball_impl.h"

entity_t *entity_fireball_new(entity_t *player)
{
    entity_t *entity = entity_new(sizeof(entity_fireball_t));
    entity_fireball_t *data;

    if (entity == NULL)
        return NULL;
    data = entity_get_data(entity);
    data->player = player;
    entity_bind_on_attach(entity, entity_fireball_on_attach);
    entity_bind_on_detach(entity, entity_fireball_on_detach);
    entity_bind_on_event(entity, entity_fireball_on_event);
    entity_bind_on_update(entity, entity_fireball_on_update);
    entity_bind_on_render(entity, entity_fireball_on_render);
    return entity;
}
